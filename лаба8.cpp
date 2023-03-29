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
            cout << "Ошибка чтения из файла" << endl << endl;
            exit(1);
        }
    }
    return true;
}
void clearFile(const char* fail) {
    ofstream outFile(fail, ios::trunc);
    if (!outFile) {
        cout << "Ошибка открытия файла " << fail << endl << endl;
        return;
    }
    outFile.close();
    cout << "База данных успешно очищена" << endl << endl;
}
void writeToFile(ofstream& outFile, const Information& sotr) {
    outFile.write((const char*)&sotr, sizeof(Information));
}
void addInformationToFile(const char* fail) {
    ofstream outFile(fail, ios::binary | ios::app);
    if (!outFile) {
        cout << "Ошибка открытия файла " << fail << endl << endl;
        return;
    }
    Information sotr;
    cout << "Введите носитель: " << endl;
    cin >> sotr.carrier;
    cout << "Введите объём: " << endl;
    cin >> sotr.volume;
    cout << "Введите имя файла " << endl;
    cin >> sotr.name;
    cout << "Введите автора: " << endl;
    cin >> sotr.author;
    cout << endl;
    if (!cin) {
        cout << endl << "Ошибка ввода" << endl << endl;
        cin.clear();
        return;
    }
    writeToFile(outFile, sotr);
    cout << endl << "Информация успешно добавлена" << endl << endl;
    outFile.close();
}
void printFileContents(const char* fail) {
    ifstream inFile(fail, ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия файла " << fail << endl << endl;
        return;
    }
    Information sotr;
    if (inFile.peek() == EOF)
        cout << "База данных пустая" << endl << endl;
    else {
        while (readFromFile(inFile, sotr)) {
            cout << "Носитель:\t" << sotr.carrier << endl;
            cout << "Объём:\t\t" << sotr.volume << endl;
            cout << "Имя:\t\t" << sotr.name << endl;
            cout << "Автор:\t\t" << sotr.author << endl;
            cout << "-------------------------" << endl;
        }
    }
    inFile.close();
}
void removeinformationfromfile(const char* fail) {
    int volume;
    cout << "Введите объём информации и файл с ней удалится: ";
    cin >> volume;
    if (!cin) {
        cout << "Ошибка ввода" << endl << endl;
        cin.clear();
        return;
    }
    ifstream inFile(fail, ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия файла " << fail << endl << endl;
        return;
    }
    ofstream tempFile("tempfail.txt", ios::binary);
    if (!tempFile) {
        cout << "Ошибка открытия файла tempfail.txt" << endl << endl;
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
        cout << endl << "Информация успешно удалена" << endl << endl;
    }
    else {
        cout << endl << "Информация не найдена" << endl << endl;
    }
}
void addInformationToFile1(const char* fail) {
    char name[MAX_NAME_LEN];
    cout << "Введите имя носителя информации, после которой добавить следующую информацию: ";
    cin >> name;
    Information newsotr;
    cout << "Введите данные новой информации: " << endl;
    cout << "Введите носитель: " << endl;
    cin >> newsotr.carrier;
    cout << "Введите объём: " << endl;
    cin >> newsotr.volume;
    cout << "Введите имя файла " << endl;
    cin >> newsotr.name;
    cout << "Введите автора: " << endl;
    cin >> newsotr.author;
    if (!cin) {
        cout << endl << "Ошибка ввода" << endl << endl;
        cin.clear();
        return;
    }
    ifstream inFile(fail, ios::binary);
    if (!inFile) {
        cout << endl << "Ошибка открытия файла " << fail << endl << endl;
        return;
    }
    ofstream tempFile("failtemp.txt", ios::binary);
    if (!tempFile) {
        cout << endl << "Ошибка открытия файла failtemp.txt" << endl << endl;
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
        cout << endl << "Информация успешно добавлена" << endl << endl;
    }
    else {
        cout << endl << "Информация с носителем " << name << " не найдена" << endl << endl;
    }
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* fail = "fail8.txt";
    setlocale(0, "");
    cout << "Добавление информации" << endl;
    int choice;
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Вывести содержимое базы данных с информацией" << endl;
        cout << "2. Добавить информацию в базу данных" << endl;
        cout << "3. Удалить информацию с заданным объёмом" << endl;
        cout << "4. Добавить информацию после информацию с заданным объёмом" << endl;
        cout << "5. Очистить базу данных" << endl;
        cout << "6. Завершить работу с базой данных" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        if (!cin) {
            cout << endl << "Ошибка ввода" << endl << endl;
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
            cout << "Некорректный ввод" << endl << endl;
            break;
        }
    }
}