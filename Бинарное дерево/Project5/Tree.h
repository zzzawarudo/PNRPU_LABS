#pragma once
#include <iostream>
#include <glut.h>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace std;

struct SGlutContextStruct
{
	void* tree;
	int window_width, window_height, shift, k, R, x, y, state;
};

bool myfunction(const double& i, const double& j) { return (i > j); }

template <class T>
class btree
{
public:
	T key_value;
	btree* left;
	btree* right;
	btree* root;

	int node_x;
	int node_y;
	int text_x;
	int text_y;

	btree(T);
	btree();
	~btree();

	void insert(T key);
	void insertLeft(int key);
	void insertRight(int key);
	btree<T>* search(T key, btree<T>* leaf);

	btree<T>* findElement(T);

	void findMax(double& max_elem);

	void Add_Left_Tree(btree<T>* node)
	{
		left = node;
	}
	void Add_Right_Tree(btree<T>* node)
	{
		right = node;
	}

	btree<T>* delete_elem(double& data);

	void fill_vector_data(vector<double>& vect);

	void make_search_tree(vector<double>& vect);

	btree<T>* make_tree(int counter);

	btree<T>* search(T key);

	void setCoordsForNode(int window_width, int window_height, int shift,
		int tree_width, int tree_height, int x, int y, int R);
	btree<T>* getNodeByCoords(int x, int y, int R);
	void setCoordsForText(int k, int shift);


	void drawTree(
		int argc, char** argv,
		int window_width, int window_height,
		int shift, int k);

	int getHeight();

	btree<T>* CopyTree();

	btree<T>* replaceNULLforEmpty();

	btree<T>* getLeft()
	{
		return left;
	}
	btree<T>* getRight()
	{
		return right;
	}
	btree<T>* getRoot()
	{
		return root;
	}

	int getData()
	{
		return key_value;
	}

	void make_search(vector<double> vect);

	void print_tree(int level);

	int getAmountOfNodes();

};



template<class T>
void initWindow(int argc, char** argv);

template <class T>
void display();

void reshape(int w, int h);

int getPos(int index, int width, int curLevel, int maxLevel);

extern SGlutContextStruct glutContext;

struct  pos
{
	int col;
	int str;
};

template <class T>
void btree<T>::print_tree(int level)
{
	if (this != nullptr)
	{
		this->left->print_tree(level + 1);
		for (int i = 1; i < level; i++) cout << "    ";
		cout << this->key_value << endl;
		this->right->print_tree(level + 1);
	}
}

template <class T>
void btree<T>::fill_vector_data(vector<double>& vect)
{
	if (this != nullptr)
	{
		vect.push_back(this->key_value);
		this->left->fill_vector_data(vect);
		this->right->fill_vector_data(vect);
	}
}

template <class T>
void btree<T>::make_search_tree(vector<double>& vect)
{
	vector<double> v = vect;
	sort(v.begin(), v.end(), myfunction);
	int mid = v.size() / 2;
	this->key_value = v[mid];
	for (int i = 0; i < (int)vect.size(); i++)
	{
		if (vect[i] != v[mid])
		{
			this->insert(vect[i]);
		}
	}
}


template <class T>
btree<T>* btree<T>::make_tree(int counter)
{
	if (counter <= 0)
	{
		return nullptr;
	}
	double data = rand() % 50 + 1;
	btree* temp = new btree<T>(data);
	temp->Add_Left_Tree(make_tree(counter / 2));
	temp->Add_Right_Tree(make_tree(counter - counter / 2 - 1));
	return temp;
}

template <class T>
btree<T>* btree<T>::replaceNULLforEmpty()
{
	btree<T>* node = this->CopyTree();
	int h = node->getHeight();
	node = replace_help(node, h);
	return node;
}

template<class T>
btree<T>::btree(T key)
{
	this->key_value = key;
	left = nullptr;
	right = nullptr;
	root = nullptr;
}

template<class T>
btree<T>::btree()
{

}

template<class T>
btree<T>::~btree()
{

}

template <class T>
btree<T>* btree<T>::findElement(T key)
{
	if ((this == NULL) || (key == this->key_value))
		return this;
	if (key < this->key_value) return this->left->findElement(key);
	else return this->right->findElement(key);
}

