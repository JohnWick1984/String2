// String2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
#include "String2.h"
using namespace std;




int main()
{
    String myString("Hello World");

    cout << "Enter your line: ";
    myString.input(); // Используем функцию-член для ввода строки

    cout << "You have entered: ";
    myString.output(); // Используем функцию-член для вывода строки
    cout << endl;
    //Реализация приведения типа к int
    cout << "Lenth of line without last simbol : " << int(myString) << endl;
    return 0;
}