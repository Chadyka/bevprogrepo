#include "my.h"
#include <iostream>

int main()
{
    foo = 7;
    print_foo();
    print(99);

    int x = 7;
    int y = 9;
    swap_r(x, y);
    std::cout << x << " " << y << "\n";

    swap_v(7, 9);
    
    const int cx = 7;
    const int cy = 9;
    // swap_cr(cx,cy); --- const can't be modified
    std::cout << cx << " " << cy << "\n";

    // swap_v(7.7, 9.9); --- not int value (double)

    double dx = 7.7;
    double dy = 9.9;
    
    // swap_v(dx, dy); --- not int value
    //swap_v(7.7, 9.9); ---not int value

    std::cout << cx << " " << cy << "\n";

    return 0;
}