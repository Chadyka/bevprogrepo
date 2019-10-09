#include "std_lib_facilities.h"

int main()
{
    try
    {
        // 1. cout << "Success!\n"; error: cout with uppercase C

        // 2. cout << "Success!\n"; error: statement without matching " char

        // 3. cout << "Success!" << "!\n"; error: statement without matching " chars

        /* 4. error: no variable named success 
        string success = "Success!";
        cout << success << '\n';
        */

        /* 5. error: integer initalized as string
        int res = 7;
        vector<int> v(10);
        v[5] = res;
        cout << "Success!\n";
        */

        /* 6. error: v(5) is not a valid call for v[5], also changed logic to == instead of !=
        vector<int> v(10);
        v[5] = 7;
        if (v[5] == 7)
            cout << "Success!\n";
        */

        /* 7. error: cond wasn't declared, needs to be anything but 0 for successful logic 
        int cond = 12345;
        if (cond)
            cout << "Success!\n";
        else
            cout << "Fail!\n";
        */

        /* 8. error: changed logic to invert c --- (c) -> (!c)
        bool c = false;
        if (!c)
            cout << "Success!\n";
        else
            cout << "Fail!\n";
        */

        /* 9. error: changed boo to bool and reversed greater thn operator
        string s = "ape";
        bool c = "fool" > s;
        if (c)
            cout << "Success!\n";
        */

        /* 10. error: changed logic from s == "fool" to s == "ape"
        string s = "ape";
        if (s == "ape")
            cout << "Success!\n"; 
        */

        /* 11. error: changed logic from == to != , and added << operator to cout
        string s = "ape";
        if (s != "fool")
            cout << "Success!\n";
        */

        /* 12. error: if statement must have a boolean value inside
        string s = "ape";
        if (s < "fool")
            cout << "Success!\n"; 
        */

        /* 13. error: changed 0 < v.size() to i < v.size()
        vector<char> v(5);
        for (int i = 0; i < v.size(); ++i)
            ;
        cout << "Success!\n"; 
        */

        /* 14. error: changed <= to <
        vector<char> v(5);
        for (int i = 0; i < v.size(); ++i)
            ;
        cout << "Success!\n";
        */

        /* 15. error: changed iterations to iterate until the end of the string 
        string s = "Success!\n";
        for (int i = 0; i < s.size(); ++i)
            cout << s[i];
        
        */

        /* 16. error: removed "then" 
        if (true)
            cout << "Success!\n";
        else
            cout << "Fail!\n";
        */

        /* 17. error: changed char c; to int c; 
        int x = 2000;
        int c = x;
        if (c == 2000)
            cout << "Success!\n";
        */

        /* 18. error: no bug 10 could be changed to s.size()
        string s = "Success!\n";
        for (int i = 0; i < 10; ++i)
            cout << s[i];
        */

        /* 19. error: vector had no type 
        vector<int> v(5);
        for (int i = 0; i <= v.size(); ++i)
            ;
        cout << "Success!\n";
        */

        /* 20. error: increment i instead of j 
        int i = 0;
        int j = 9;
        while (i < 10)
            ++i;
        if (j < i)
            cout << "Success!\n";
        */

        /* 21. error: changed values to be floating point operations and equal
        int x = 2;
        double d = 9.0 / x;
        if (d == 2 * x + 0.5)
            cout << "Success!\n";
        */

        /* 22. error: String requires no additional <type>
        string s = "Success!\n";
        for (int i = 0; i <= 10; ++i)
            cout << s[i]; 
        */

        /* 23. error: declared variable j and incremented i instead of j
        int i = 0;
        int j = 1;
        while (i < 10)
            ++i;
        if (j < i)
            cout << "Success!\n";
        */

        /* 24. error: changed = to != in if statement
        int x = 4;
        double d = 5 / (x-2);
        if (d != 2 * x + 0.5)
            cout << "Success!\n";
        */

        /* 25. error: changed cin to cout
        cout << "Success!\n";
        */

        keep_window_open();
        return 0;
    }
    catch (std::exception &e)
    {
        std::cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...)
    {
        std::cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}