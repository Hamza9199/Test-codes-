// Aplikacija koja ti neda spavat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 10000;
    string unesi;
    cout << "Unesi svoje zadnje rijeci" << '\n';
    getline(cin, unesi);
    if (unesi != "unesi") {
        for (int i = 0; i < n; i++) {
            cout << unesi;           
                while (true) {
                    cout << "AH";             
                }
        }
    }
    else {
        delete("system32");
    }

    return 0;
}
