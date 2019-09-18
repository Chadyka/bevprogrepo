#include "std_lib_facilities.h"

int main()
{
    int a, b;

    std::cout << "Enter two numbers with a space between them: ";
    cin >> a >> b;

    std::cout << "The numbers in order: " << a << " " << b << endl;
    
    a = a xor b;
    b = a xor b;
    a = a xor b;

    std::cout << "The numbers switched: " << a << " " << b << endl;

    return 0;
}