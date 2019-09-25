#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 1;
    int hossz = 0;

    while (i != 0)
    {
        i = i << 1;
        hossz++;
    }

    cout << hossz << endl;

    return 0;
}