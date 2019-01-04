/**
Author: leewilliam236
Compiler: GNU GCC Compiler
IDE: Code::Blocks (Windows 10 Pro)
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "morse.h"

using namespace std;

void igotoptions(Morse&);

int main()
{
    Morse m;
    ifstream morse;
    morse.open("C:\\Users\\Student\\Documents\\CPP\\morse\\morse.txt");
    if(morse.fail())
    {
        cout << "Can't open file.";
        exit(0);
    }
    m.assign(morse);
    cout << "leewilliam236's morsecodetranslator! v0.2-beta" << endl;
    cout << "Hello and Welcome to my Morse Code Translator! Would you to do like me to display the code or type the code?" << endl;
    igotoptions(m);
    morse.close();
    return 0;
}

void igotoptions(Morse& m)
{
    unsigned short option;
    cout << endl <<  " 1. Display" << endl;
    cout << " 2. Type" << endl;
    cout << " 3. Joke" << endl;
    cout << " 4. Quit" << endl;
    cin >> option;
    char yn;
    do
    {
        switch(option)
        {
        case 1:
            m.display();
            break;
        case 2:
            m.print();
            break;
        case 3:
            m.joke();
            break;
        case 4:
            cout << "See you around!" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid Entry. Please enter 1, 2, 3, or 4." << endl;
            igotoptions(m);
            break;
        }
        cout << endl << "Wanna do it again? (y/n)" << endl;
        cin >> yn;
        if(yn == 'n')
            igotoptions(m);
    }
    while(yn == 'y' || yn == 'Y');
}