template <class T>
void btree<T>::insert(T key)
{
	if (key < -128 || key > 127)
	{
		cout << "Out of range" << endl;
		return;
	}
	btree<T>* tree = this;
	btree<T>* search = findElement(key);
	while (tree != NULL)
	{
		if (key >= tree->key_value)
		{
			if (tree->right != NULL)
			{
				tree = tree->right;
			}
			else
			{
				btree<T>* t = new btree<T>(key);
				t->root = tree;
				tree->right = t;
				break;
			}
		}
		else if (key < tree->key_value)
		{
			if (tree->left != NULL)
			{
				tree = tree->left;
			}
			else
			{
				btree<T>* t = new btree<T>(key);
				t->root = tree;
				tree->left = t;
				break;
			}
		}
	}
}

template <class T>
void btree<T>::insertLeft(int key)
{
	btree<T>* node = new btree<T>();
	if (this->left != NULL)
		this->left->root = node;
	node->left = this->left;
	this->left = node;
	node->root = this;
}

template<class T>
void btree<T>::insertRight(int key)
{
	btree<T>* node = new btree<T>();
	if (this->right != NULL)
		this->right->root = node;
	node->right = this->right;
	this->right = node;
	node->root = this;
}

template <class T>
void btree<T>::make_search(vector<double> vect)
{
	if (this != nullptr)
	{
		sort(vect.begin(), vect.end(), myfunction);
		this->left->make_search(vect);
		this->key_value = vect[vect.size() - 1];
		vect.pop_back();
		this->right->make_search(vect);
	}
}

template <class T>
void btree<T>::findMax(double& max_elem)
{
	if (this == nullptr)
	{
		return;
	}
	if (this->key_value > max_elem)
	{
		max_elem = this->key_value;
	}
	this->left->findMax(max_elem);
	this->right->findMax(max_elem);
}


template <class T>
btree<T>* btree<T>::delete_elem(double& data)
{
	if (this == nullptr)
	{
		return this;
	}
	this->left = this->left->delete_elem(data);
	if (data == this->key_value && data != -1)
	{
		data = -1;
		btree<T>* tmp;
		if (this->right == nullptr)
		{
			tmp = this->left;
		}
		else
		{
			btree<T>* ptr = this->right;
			if (ptr->left == nullptr)
			{
				ptr->left = this->left;
				tmp = ptr;
			}
			else
			{
				btree<T>* pmin = ptr->left;
				while (pmin->left != nullptr)
				{
					ptr = pmin;
					pmin = ptr->left;
				}
				ptr->left = pmin->right;
				pmin->left = this->left;
				pmin->right = this->right;
				tmp = pmin;
			}
		}
		delete this;
		return tmp;
	}
	this->right = this->right->delete_elem(data);
	return this;
}

void drawLine(int x1, int y1)
{
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(x1, y1);
	glEnd();
}

