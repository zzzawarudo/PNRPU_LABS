#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;
const int MAX_CARRIER_LEN = 50;
const int MAX_NAME_LEN = 50;
const int MAX_AUTHOR_LEN = 50;
struct Information {
    char carrier[MAX_CARRIER_LEN];
    double volume;
    char name[MAX_NAME_LEN];
    char author[MAX_AUTHOR_LEN];
};
bool readFromFile(ifstream& inFile, Information& sotr) {
    if (!inFile.read((char*)&sotr, sizeof(Information))) {
        if (inFile.eof()) {
            return false;
        }
        else {
            cout << "������ ������ �� �����" << endl << endl;
            exit(1);
        }
    }
    return true;
}
void clearFile(const char* fail) {
    ofstream outFile(fail, ios::trunc);
    if (!outFile) {
        cout << "������ �������� ����� " << fail << endl << endl;
        return;
    }
    outFile.close();
    cout << "���� ������ ������� �������" << endl << endl;
}
void writeToFile(ofstream& outFile, const Information& sotr) {
    outFile.write((const char*)&sotr, sizeof(Information));
}
void addInformationToFile(const char* fail) {
    ofstream outFile(fail, ios::binary | ios::app);
    if (!outFile) {
        cout << "������ �������� ����� " << fail << endl << endl;
        return;
    }
    Information sotr;
    cout << "������� ��������: " << endl;
    cin >> sotr.carrier;
    cout << "������� �����: " << endl;
    cin >> sotr.volume;
    cout << "������� ��� ����� " << endl;
    cin >> sotr.name;
    cout << "������� ������: " << endl;
    cin >> sotr.author;
    cout << endl;
    if (!cin) {
        cout << endl << "������ �����" << endl << endl;
        cin.clear();
        return;
    }
    writeToFile(outFile, sotr);
    cout << endl << "���������� ������� ���������" << endl << endl;
    outFile.close();
}
void printFileContents(const char* fail) {
    ifstream inFile(fail, ios::binary);
    if (!inFile) {
        cout << "������ �������� ����� " << fail << endl << endl;
        return;
    }
    Information sotr;
    if (inFile.peek() == EOF)
        cout << "���� ������ ������" << endl << endl;
    else {
        while (readFromFile(inFile, sotr)) {
            cout << "��������:\t" << sotr.carrier << endl;
            cout << "�����:\t\t" << sotr.volume << endl;
            cout << "���:\t\t" << sotr.name << endl;
            cout << "�����:\t\t" << sotr.author << endl;
            cout << "-------------------------" << endl;
        }
    }
    inFile.close();
}
void removeinformationfromfile(const char* fail) {
    int volume;
    cout << "������� ����� ���������� � ���� � ��� ��������: ";
    cin >> volume;
    if (!cin) {
        cout << "������ �����" << endl << endl;
        cin.clear();
        return;
    }
    ifstream inFile(fail, ios::binary);
    if (!inFile) {
        cout << "������ �������� ����� " << fail << endl << endl;
        return;
    }
    ofstream tempFile("tempfail.txt", ios::binary);
    if (!tempFile) {
        cout << "������ �������� ����� tempfail.txt" << endl << endl;
        inFile.close();
        return;
    }
    Information sotr;
    bool removed = false;
    while (readFromFile(inFile, sotr)) {
        if (sotr.volume == volume) {
            removed = true;
            continue;
        }
        writeToFile(tempFile, sotr);
    }
    inFile.close();
    tempFile.close();
    remove(fail);
    rename("tempfail.txt", fail);
    if (removed) {
        cout << endl << "���������� ������� �������" << endl << endl;
    }
    else {
        cout << endl << "���������� �� �������" << endl << endl;
    }
}
void addInformationToFile1(const char* fail) {
    char name[MAX_NAME_LEN];
    cout << "������� ��� �������� ����������, ����� ������� �������� ��������� ����������: ";
    cin >> name;
    Information newsotr;
    cout << "������� ������ ����� ����������: " << endl;
    cout << "������� ��������: " << endl;
    cin >> newsotr.carrier;
    cout << "������� �����: " << endl;
    cin >> newsotr.volume;
    cout << "������� ��� ����� " << endl;
    cin >> newsotr.name;
    cout << "������� ������: " << endl;
    cin >> newsotr.author;
    if (!cin) {
        cout << endl << "������ �����" << endl << endl;
        cin.clear();
        return;
    }
    ifstream inFile(fail, ios::binary);
    if (!inFile) {
        cout << endl << "������ �������� ����� " << fail << endl << endl;
        return;
    }
    ofstream tempFile("failtemp.txt", ios::binary);
    if (!tempFile) {
        cout << endl << "������ �������� ����� failtemp.txt" << endl << endl;
        inFile.close();
        return;
    }
    Information sotr;
    bool added = false;
    while (readFromFile(inFile, sotr)) {
        writeToFile(tempFile, sotr);
        if (strcmp(sotr.name, name) == 0) {
            writeToFile(tempFile, newsotr);
            added = true;
        }
    }
    inFile.close();
    tempFile.close();
    remove(fail);
    rename("failtemp.txt", fail);
    if (added) {
        cout << endl << "���������� ������� ���������" << endl << endl;
    }
    else {
        cout << endl << "���������� � ��������� " << name << " �� �������" << endl << endl;
    }
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* fail = "fail8.txt";
    setlocale(0, "");
    cout << "���������� ����������" << endl;
    int choice;
    while (true) {
        cout << "�������� ��������:" << endl;
        cout << "1. ������� ���������� ���� ������ � �����������" << endl;
        cout << "2. �������� ���������� � ���� ������" << endl;
        cout << "3. ������� ���������� � �������� �������" << endl;
        cout << "4. �������� ���������� ����� ���������� � �������� �������" << endl;
        cout << "5. �������� ���� ������" << endl;
        cout << "6. ��������� ������ � ����� ������" << endl;
        cout << "��� �����: ";
        cin >> choice;
        if (!cin) {
            cout << endl << "������ �����" << endl << endl;
            cin.clear();
            continue;
        }
        cout << endl;
        switch (choice) {
        case 1:
            printFileContents(fail);
            break;
        case 2:
            addInformationToFile(fail);
            break;
        case 3:
            removeinformationfromfile(fail);
            break;
        case 4:
            addInformationToFile1(fail);
            break;
        case 5:
            clearFile(fail);
            break;
        case 6:
            return 0;
        default:
            cout << "������������ ����" << endl << endl;
            break;
        }
    }
}