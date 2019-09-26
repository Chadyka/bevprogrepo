#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 1, hossz = 0;

    while (i != 0)
    {
        i = i << 1;
        cout<<i<<"\n";
        hossz++;
    }

    std::cout << hossz << "\n";
    return 0;
}