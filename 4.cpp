//swap для двух int* и int&
#include <assert.h>
#include <iostream>

void swap1(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap2(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char *argv[])
{
    int a = 42;
    int b = 13;

    swap1(&a, &b);
    swap2(a, b);

    std::cout << a << b;
    return 0;
}
