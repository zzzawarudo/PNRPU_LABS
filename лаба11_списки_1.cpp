#include <iostream>
#include <fstream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void createList(Node*& head, int n) {
    head = NULL;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        cout << "������� ������� " << i + 1 << ": ";
        cin >> newNode->data;
        newNode->next = head;
        head = newNode;
    }
    cout << "������ ������� ������!" << endl;
}
void addNode(Node*& head, int key) {
    Node* newNode = new Node;
    cout << "������� ����� �������: ";
    cin >> newNode->data;
    if (head == NULL) {
        newNode->next = NULL;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != NULL && current->data != key) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    cout << "������� ������� ��������!" << endl;
}
void pop(Node*& head, int k) {
    for (int i = 0; i < k; i++) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
void printList(Node* head) {
    cout << "���������� ������: ";
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void writeListToFile(Node* head, string fileName) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        Node* current = head;
        while (current != NULL) {
            outFile << current->data << " ";
            current = current->next;
        }
        cout << "������ ������� ������� � ����!" << endl;
    }
    else {
        cout << "������ �������� �����" << endl;
    }
    outFile.close();
}
void destroyList(Node*& head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
    cout << "������ ������� ������!" << endl;
}
void readListFromFile(Node*& head, string fileName) {
    ifstream inFile(fileName);
    if (inFile.is_open()) {
        destroyList(head);
        int data;
        while (inFile >> data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
        }
        cout << "������ ������� �������� �� �����!" << endl;
    }
    else {
        cout << "������ �������� �����" << endl;
    }
    inFile.close();
}
int main() {
    setlocale(0, "RUS");
    Node* head = NULL;
    int n, key, k;
    string fileName;
    cout << "������� ���������� ��������� ������: ";
    cin >> n;
    createList(head, n);
    printList(head);
    cout << "������� ���� ��� ���������� �������� �����: ";
    cin >> key;
    addNode(head, key);
    printList(head);
    cout << "������� ���������� ���������, ������� �������� � �����: ";
    cin >> k;
    pop(head, k);
    printList(head);
    cout << "������� ��� ����� ��� ������ ������: ";
    cin >> fileName;
    writeListToFile(head, fileName);
    destroyList(head);
    cout << "������� ��� ����� ��� ������ ������: ";
    cin >> fileName;
    readListFromFile(head, fileName);
    printList(head);
    return 0;
}