void drawLine(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

void drawFillCircle(int x, int y, int R)
{
	glColor3f(0.9, 0.7, 0.2);
	float x1, y1;
	glBegin(GL_POINTS);
	for (int i = 0; i <= R; i++) {
		for (int t = 0; t <= 360; t++) {
			x1 = i * sin(t) + x;
			y1 = i * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (int i = R - 1; i <= R; i++) {
		for (int t = 0; t <= 360; t++) {
			x1 = R * sin(t) + x;
			y1 = R * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
}

void drawText(char text, void* font, int text_x, int text_y, int R, int k)
{
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(text_x, text_y, 0.0);
	string s = to_string(text);
	char* s1 = new char[s.size() + 1];
	for (int i = 0; i < (int)s.size(); i++) {
		s1[i] = s.at(i);
	}
	s1[s.size()] = 0;
	char* c;
	int max_char_width = 0;
	int char_width = 0;
	for (c = s1; *c != '\0'; c++) {
		char_width = glutStrokeWidth(font, *c);
		if (max_char_width < char_width) max_char_width = char_width;
	}
	float expand_x = (float)1.5 * R / (float)(k * max_char_width);
	float expand_y = (float)1.5 * R / (float)(k * 100);
	glScalef(expand_x, expand_y, 1.0);
	for (c = s1; *c != '\0'; c++)
		glutStrokeCharacter(font, *c);
	glPopMatrix();
}




template<class T>
btree<T>* btree<T>::CopyTree()
{
	btree<T>* tree = new btree<T>(this->key_value);
	if (this->root != NULL)
		tree->root = this->root;
	if (this->left != NULL)
		tree->left = this->left->CopyTree();
	if (this->right != NULL)
		tree->right = this->right->CopyTree();
	return tree;
}

template <class T>
int btree<T>::getHeight()
{
	int h1 = 0, h2 = 0, hadd = 0;
	if (this == NULL)return 0;
	if (this->left != NULL) h1 = this->left->getHeight();
	if (this->right != NULL) h2 = this->right->getHeight();
	if (h1 >= h2) return h1 + 1;
	else return h2 + 1;
}

template<class T>
int btree<T>::getAmountOfNodes()
{
	if (this == NULL)return 0;
	if ((this->left == NULL) && (this->right == NULL)) return 1;
	int l = 0;
	int r = 0;
	if (this->left != NULL) l = this->left->getAmountOfNodes();
	if (this->right != NULL) r = this->right->getAmountOfNodes();
	return (l + r + 1);
}

template<class T>
btree<T>* get_help(btree<T>* node, int x, int y, int R)
{
	if (pow(x - node->node_x, 2) + pow(y - node->node_y, 2) <= pow(R, 2))
		return node;
	btree<T>* temp = NULL;
	if (node->getLeft() != NULL)
		temp = get_help(node->getLeft(), x, y, R);
	if (temp != NULL)
		return temp;
	if (node->getRight() != NULL)
		temp = get_help(node->getRight(), x, y, R);
	return temp;
}

template<class T>
void btree<T>::drawTree(int argc, char** argv, int window_width,
	int window_height, int shift, int k)
{
	btree<T>* temp = this->CopyTree();
	temp = temp->replaceNULLforEmpty();
	glutContext.tree = temp;
	glutContext.window_width = window_width;
	glutContext.window_height = window_height;
	glutContext.shift = shift;
	glutContext.k = k;
	initWindow<T>(argc, argv);
}

template<class T>
btree<T>* btree<T>::getNodeByCoords(int x, int y, int R)
{
	btree<T>* node = this;
	node = get_help(node, x, y, R);
	return node;
}

template <class T>
void btree<T>::setCoordsForText(int k, int R)
{

	text_x = node_x - 3 * R / 4;

	text_y = node_y - 3 * R / (4 * k);
}

template <class T>
void btree<T>::setCoordsForNode(int window_width, int window_height, int shift, int tree_width, int tree_height, int x, int y, int R)
{
	if (tree_width != tree_height)
	{
		int k_x = (window_width - 2 * (shift + R)) / (tree_width - 1);
		int k_y = (window_height - 2 * (shift + R)) / (tree_height - 1);
		node_x = k_x * x + shift + R;
		node_y = window_height - k_y * y - shift - R;
	}
	else
	{
		node_x = window_width / 2;
		node_y = window_height / 2;
	}
}

template <class T>
btree<T>* btree<T>::search(T key)
{
	if (root != NULL)
	{
		if (key == root->key_value)
			return root;
		if (key < root->key_value)

			return search(key, root->left);
		else
			return search(key, root->right);
	}
	else return NULL;
}

template <class T>
btree<T>* btree<T>::search(T key, btree<T>* leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key_value)
			return leaf;
		if (key < leaf->key_value)

			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}

template <class T>
btree<T>* replace_help(btree<T>* node, int h)
{
	int curLevel = getLevel(node);
	if ((node->getLeft() == NULL) && (curLevel != h - 1))
	{
		node->insertLeft(NULL);
	}
	if ((node->getRight() == NULL) && (curLevel != h - 1))
	{
		node->insertRight(NULL);
	}
	if (node->getLeft() != NULL) node->Add_Left_Tree(replace_help(node->getLeft(), h));
	if (node->getRight() != NULL) node->Add_Right_Tree(replace_help(node->getRight(), h));
	return node;
}

template<class T>
int getLevel(btree<T>* node)
{

	if (node->getRoot() == NULL)
	{
		return 0;
	}
	else
	{
		return getLevel(node->getRoot()) + 1;
	}
}