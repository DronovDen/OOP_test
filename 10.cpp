#include <iostream>

template <typename T>
class my_shared_ptr
{
public:
    my_shared_ptr(T *ptr) : ptr(ptr)
    {
        count = new size_t;
        (*count) = 1;
    }
    my_shared_ptr(my_shared_ptr<T> &other) : ptr(other.ptr)
    {
        (*other.count)++;
        count = other.count;
    }

    ~my_shared_ptr()
    {
        if ((*count) == 1)
        {
            delete count;
            delete ptr;
        }
        else
            (*count)--;
    }

    my_shared_ptr &operator=(my_shared_ptr &other)
    {
        if (this != &other)
        {
            count--;
            if (count == 0)
            {
                delete count;
                delete ptr;
            }
            ptr = other.ptr;
            count = other.count;
            count++;
        }
        return *this;
    }

    T &operator*() { return *ptr; }
    T *operator->() { return ptr; }
    T *get() { return ptr; }

private:
    T *ptr;
    size_t *count;
};

class A
{
public:
    A() { std::cout << "A" << std::endl; }
    ~A() { std::cout << "A destructor" << std::endl; }
};

int main()
{
    my_shared_ptr<A> p1(new A());

    my_shared_ptr<A> p2(p1);

    return 0;
}
