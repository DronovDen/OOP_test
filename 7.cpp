#include <iostream>

class A
{
public:
    A() //2
    {
        std::cout << "A constructor" << std::endl;
    }
    ~A()
    {
        std::cout << "dtor A " << std::endl;
    }

    int a; //1
};

class B : public A
{
public:
    B() //4
    {
        std::cout << "B constructor" << std::endl;
    }
    ~B()
    {
        std::cout << "dtor B" << std::endl;
    }

    int b; //3
};

class C : public B
{
public:
    C() //6
    {
        std::cout << "C constructor" << std::endl;
    }
    ~C()
    {
        std::cout << "dtor C" << std::endl;
    }

    int c; //5
};

int main()
{
    C child;
    return 0;
}

//Вывод:
//A constructor
//B constructor
//C constructor
//dtor C
//dtor B
//dtor A