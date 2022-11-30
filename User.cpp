#include <iostream>
#include <string.h>
#include "User.h"

using namespace std;

User::User(const char* userName, const char* password)
{
    strcpy(this->userName,"YuviVerse");
    strcpy(this->password, "TwitchTTV");

}

User::User(const char* userName, const char* password, Character &character):size(1)
{  
    strcpy (this->userName, userName);
    strcpy (this->password, password);

    memset(this->characters, 0, MAX_NO_CHARC * sizeof(Character*)); // אתחול מערך של אובייקטים

    for(int i = 0; i < MAX_NO_CHARC; ++i)
        if(this->characters[i] == nullptr)
            this->characters[i] = new Character(character);
    
}

User::User(const char* userName, const char* password, Character character[]):size(1)
{  
    strcpy (this->userName, userName);
    strcpy (this->password, password);

    // memset(this->characters, 0, MAX_NO_CHARC * sizeof(Character*)); // אתחול מערך של אובייקטים

    for(int i = 0; i < MAX_NO_CHARC; ++i)
        characters[i] = nullptr;

    for(int i = 0; i < MAX_NO_CHARC; ++i)
        if(this->characters[i] == nullptr)
            this->characters[i] = &character[i];
}

User::~User()
{
}

void User::printCharacters()
{
    cout << "Your Characters are: " << endl;
    cout << "---------------------" << endl;
    cout << endl;
    for(int i = 0; i < MAX_NO_CHARC; ++i)
    {
        cout << "#--- Character Number " << i << " ---#"<< endl;
        cout << endl;
        this->characters[i]->PrintCharacter();
    }
}

void User::ChangeCharacter(Character &c1, const char *Oldcharname)
{
    for(int i = 0; characters[i] != nullptr; ++i)
    {
        if(strcmp(characters[i]->getName(), Oldcharname) == 0)
        {
            characters[i]->ChangeCharacter(c1);
        }
    }
}

bool User::AddCharacter()
{
    char *name = new char[20];
    int x;
    int flag = 0;
    job temp;
    Character *temp2;

    cout << "Enter Character Name: " << endl;
    cin >> name;
        cout << "Choose Character Job:  " << endl;
    cout << "1 - Warrior " << endl << "2 - Magician" << endl << "3 - Rouge" << endl << "4 - Archer" << endl << "5 - Pirate" << endl;
    cin >> x;

    while(x > 5 || x < 1)
    {
        cin >> x;
    }

    if  (x == 1)
    {
        temp = Warrior;
    }
    if (x == 2)
    {
        temp = Magician;
    }
    if (x == 3)
    {
        temp = Rouge;
    }
    if (x == 4)
    {
        temp = Archer;
    }
    if (x == 5)
    {
        temp = Pirate;
    }

    for(int i = 0; i < MAX_NO_CHARC; ++i)
    {
        if(characters[i] == nullptr)
        {
            characters[i] = new Character(name, temp);
            return true;
        }
    }

    return false;
}

void User::CharAttack(int x, Enemy &EN)
{
    characters[x]->attack(EN);
}