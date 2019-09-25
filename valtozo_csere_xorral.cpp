#include <iostream>

int main()
{

    int t = 15, t1 = 25;
    t = t xor t1;
    t1 = t xor t1;
    t = t xor t1;
    std::cout << t << " " << t1 << "\n";

    return 0;
}