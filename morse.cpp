#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cctype>
#include <string>
#include <Windows.h>
#include <ctime>

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
    do{
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
    }while(yn == 'y' || yn == 'Y');
}

char* isitnumber()
{
    bool cond = false;
    unsigned int i = 0;
    char count[100];
    cin.ignore();
    do
    {
        char* numorlet;
        cout << "How many times? (Enter up to 100 charachters)" << endl;
        cin.getline(numorlet, 101);
        strcpy(count, numorlet);
        while(i < strlen(count))
        {
            if(isalpha(count[i]))
            {
                cout << count << " is not a number. Please enter a valid number." << endl;
                break;
            }
            else if(i == strlen(count)-1)
            {
                if(atoi(numorlet) <= 0)
                {
                    cout << "You can't input a 0 or any negative number. Please enter a valid number." << endl;
                    break;
                }
                else
                {
                    return numorlet;
                }
            }
            else
            {
                i++;
            }
        }
    }
    while(cond == false);
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
    int amount = 0, c = 0;
    amount = atoi(isitnumber());
    cout << "Enter some words, and we will translate it in morse code (Yes, you may use punctuation!): " << endl;
    getline(cin, sentence);
    while(c < amount)
    {
        c++;
        for(unsigned int i = 0; i < sentence.length(); i++)
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
        if(amount == c)
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
    int amount = 0, c = 0;
    amount = atoi(isitnumber());
    cout << "Enter some words, and we will display the morse code! (Yes, you may use punctuation!): " << endl;
    getline(cin, sentence);
    while(c < amount)
    {
        c++;
        for(unsigned int i = 0; i < sentence.length(); i++)
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
        if(c == amount)
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
    cin.ignore();
    int i = 0, j = 0;
    cout << endl << "How do you play the intro of Beethoven's 5th Symphony in C Minor?";
    cin.get();
    while(i < 3)
    {
        cout << ".";
        Beep(420, 100);
        i++;
    }
    cout << "_";
    cout << " ";
    Beep(350, 1500);
    while(j < 3)
    {
        cout << ".";
        Beep(385, 300);
        j++;
    }
    cout << "_";
    Beep(325, 2000);
}
