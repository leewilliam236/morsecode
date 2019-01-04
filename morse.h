#ifndef MORSE_H
#define MORSE_H

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstring>
#include <string>

using namespace std;

class Morse
{
private:
    char charachter[54];
    string code[54];
    unsigned int wpm = 100;
    unsigned int pitch = 1000;
    unsigned int farnsworth = 200;
public:
    ~Morse()
    {
    }
    void assign(ifstream&);
    void print();
    void dotdashspace(int j)
    {
        string word;
        word = code[j];
        for(unsigned int i = 0; i < code[j].length(); i++)
        {
            if(word[i] == '.')
            {
                cout << ".";
                Beep(pitch, wpm);
            }
            else
            {
                cout << "_";
                Beep(pitch, wpm + 100);
            }
        }
        Sleep(farnsworth);
    }
    void display();
    void displayonly(int j)
    {
        string word;
        word = code[j];
        cout << word;
    }
    void joke();
};

char* isitnumber();

#endif // MORSE_H
