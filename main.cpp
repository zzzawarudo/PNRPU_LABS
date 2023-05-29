#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

struct node {
    char date[256] = "";
    node* next = nullptr;
};

struct hashtab {
    int number = -1;
    node* head = nullptr;
};

struct client {
    char FIO[256] = "";
    char date[256] = "";
    char passport[256] = "";
};

// ������� ��� �������� ���� ������
node* createNode(char* data) {
    node* newNode = new node;
    strncpy(newNode->date, data, 256);
    newNode->next = nullptr;
    return newNode;
}

// ������� ��� ���������� ������� � ����
void SaveArr(client* arr, int n) {
    client* current = new client;
    char FName[] = "array.txt"; //���� � �����
    ofstream f1(FName, ios_base::out | ios_base::binary);   // ��������� ���� ��� ������
    for (int i = 0; i < n; i++) {
        //current.FIO = arr[i].FIO;
        strncpy(current->FIO, arr[i].FIO, 256);
        strncpy(current->date, arr[i].date, 256);
        strncpy(current->passport, arr[i].passport, 256);
        f1.write((char*)current, sizeof(client));   /*���������� ��������� � ����*/
    }
    f1.close();     // ��������� ����
}

// ������� ��� ������ ������� �� �����
void LoadArr(client* arr, int n) {
    client current;
    char FName[] = "array.txt"; //���� � �����
    ifstream f2(FName);  // ��������� ���� ��� ������
    if (!f2) {
        cout << "���� �� ����������\n\n";
        f2.close();
    }
    for (int i = 0; i < n; i++) {
        strncpy(arr[i].FIO, "", 256);
        strncpy(arr[i].date, "", 256);
        strncpy(arr[i].passport, "", 256);

    }
    f2.seekg(0, ios::end);      //������� �������� � ����� �����
    long NumBytes = (long)f2.tellg();  //��������� ���-�� ������ � �����
    float NumStruct = NumBytes / sizeof(client);  //��������� ���-�� �������� � �����
    f2.seekg(0, ios::beg);      //������� � ������ �����
    for (int i = 0; i < NumStruct; i++) {
        f2.read((char*)&current, sizeof(client));  // ������ ��������� �� ����� � ���������� current
        //cout << current2.FIO << " " << current2.account << " " << current2.summa << endl;
        strncpy(arr[i].FIO, current.FIO, 256);
        strncpy(arr[i].date, current.date, 256);
        strncpy(arr[i].passport, current.passport, 256);
        cout << arr[i].FIO << " " << arr[i].date << " " << arr[i].passport << endl;
    }
    f2.close();
}

int get_rnd_number(int max) {
    return rand() % max;
}

string get_rnd_passport() {
    string pass = to_string(rand() % 90 + 10) + to_string(rand() % 90 + 10) + " " + to_string(rand() % 90 + 10) + to_string(rand() % 90 + 10) + to_string(rand() % 90 + 10);
    return pass;
}

string get_rnd_date() {
    string birth = to_string(rand() % 27 + 1) + "." + to_string(rand() % 12 + 1) + "." + to_string(19 + rand() % 2) + to_string(10 + rand() % 13);
    return birth;
}

string get_rnd_fio() {
    string name[10] = { "���������", "�����", "������", "��������", "�������", "�������", "����", "�������", "������", "����" };
    string patronymic[10] = { "�������������", "���������", "����������", "�����������", "����������", "����������", "��������", "����������", "����������", "��������" };
    string surname[10] = { "�����������", "�������", "��������", "���������", "��������", "��������", "������", "��������", "��������", "������" };
    string fio = name[get_rnd_number(9)] + " " + patronymic[get_rnd_number(9)] + " " + surname[get_rnd_number(9)];
    return fio;
}

void makearr_rnd(int n, client* arr) {
    string s1 = "";
    string s2 = "";
    string s3 = "";
    char sarr1[256];
    char sarr2[256];
    char sarr3[256];
    s1 = get_rnd_fio();
    s2 = get_rnd_date();
    s3 = get_rnd_passport();
    strcpy(sarr1, s1.c_str());
    strcpy(sarr2, s2.c_str());
    strcpy(sarr3, s3.c_str());
    for (int i = 0; i < n - 5; i++) {//-5 - ��������� 5 ������ �����, ����� ����, ���� ��������
        s1 = get_rnd_fio();
        s2 = get_rnd_date();
        s3 = get_rnd_passport();
        strcpy(sarr1, s1.c_str());
        strcpy(sarr2, s2.c_str());
        strcpy(sarr3, s3.c_str());
        strncpy(arr[i].FIO, sarr1, 256);
        strncpy(arr[i].date, sarr2, 256);
        strncpy(arr[i].passport, sarr3, 256);
    }
    for (int j = 0; j < n - 5; j++) {
        cout << arr[j].FIO << " " << arr[j].date << " " << arr[j].passport << endl;
    }
    cout << endl;
}

