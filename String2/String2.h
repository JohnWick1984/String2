#pragma once
#include <iostream>
#include <string>
using namespace std;


class String
{
public:
    //������������
    String() : String(50) {}
    String(int size) : length(size) { data = new char[size]; }
    String(const char* str) : String(strlen(str))
    {
        memcpy(data, str, length);
    }
    //����������
    ~String() { delete[] data; }
    //������� ����� � ����������
    void input() {
        cin.getline(data, length);
    }
    //������� ������ �� ����� ���������� ������
    void output() const {
        cout << data << endl;
    }
    // ���������� ��������� ()
    int operator()(char target) const {
        for (size_t i = 0; i < length; ++i) {
            if (data[i] == target) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }
    //���������� ���������   >>
    friend istream& operator>>(istream& in, String& str) {
        // ����������� ������ ����� � �������� �����
        delete[] str.data;
        str.length = 100;  // �����������, ��� ����� ������ ������ ������������ ����� 100
        str.data = new char[str.length];

        // ������ ������ � ����������
        in.getline(str.data, str.length);

        return in;
    }

    // ���������� ��������� ������ <<
    friend ostream& operator<<(ostream& out, const String& str) {
        out << str.data;
        return out;
    }

    // �������� ���������� ���� � int
    operator int() const {
        return length - 1; // ��������� ������ ��������� ������
    }
private:
    char* data;
    int length;
};