
#include <iostream>
#include <sstream>
#include "lzwdict.h"
using namespace std;
bool running = true;
lzwdict dict;
string inputString;
string s;
char c;

int main()
{
    cout << "\nLZW Coding Program.";

    while (running) {
        cout << "\n\nEnter string (X to close):\n";
        cin >> inputString;
        if (inputString != "X" && inputString != "x") {
            stringstream inputStream(inputString);

            inputStream >> c;
            s = c;
            while (inputStream >> c) {
                if (dict.exists(s + c)) {
                    s = s + c;
                }
                else {
                    cout << dict.getCode(s) << endl;
                    dict.insert(s + c);
                    s = c;
                }
            }
            cout << dict.getCode(s) << endl;
            dict.print();
        }
        else { running = false; }
    }
    cout << "Closing...\n";
}
