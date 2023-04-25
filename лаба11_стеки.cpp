#include <iostream>
#include <fstream>
using namespace std;
struct Node // ��������� ���� �����
{
    int key; // �������� ����
    Node* next; // ��������� �� ��������� �������
};
void createStack(Node*& top) // �������� ������� �����
{
    top = NULL;
}
void push(Node*& top, int key) // ���������� �������� � ����
{
    Node* p = new Node; // ������� ����� �������
    p->key = key; // ����������� ��� �������� �����
    p->next = top; // ����� ������� ���������� ������
    top = p; // ������� ����� ��������� �� ����� �������
}
void pop(Node*& top) // �������� �������� �������� �� �����
{
    if (top == NULL) // ���� ���� ������
    {
        cout << "���� ������." << endl;
        return;
    }
    Node* p = top; // ��������� ������� �����
    top = top->next; // ������� ����� ��������� �� ��������� �������
    delete p; // ������� ����������� �������
}
void printStack(Node* top) // ������ �����
{
    if (top == NULL) // ���� ���� ������
    {
        cout << "���� ������." << endl;
        return;
    }
    while (top != NULL) // ���� �� ��������� ����� �����
    {
        cout << top->key << " "; // �������� �������� �����
        top = top->next; // ��������� � ���������� ��������
    }
    cout << endl;
}
void writeStackToFile(Node* top, string fileName) // ������ ����� � ����
{
    ofstream file(fileName); // ������� ���� ��� ������
    if (file.is_open()) // ���� ���� ������
    {
        while (top != NULL) // ���� �� ��������� ����� �����
        {
            file << top->key << " "; // ���������� �������� �����
            top = top->next; // ��������� � ���������� ��������
        }
        file.close(); // ��������� ����
    }
    else // ���� ���� �� ������
    {
        cout << "������ �������� �����." << endl;
    }
}
void destroyStack(Node*& top) // ����������� �����
{
    while (top != NULL) // ���� �� ��������� ����� �����
    {
        Node* p = top; // ��������� ������� �����
        top = top->next; // ������� ����� ��������� �� ��������� �������
        delete p; // ������� ����������� �������
    }
}
void restoreStackFromFile(Node*& top, string fileName) // �������������� ����� �� �����
{
    destroyStack(top); // ���������� ������������ ����
    ifstream file(fileName); // ��������� ���� ��� ������
    if (file.is_open()) // ���� ���� ������
    {
        int key;
        while (file >> key) // ���� �� ��������� ����� �����
        {
            push(top, key); // ��������� ������� � ����
        }
        file.close(); // ��������� ����
    }
    else // ���� ���� �� ������
    {
        cout << "������ �������� �����." << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian"); // ���������� ������� ����
    Node* top; // ��������� �� ������� �����
    int n, k;
    createStack(top); // ������� ������ ����
    cout << "������� ���������� ��������� � �����: ";
    cin >> n;
    for (int i = 0; i < n; i++) // ��������� ����
    {
        int key;
        cout << "������� �������� ���� �������� " << i + 1 << ": ";
        cin >> key;
        push(top, key); // ��������� ������� � ����
    }
    cout << "����: ";
    printStack(top); // �������� ����
    cout << "������� ����� ��������, ������� ����� ��������: ";
    cin >> k;
    push(top, k); // ��������� ������� � �������� �������
    cout << "���� ����� ���������� ��������: ";
    printStack(top); // �������� ����
    cout << "������� ���������� ���������, ������� ����� �������: ";
    cin >> k;
    for (int i = 0; i < k; i++) // ������� �������� �� ����� �����
    {
        pop(top);
    }
    cout << "���� ����� �������� ���������: ";
    printStack(top); // �������� ����
    writeStackToFile(top, "stack.txt"); // ���������� ���� � ����
    destroyStack(top); // ���������� ����
    restoreStackFromFile(top, "stack.txt"); // ��������������� ���� �� �����
    cout << "���� ����� �������������� �� �����: ";
    printStack(top); // �������� ����
    destroyStack(top); // ���������� ����
    return 0;
}