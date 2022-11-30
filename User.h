#ifndef _User_H_
#define _User_H_

#include "Character.h"
#define MAX_NO_CHARC 5

class User
{   
    private:
        char userName[10];
        char password[10];
        class Character* characters[MAX_NO_CHARC]; //Notice it’s an array of the next Class
        int size;
    public:
        User();
        User(const char* userName, const char* password);
        User(const char* userName, const char* password,  Character &character);
        User(const char* userName, const char* password, Character character[]);
    ~User();

    char* getName()
    {
        return this->userName;
    }
    char* getPassword()
    {
        return this->password;
    }
    void printCharacters();
    void ChangeCharacter(Character &c1, const char *Oldcharname);
    void CharAttack(int x, Enemy &);
    bool AddCharacter();
    char *getCharName(int x) { return characters[x]->getName();}
    int getCharLevel(int x){return characters[x]->getCharLevel();}


};
#endif /*_User_H_*/
