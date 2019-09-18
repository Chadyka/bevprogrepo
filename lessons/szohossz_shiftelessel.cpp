#include "std_lib_facilities.h"

int main()
{
    int first = 1;
    int second = 0;

    while (first != 0)
    {
        first = first << 1;
        second++;
    }

    std::cout << second << endl;

    return 0;
}