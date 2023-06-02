#include <iostream>
#include <queue>
using namespace std;
typedef priority_queue <double>  deq;

deq make_deque(int kol) {
    deq d;
    for (int i = 0; i < kol; i++) {
        double a;
        //a = rand()/1.1;
        a = (double)(rand() % (10000 - (-10000) + 1) + (-10000)) / 100;
        d.push(a);
    }
    return d;
}
void print_deq(deq d) {
    while (!d.empty()) {
        std::cout << d.top() << " "; // Выводим наибольший элемент
        d.pop(); // Удаляем наибольший элемент
    }
    cout << endl;
}
int find_key(deq d, double key) {
    for (int i = 0; i < d.size(); i++) {
        if (d.top() == key) return i;
        else {
            d.pop();
        }
    }
    return -1; //элемент не найден
}
void add_deque(deq& d, double key) {
    d.push(key);
}
deq del_deque(deq d, double key) {
    deq temp;
    double cur;
    for (int i = 0; i < d.size(); ) {
        cur = d.top();
        d.pop();
        if (cur != key) {
            temp.push(cur);
        }
    }
    return temp;
}
deq min_max_deque(deq d) {
    deq temp;
    double cur;
    double max = d.top();
    for (int i = 0; i < d.size() - 1; ) {
        cur = d.top();
        d.pop();
        temp.push(cur);
    }
    double min = d.top();
    cur = d.top();
    d.pop();
    temp.push(cur);
    for (int i = 0; i < temp.size(); ) {
        cur = temp.top();
        temp.pop();
        cur = cur - (max - min);
        d.push(cur);
    }
    return d;
}

int main() {
    try {
        deq d;
        setlocale(0, "ru");
        int kol;
        cout << "Введите количество элементов: ";
        cin >> kol;
        d = make_deque(kol);
        print_deq(d);
        double key; //значение элемента
        int pos; //индекс элемента
        cout << "Введите значение элемента для добавления: "; cin >> key;
        pos = find_key(d, key);
        /* if (pos == -1) throw 1;
        else {*/
        add_deque(d, key);
        print_deq(d);
        cout << "Введите ключ элемента для удаления: ";
        cin >> key;
        d = del_deque(d, key);
        print_deq(d);
        d = min_max_deque(d);
        print_deq(d);
    }
    catch (int) {
        cout << "error";
    }
    return 0;
}