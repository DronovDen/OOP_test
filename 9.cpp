#include <cassert>
#include <iostream>

template <typename T>
class my_vector
{
public:
    my_vector(int capacity)
        : data(new T[capacity]), capacity(capacity){};

    ~my_vector() { delete[] data; };

    void resize()
    {
        T *arr = new T[size * 2];
        capacity = capacity * 2;
        for (int i = 0; i < size; i++)
        {
            arr[i] = data[i];
        }
        delete[] data;
        data = arr;
    };

    int push_back(T i)
    {
        if (size + 1 == capacity)
            resize();
        data[size] = i;
        size++;
        return size;
    };

    T operator[](int i)
    {
        assert(i < size && i >= 0);
        return data[i];
    };

    T at(int i)
    {
        assert(i < size && i >= 0);
        return data[i];
    };

    T pop_back()
    {
        assert(size > 0);
        size--;
        return data[size];
    };

    int getSize() { return size; };

    my_vector &my_vector::operator=(my_vector &other)
    {
        if (&other != this)
        {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new int[capacity];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

private:
    T *data;
    int size = 0;
    int capacity;
};

int main()
{
    my_vector<int> arr(2);
    arr.push_back(13);
    arr.push_back(42);
    arr.push_back(23);
    arr.push_back(23);

    // 13
    std::cout << arr.at(0) << std::endl;
    // 42
    std::cout << arr.pop_back() << std::endl;
    // 1
    std::cout << "Size: " << arr.getSize() << std::endl;
    arr.~my_vector();

    return 0;
}