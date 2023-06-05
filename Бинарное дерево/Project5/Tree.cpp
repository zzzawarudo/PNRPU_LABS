#include <glut.h>
#include "Tree.h"
#include <Windows.h>

using namespace std;

SGlutContextStruct glutContext;

int getPos(int index, int width, int curLevel, int height)
{
	int x1 = 0;
	int x2 = pow(2, curLevel) - 1;
	int y1 = width / pow(2, curLevel + 1);
	int y2 = width - pow(2, height - curLevel);
	if (x1 == x2) return y1;
	double k = (y2 - y1) / (x2 - x1);
	double m = -x1 * k + y1;
	int y = (int)(k * index + m);
	return y;

}

template<class T>
void initWindow(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(glutContext.window_width, glutContext.window_height);
	glutCreateWindow("Бинарное дерево");
	glutDisplayFunc(display<T>);
	glutReshapeFunc(reshape);
	glutMainLoop();
}

void reshape(int w, int h);

template <class T>
void display()
{
	btree<T>* tree = ((btree<T>*)glutContext.tree)->CopyTree();
	tree = tree->replaceNULLforEmpty();
	int k = glutContext.k;
	int window_width = glutContext.window_width;
	int window_height = glutContext.window_height;
	int shift = glutContext.shift;
	int height = tree->getHeight();
	int maxLeafs = pow(2, height - 1);
	int width = 2 * maxLeafs - 1;
	int curLevel = 0;
	int index = 0;
	int factSpaces = getPos(index, width, curLevel, height - 1);
	pos node;
	vector<btree<T>*> V;
	vector<pos> Vi;
	int R;
	R = (window_width - 2 * shift) / (2 * width);
	if (2 * R * height > (window_height - 2 * shift)) R = (window_height - 2 * shift) / (2 * height);
	glutContext.R = R;
	tree->setCoordsForNode(window_width, window_height, shift, width, height, factSpaces, curLevel, R);
	V.push_back(tree);
	node.col = factSpaces;
	node.str = curLevel;
	Vi.push_back(node);
	glClearColor(1.5, 1.8, 1.35, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glEnable(GL_POINT_SMOOTH);
	for (int i = 0; i < tree->getAmountOfNodes(); i++) {
		if (pow(2, curLevel) <= index + 1)
		{
			index = 0;
			curLevel++;
		}
		if (V.at(i)->getLeft() != NULL)
		{
			V.push_back(V.at(i)->getLeft());
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
			V.at(i)->getLeft()->setCoordsForNode(window_width, window_height, shift, width, height, factSpaces, curLevel, R);
			if (V.at(i)->getLeft()->getData() != NULL)
			{
				int x1 = V.at(i)->node_x;
				int y1 = V.at(i)->node_y;
				int x2 = V.at(i)->getLeft()->node_x;
				int y2 = V.at(i)->getLeft()->node_y;
				drawLine(x1, y1, x2, y2);
			}
		}
		if (V.at(i)->getRight() != NULL)
		{
			V.push_back(V.at(i)->getRight());
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
			V.at(i)->getRight()->setCoordsForNode(window_width, window_height, shift, width, height, factSpaces, curLevel, R);
			if (V.at(i)->getRight()->getData() != NULL)
			{
				int x1 = V.at(i)->node_x;
				int y1 = V.at(i)->node_y;
				int x2 = V.at(i)->getRight()->node_x;
				int y2 = V.at(i)->getRight()->node_y;
				drawLine(x1, y1, x2, y2);
			}
		}
		if (V.at(i)->getData() != NULL)
		{
			if (glutContext.state == 0)
			{
				drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
			}
			else
			{
				drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
				if ((tree->getNodeByCoords(glutContext.x, glutContext.y, R)->node_x == V.at(i)->node_x)
					& (tree->getNodeByCoords(glutContext.x, glutContext.y, R)->node_y == V.at(i)->node_y))
					drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
			}
			V.at(i)->setCoordsForText(k, R);
			drawText(V.at(i)->getData(), GLUT_STROKE_ROMAN, V.at(i)->text_x, V.at(i)->text_y, R, k);
		}
	}
	glutSwapBuffers();
	glDisable(GL_POINT_SMOOTH);
}


int main(int argc, char** argv)
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	btree<double>* root = new btree<double>;

	int size = 5 + rand() % 3;

	cout << "SIZE: " << size << endl;

	root = root->make_tree(size);

	double max = root->getData();

	root->findMax(max);

	cout << "Max element is: " << max << endl;

	cout << endl;

	root->print_tree(1);

	cout << endl << endl;
	double del;
	cout << "Delete element: ";
	cin >> del;
	cout << endl;

	root = root->delete_elem(del);

	root->print_tree(1);

	cout << endl;

	vector<double> vect;

	root->fill_vector_data(vect);

	btree<double>* search_root = new btree<double>();

	search_root->make_search_tree(vect);

	search_root->print_tree(1);

	cout << endl;
	cout << "Insert element: ";
	cin >> del;

	search_root->insert(del);

	search_root->print_tree(1);

	search_root->drawTree(argc, argv, 800, 600, 10, 2);

	return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLsizei)w, 0, (GLsizei)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutContext.window_width = w;
	glutContext.window_height = h;
	glutPostRedisplay();
}

