#pragma once
#include <iostream>
#include <string>
using namespace std;


class String
{
public:
    //конструкторы
    String() : String(50) {}
    String(int size) : length(size) { data = new char[size]; }
    String(const char* str) : String(strlen(str))
    {
        memcpy(data, str, length);
    }
    //деструктор
    ~String() { delete[] data; }
    //функция ввода с клавиатуры
    void input() {
        cin.getline(data, length);
    }
    //функция вывода на экран введенного текста
    void output() const {
        cout << data << endl;
    }
    // Перегрузка оператора ()
    int operator()(char target) const {
        for (size_t i = 0; i < length; ++i) {
            if (data[i] == target) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }
    //перегрузка оператора   >>
    friend istream& operator>>(istream& in, String& str) {
        // Освобождаем старый буфер и выделяем новый
        delete[] str.data;
        str.length = 100;  // Предположим, что хотим ввести строку максимальной длины 100
        str.data = new char[str.length];

        // Вводим строку с клавиатуры
        in.getline(str.data, str.length);

        return in;
    }

    // Перегрузка оператора вывода <<
    friend ostream& operator<<(ostream& out, const String& str) {
        out << str.data;
        return out;
    }

    // Оператор приведения типа к int
    operator int() const {
        return length - 1; // Исключаем символ окончания строки
    }
private:
    char* data;
    int length;
};