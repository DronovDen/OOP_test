//Exceptions

#include <iostream>
#include <string>

class A
{
public:
    A(){};

    size_t code = 0;

protected:
    int n = 0;

    //std::string code = "A ";
};

class B : public A
{
public:
    B() : code(n + 1) { n++; }
    size_t code;
};

class C : public B
{
public:
    C() : code(n + 1) { n++; }
    size_t code;
};

int main()
{
    try
    {
        throw C();
    }
    catch (C &child)
    {
        std::cerr << "caught C - " << child.code << std::endl;
    }
    catch (B &parent)
    {
        std::cerr << "caught B - " << parent.code << std::endl;
    }
    catch (A &grand)
    {
        std::cerr << "caught A - " << grand.code << std::endl;
    }
    return 0;
}