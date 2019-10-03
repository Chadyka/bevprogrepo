#include "std_lib_facilities.h"

int main()
{
    char escape_char;
    // 4. Működjön a program valós számokra (double)
    double new_num = 0;
    double last_num = 0;

    double min = __DBL_MAX__, max = 0;

    string dist_val;

    //9. Folyamatosan számoljuk a beírt értékek összegét méterben
    double count = 0;

    //10. Tároljunk minden értéket egy vectorban (méterben). A program végén írjuk ki.
    vector<double> values;

    //1. Írjunk egy while ciklust, mely minden lépésben beolvas és kiír 2 egész számot...
    while (true)
    {

        std::cout << "Enter the '|' character to stop or enter any other character to continue: ";
        cin >> escape_char;
        if (escape_char == '|')
        {
            break;
        }

        std::cout << "Enter a number: ";
        cin >> new_num;
        std::cout << "Add a distance value to the number (ft, in, m or cm): ";
        cin >> dist_val;

        //8. Ne engedjünk a fentieken kínül másik mértékegységet, vagy mértékegység nélküli értékeket (kezeljük!).
        if (dist_val == "m")
        {
            // DO NOTHING
        }
        else if (dist_val == "cm")
        {
            new_num = new_num / 100;
        }
        else if (dist_val == "ft")
        {
            new_num = (new_num * 12 * 2.54) / 100;
        }
        else if (dist_val == "in")
        {
            new_num = (new_num * 2.54) / 100;
        }
        else
        {
            std::cout << "\nWrong value please enter ft, in, m or cm on your next try!\n";
            continue;
        }

        values.push_back(new_num);

        // 6. Módosítsuk a programot, hogy a ciklus minden lépésben csak egy double kérjen be a usertől...
        /*
        std::cout << "Enter another number: ";
        cin >> b;
        */
        std::cout << "The entered number is: " << new_num << endl;
        if (max < new_num)
        {
            max = new_num;
            std::cout << "The largest so far!\n";
        }
        if (min > new_num)
        {
            min = new_num;
            std::cout << "The smallest so far!\n";
        }

        // 2. Nagyobb/kisebb érték kiírása
        if (new_num > last_num)
        {
            std::cout << "The smaller value is: " << last_num << endl;
            std::cout << "The larger value is: " << new_num << endl;

            //5. Írja ki a program, hogy "the numbers are almost equal", ha a két szám különbsége kisebb, mint 1.0/100.
            if (new_num - last_num < 0.01)
            {
                std::cout << "The numbers are almost equal!\n";
            }
        }
        else if (new_num < last_num)
        {
            std::cout << "The smaller value is: " << new_num << endl;
            std::cout << "The larger value is: " << last_num << endl;

            //5. Írja ki a program, hogy "the numbers are almost equal", ha a két szám különbsége kisebb, mint 1.0/100.
            if (last_num - new_num < 0.01)
            {
                std::cout << "The numbers are almost equal!\n";
            }
        }
        // 3. Jelezzük, ha a két szám egyenlő: "the numbers are equal".
        else
        {
            std::cout << "The numbers are equal!\n";
        }

        count += new_num;
        std::cout << "The sum of the values so far is: " << count << endl;

        last_num = new_num;
    }
    //10.-11.
    std::cout << "All entered values in order: ";
    sort(values.begin(), values.end());

    std::cout << values[0];

    for (int i = 1; i < values.size(); i++)
    {
        std::cout << ", " << values[i];
    }
    std::cout << endl;
}