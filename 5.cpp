//Виртуальные функции

#include <iostream>

class A
{
public:
    int GetInt() { return 1; };
    virtual void SayName() { std::cout << "A "; }
};

class B : public A
{
public:
    int GetInt() { return 2; };
    virtual void SayName() { std::cout << "B "; }
};

class C : public B
{
public:
    int GetInt() { return 3; };
    virtual void SayName() { std::cout << "C \n"; }
};

int main()
{
    C child;
    child.SayName();
    std::cout << child.GetInt() << std::endl;

    A &parent = child;
    parent.SayName();
    std::cout << parent.GetInt() << std::endl;

    return 0;
}