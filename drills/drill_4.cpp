#include "std_lib_facilities.h"

int main()
{
    char escape_char;
    // 4. Működjön a program valós számokra (double)
    double new_num = 0;
    double last_num = 0;

    double min = __DBL_MAX__, max = 0;

    //1. Írjunk egy while ciklust, mely minden lépésben beolvas és kiír 2 egész számot...
    while (true)
    {

        cout << "Enter the '|' character to stop or enter any other character to continue: ";
        cin >> escape_char;
        if (escape_char == '|')
        {
            break;
        }

        last_num = new_num;

        cout << "Enter a number: ";
        cin >> new_num;
        // 6. Módosítsuk a programot, hogy a ciklus minden lépésben csak egy double kérjen be a usertől...
        /*
        cout << "Enter another number: ";
        cin >> b;
        */
        cout << "The entered number is: " << new_num << endl;
        if (max < new_num)
        {
            max = new_num;
            cout << "The largest so far!\n";
        }
        if (min > new_num)
        {
            min = new_num;
            cout << "The smallest so far!\n";
        }

        // 2. Nagyobb/kisebb érték kiírása
        if (new_num > last_num)
        {
            cout << "The smaller value is: " << last_num << endl;
            cout << "The larger value is: " << new_num << endl;

            //5. Írja ki a program, hogy "the numbers are almost equal", ha a két szám különbsége kisebb, mint 1.0/100.
            if (new_num - last_num < 0.01)
            {
                cout << "The numbers are almost equal!\n";
            }
        }
        else if (new_num < last_num)
        {
            cout << "The smaller value is: " << new_num << endl;
            cout << "The larger value is: " << last_num << endl;

            //5. Írja ki a program, hogy "the numbers are almost equal", ha a két szám különbsége kisebb, mint 1.0/100.
            if (last_num - new_num < 0.01)
            {
                cout << "The numbers are almost equal!\n";
            }
        }
        // 3. Jelezzük, ha a két szám egyenlő: "the numbers are equal".
        else
        {
            cout << "The numbers are equal!\n";
        }
    }
}