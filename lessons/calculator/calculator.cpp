#include "std_lib_facilities.h"

using namespace std;

int main()
{
    double leftVal = 0.0, rightVal = 0.0;
    char muv;
    std::cout << "Please enter an expression to calculate: ";
    try
    {
        while (cin >> leftVal >> muv >> rightVal)
        {
            switch (muv)
            {
            case '+':
                leftVal += rightVal;
                break;
            case '-':
                leftVal -= rightVal;
                break;
            case '*':
                leftVal *= rightVal;
                break;
            case '/':
                leftVal /= rightVal;
                break;
            default:
                break;
            }

            std::cout << "Result: " << leftVal << endl;
            std::cout << "Please enter an expression to calculate: ";
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << endl;
        keep_window_open();
        return 1;
    }
    catch (...)
    {
        std::cerr << "Error" << endl;
        keep_window_open();
        return 1;
    }
    return 0;
}