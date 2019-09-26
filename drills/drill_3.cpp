#include "std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to : ";
    string first_name;
    cin >> first_name;

    cout << "Enter the name of one of our friends : ";
    string friend_name;
    cin >> friend_name;

    cout << "Enter (m) if our friend is a male and enter (f) is our friend is a female: ";
    char friend_sex = 0;
    cin >> friend_sex;

    cout << "Enter your age : ";
    int age;
    cin >> age;

    cout << "\nDear " << first_name << ",\n";
    cout << "   How are you doing nowadays? I hope you are fine as ever! I waited a long time to see you again and here I am after all these years writing to you.\n";
    cout << "\n    Have you seen " << friend_name << " lately?";

    if (friend_sex == 'm')
    {
        cout << " If you see " << friend_name << " please ask him to call me.\n";
    }
    else if (friend_sex == 'f')
    {
        cout << " If you see " << friend_name << " please ask her to call me.\n";
    }

    cout << " I hear you just had a birthday and you are " << age << " years old.";
    if (age <= 0 || age >= 110)
    {
        cout<<"\n";
        simple_error("You're kidding!");
    }

    if (age < 12)
    {
        cout << " Next year you will be " << age + 1 << ".\n";
    }
    else if (age == 17)
    {
        cout << " Next year you will be able to vote.\n";
    }
    else if (age > 70)
    {
        cout << " I hope you are enjoying retirement.\n";
    }

    cout << "\nYours sincerely, _______ _______ Jakab Adam\n";
}