#include "std_lib_facilities.h"

void kiir(vector<double> v, int db)
{
    for (int i = 0; i < db; i++)
    {
        std::cout << v[i] << endl;
    }
}

double tavolsag(vector<double> PR, vector<double> PRv, int n)
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

    vector<double> PR = {0.0, 0.0, 0.0, 0.0};
    vector<double> PRv = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};

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