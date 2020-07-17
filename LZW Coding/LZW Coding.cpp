
#include <iostream>
#include <sstream>
#include "lzwdict.h"
using namespace std;
bool running = true;
string inputString;
string s;
char c;

int main()
{
    cout << "LZW Coding Program.";

    while (running) {
        cout << "\n\nEnter string (X to close):\n";
        cin >> inputString;
        if (inputString != "X" && inputString != "x") {
            lzwdict dict;
            stringstream inputStream(inputString);

            inputStream >> c;
            s = c;
            cout << "Output: ";
;           while (inputStream >> c) {
                if (dict.hasCode(s + c)) {
                    s = s + c;
                }
                else {
                    cout << dict.getCode(s) << " ";
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