void addEl(client* arr, int n) {
    client input;
    string temp;
    string temp1;
    string temp2;
    string temp3;
    cout << "������� ���: ";
    cin.ignore();
    getline(cin, temp);
    strcpy(input.FIO, temp.c_str());
    cout << "������� ���� ��������: ";
    getline(cin, temp1);
    strcpy(input.date, temp1.c_str());
    cout << "������� � ��������: ";
    getline(cin, temp2);
    strcpy(input.passport, temp2.c_str());
    if (arr == nullptr) {
        cout << "������";
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            temp3 = arr[i].FIO;
            if (temp3 == "") {
                arr[i] = input;
                return;
            }
        }
        cout << "� ������� ��� ����� ��� ����� ������" << endl;
    }
}

int hash_function(string str, int n) {
    unsigned long i = 0;
    for (int j = 0; str[j]; j++) {
        i += str[j];
    }
    return i % n;
}

void hashta(client* arr, int n, hashtab* hashtable) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        hashtable[i].number = -1;
        hashtable[i].head = nullptr;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i].date != "") { //������ ������� �� �����
            int key = hash_function(arr[i].date, n);
            bool found = false;
            if (hashtable[key].number == -1) { //������ ���-������� ��������
                hashtable[key].number = key;
                hashtable[key].head = createNode(arr[i].date);
                found = true;
            }
            else { // ������ ���-������� ��������� - ��� ��������
                cnt++; //������� �������� ++
                node* newNode = createNode(arr[i].date); //��������� ����� ������ � ������ ������
                newNode->next = hashtable[key].head;
                hashtable[key].head = newNode;
                found = true;
            }
        }
    }
    for (int i = 0; i < n; i++) { // ������ ���-�������
        cout << hashtable[i].number;
        if (hashtable[i].head != nullptr) {
            node* current = hashtable[i].head;
            do {
                cout << ' ' << current->date << endl;
                current = current->next;
            } while (current != nullptr);
        }
        else {
            cout << endl;
        }
    }
    cout << endl;
    cout << "������� ��������: " << cnt << endl;
}

void hashFound(hashtab* hashtable, int n, client* arr) {
    string a;
    int k, i;
    bool found = false;
    cout << "������� ���� �������� ��� ������: "; cin.ignore(); getline(cin, a);
    k = hash_function(a, n);
    if (hashtable[k].head != nullptr) { // � ���-������� ���� ������ � ������ k
        node* current = hashtable[k].head;
        do {
            if (current->date == a) {
                found = true;
            }
            current = current->next;
        } while (current != nullptr && !found);
    }
    if (found == 0) {
        cout << "������� �� ������" << endl;
    }
    else {
        cout << "����� ������ � �������: " << k << endl;
        found = FALSE;
        for (i = 0; i < n && !found; i++) {
            if (arr[i].date == a) {
                found = TRUE;
                cout << arr[i].FIO << ' ' << arr[i].date << ' ' << arr[i].passport << endl;
            }
        }
    }
}

void DelEL(client* arr, int n) {
    string data;
    int pos;
    bool found = 0;
    int temp;
    if (arr == nullptr) {
        cout << "������";
        return;
    }
    else {
        cout << "������� ���� �������� ��� ��������: ";
        cin.ignore();
        getline(cin, data);
        pos = hash_function(data, n);
    }
    if (data == arr[pos].date) {
        found = 1;
        strcpy(arr[pos].FIO, "");
        strcpy(arr[pos].date, "");
        strcpy(arr[pos].passport, "");
    }
    else {
        temp = (pos + 1) % n;
        while (temp != pos && !found) {
            if (data == arr[temp].FIO) {
                found = 1;
                strcpy(arr[temp].FIO, "");
                strcpy(arr[temp].date, "");
                strcpy(arr[temp].passport, "");
            }
            temp = (temp + 1) % n;
        }
    }
    if (found == 0) cout << "������� �� ������" << endl;
    else cout << "������ �������" << endl;
}

int main()
{
    int choice = -1;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((int)time(NULL));
    int  n = 50;
    client* arr = new client[n];
    hashtab* hashtable = new hashtab[n];
    while (choice != 0) {
        cout << "1 ���������� ������� ��������" << endl;
        cout << "2 ���������� � ����" << endl;
        cout << "3 �������� �� �����" << endl;
        cout << "4 ���������� �������� � ������" << endl;
        cout << "5 �������� � ������ ��� �������" << endl;
        cout << "6 ����� ���� �������� � ��� �������" << endl;
        cout << "7 �������� �������� ���� ��������" << endl;
        cout << "8 ������ �������" << endl;
        cout << "0 ����� �� ���������" << endl;
        cout << "������� ����� ����: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1:
            makearr_rnd(n, arr);
            break;
        case 2:
            SaveArr(arr, n);
            break;
        case 3:
            LoadArr(arr, n);
            break;
        case 4:
            addEl(arr, n);
            break;
        case 5:
            hashta(arr, n, hashtable);
            break;
        case 6:
            hashFound(hashtable, n, arr);
            break;
        case 7:
            DelEL(arr, n);
            break;
        case 8:
            for (int j = 0; j < n; j++) cout << arr[j].FIO << " " << arr[j].date << " " << arr[j].passport << endl;
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}