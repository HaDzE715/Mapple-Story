#include <iostream>
#include <string.h>
#include "User.h"
#include "Enemy.h"
#include "Character.h"

using namespace std;


char userName[] = "YuviVerse";
char password[] = "TwitchTTV";


int main()
{
    job x[5] = {Warrior, Magician, Rouge, Archer, Pirate}; 

    Character CharactersArray[5];

    Character c1("Nave", x[0]);
    Character c2("Liel", x[1]);
    Character c3("Niv", x[2]);
    Character c4("Eden", x[3]);
    Character c5("Maya", x[4]);

    int CharChoice;
    int EnemyChoice;
    int ActionChoice;
    
    char *UserName = new char[10];
    char *PassWord = new char[10];

    CharactersArray[0] = c1;
    CharactersArray[1] = c2;
    CharactersArray[2] = c3;
    CharactersArray[3] = c4;
    CharactersArray[4] = c5;

    cout << endl;
    cout << "Enter your login details: " << endl;
    cin >> UserName;
    cin >> PassWord;

    for(int i = 0; i < 10; ++i)
    {
        if(UserName[i] != userName[i] || PassWord[i] != password[i])
        {
            cout<<"Error, Write your login details again!" << endl;
            cin >> UserName;
            cin >> PassWord;
        }
    }
    User *u1 = new User(UserName, PassWord, CharactersArray);

    Enemy *Enem = new Enemy[4 * sizeof(Enemy*)];
    
    cout<<endl;
    cout << "Welcome " << userName << endl;
    cout<<endl;
    u1->printCharacters();
    cout<<endl;

    cout<<"Choose Character: " << endl;
    cin >> CharChoice;


    for(int i = 0; i < 1000; ++i)
    {
        cout<<"Please choose your option: (0 to exit) " << endl;
        cout<<"1 - Attack " << endl;
        cout<<"2 - Level " << endl;
        cout<<"3 - Change Character " << endl;

        cin >> ActionChoice;

        if(ActionChoice == 0)
        {
            return 0;
        }
        if(ActionChoice == 1)
        {    
            cout << "Choose which Enemy to attack" << endl;
            Enem[0].setEnemyName("Enemy1");
            Enem[1].setEnemyName("Enemy2");
            Enem[2].setEnemyName("Enemy3");
            Enem[3].setEnemyName("Enemy4");
            cout<<endl;
            for(int i = 0; i < 4; ++i)
            {
                Enem[i].setExperience(20);
                cout << i << " - " << Enem[i].getEnemyName() << endl;
            }
            cin >> EnemyChoice;
            u1->CharAttack(CharChoice, Enem[EnemyChoice]);
        }
        if(ActionChoice == 2)
        {
            cout << u1->getCharName(CharChoice) << "'s level is "<< u1->getCharLevel(CharChoice) << endl;
        }
        if(ActionChoice == 3)
        {
            u1->printCharacters();
            cout<<endl;
            cout << "Choose your character: " << endl;
            cin>>CharChoice;
        }
    }

    delete UserName;
    delete PassWord;
    delete u1;
    delete[] Enem;

    return 0;

}