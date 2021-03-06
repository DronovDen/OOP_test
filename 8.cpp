//Типы оператора new

//1)operator new - выделяет и инициализирует память под один объект
//(должен использоваться только в сочетании с delete)

//2)operator new[] - выделяет и инициализирует память под
// массив объектов и возвращает указатель на первый элемент
//(число выделенных обычно лежит внутри самого блока,
//в виде служебной информации, доступной только ему
//в начале или в конце - зависит от коммилятора)
//(должен использоваться только в сочетании с delete[], т.к. тот
//обращается к служебной информации, хранящей размер массива объектов
//и соответственно корректно очищает память)

#include <iostream>

class B
{
public:
    B(){};

private:
    char *c;
    int g;
};

void *operator new(std::size_t sz)
{
    if (sz == 0)
        ++sz;
    if (void *ptr = std::malloc(sz))
        return ptr;
    throw std::bad_alloc{};
}

void operator delete(void *ptr) noexcept
{
    std::free(ptr);
}

int main()
{
    int *p1 = new int;
    delete p1;
    B *b = new B;
}