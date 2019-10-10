#include "std_lib_facilities.h"

void kiir(double arr[], int db)
{
    for (int i = 0; i < db; i++)
    {
        std::cout << arr[i] << endl;
    }
}

double tavolsag(double PR[], double PRv[], int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; ++i)
    {
        sum += (PRv[i] - PR[i]) * (PRv[i] - PR[i]);
    }

    return sqrt(sum);
}

int main()
{
    double L[4][4] = {
        {0.0, 0.0, 1.0 / 3.0, 0.0},
        {1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
        {0.0, 1.0 / 2.0, 0.0, 0.0},
        {0.0, 0.0, 1.0 / 3.0, 0.0}};

    double PR[4] = {0.0, 0.0, 0.0, 0.0};
    double PRv[4] = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};

    int i, j;

    for (;;)
    {

        for (int i = 0; i < 4; i++)
        {
            PR[i] = 0.0;
            for (int j = 0; j < 4; j++)
            {
                PR[i] += (L[i][j] * PRv[j]);
            }
        }

        if (tavolsag(PR, PRv, 4) < 0.00001)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            PRv[i] = PR[i];
        }
    }

    kiir(PR, 4);

    return 0;
}