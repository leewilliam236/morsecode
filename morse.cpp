#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cctype>
#include <string>
#include <Windows.h>

using namespace std;

class Morse
{
private:
    char charachter[54];
    string code[54];
    int speed;
    int pitch;
public:
    void assign(ifstream&);
    void print();
    void dotdashspace(int j, int pitch = 1000)
    {
        string word;
        word = code[j];
        for(int i = 0; i < code[j].length(); i++)
        {
            if(word[i] == '.')
            {
                cout << ".";
                Beep(pitch, 100);
            }
            else
            {
                cout << "_";
                Beep(pitch, 200);
            }
        }
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
    m.print();
    m.display();
    m.space();
    m.joke();
    morse.close();
    return 0;
}

void Morse::assign(ifstream& morse)
{
    ifstream size;
    string linereader, what;
    char line[100];
    char* ptr;
    int counter = 0;
    size.open("C:\\Users\\Student\\Documents\\CPP\\morse\\morse.txt");
    while(!morse.eof())
    {
        if(morse.eof())
            break;
        getline(size, linereader);
        morse.getline(line, linereader.length() + 1);
        ptr = strtok(line, " ");
        strcpy(&charachter[counter], ptr);
        ptr = strtok(NULL, " ");
        code[counter] = ptr;
        counter++;
    }
    size.close();
}

void Morse::print()
{
    string sentence;
    char s;
    int count, amount = 0;
    cout << "How many times?";
    cin >> count;
    cin.ignore();
    cout << "To quit, press ESC." << endl;
    cout << "Enter some words, and we will translate it in morse code (Yes, you may use punctuation!): " << endl;
    getline(cin, sentence);
    while(amount < count)
    {
        amount++;
        for(int i = 0; i < sentence.length(); i++)
        {
            s = toupper(sentence[i]);
            for(int j = 0; j < 54; j++)
            {
                if(s == charachter[j])
                {
                    dotdashspace(j);
                    cout << " ";
                }
            }
        }
        cout << endl;
        if(amount == count)
        {
            break;
        }
        cout << "Enter some words, and we will translate it in morse code (Yes, you may use punctuation!): " << endl;
        getline(cin, sentence);
    }
}

void Morse::display()
{
    string sentence;
    char s;
    int count, amount = 0;
    cout << "How many times?";
    cin >> count;
    cin.ignore();
    cout << "To quit, press ESC." << endl;
    cout << "Enter some words, and we will display the morse code! (Yes, you may use punctuation!): " << endl;
    getline(cin, sentence);
    while(amount < count)
    {
        amount++;
        for(int i = 0; i < sentence.length(); i++)
        {
            s = toupper(sentence[i]);
            for(int j = 0; j < 54; j++)
            {
                if(s == charachter[j])
                {
                    displayonly(j);
                    cout << " ";
                }
            }
        }
        if(amount == count)
        {
            break;
        }
        cout << endl;
        cout << "Enter some words, and we will display the morse code! (Yes, you may use punctuation!): " << endl;
        getline(cin, sentence);
    }
}

void Morse::joke()
{
    int i = 0;
    cout << endl << "How do you play the intro of Beethoven's 5th Symphony in C Minor?";
    cin.get();
    cout << endl;
    while(i < 2)
    {
        dotdashspace(21, 425);
        cout << " ";
        i++;
    }
}
