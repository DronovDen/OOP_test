#include <iostream>
#include <string>

int main()
{
    char *c;     //указатель на символ
    int arr[10]; //массив из 10 целых

    int &ref = *arr; //ссылка на массив из 10 целых
    int(&numbers_ref)[10] = arr; //ссылка на массив из 10 целых


    std::string str_arr[10];
    std::string(*ptr)[10] = &str_arr; //указатель на массив строк

    //указатель на указатель на символ
    char **ch = &c;

    //целая константа
    const int t = 6;

    //указатель на целую константу
    const int *t_ptr = &t;

    int bl = 7;
    int *const ct = &bl; //константый указатель на целое

    //std::cout << arr;
    return 0;
}