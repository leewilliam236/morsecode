#include "morse.h"

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
