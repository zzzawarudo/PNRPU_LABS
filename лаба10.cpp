#include <iostream>
#include <ctime>
using namespace std;
int main() {
	srand(time(NULL));
	setlocale(0, "");
	int rowdel, coldel, row, col;
	cin >> row;
	cin >> col;
	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[col];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cin >> rowdel;
	cin >> coldel;
	int** newarr = new int* [row - 1];
	int ni = 0;
	for (int i = 0; i < row; i++) {
		if (i != rowdel) {
			newarr[ni] = arr[i];
			ni++;
		}
	}
	delete[] arr[rowdel];
	delete[] arr;
	arr = newarr;
	row--;
	for (int i = 0; i < row; i++) {
		int* newrow = new int[col - 1];
		int nj = 0;
		for (int j = 0; j < col; j++) {
			if (j != coldel) {
				newrow[nj] = arr[i][j];
				nj++;
			}
		}
		delete[] arr[i];
		arr[i] = newrow;
	}
	col--;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}