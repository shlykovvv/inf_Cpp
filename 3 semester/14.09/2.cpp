#include <iostream>
#include <vector>

class MyClass {
    int x = 0;
    char *str = nullptr;
    char *m_str = new char[10];
public:
    MyClass(int x, char *ch): x(x), str(ch) {}
    MyClass(const MyClass &s): x(s.x), str(s.str) {} // конструктор копирования
    //MyClass(int x, char *ch) {
    //   this->x = x;
    //   str = ch;
    //}
    ~MyClass() {
        delete[] m_str;
    }

public:
    void print(int y) {
        std::cout << x*y << std::endl;
    }
    void foo();
};

void MyClass::foo() {
    std::cout << x;
}

int main() {
    MyClass mc;
    MyClass mc1 = MyClass(1, nullptr);
    MyClass mc2(1, nullptr);
    MyClass ss = mc2; // копирование
    mc.print(10);

    return 0;
}
