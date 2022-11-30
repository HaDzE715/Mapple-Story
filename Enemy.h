#ifndef _Enemy_H_
#define _Enemy_H_
#include <string.h>

class Enemy
{
    private:
        char* enemyName;
        int healthPoints;
        int attackStrength;
        int experienceWorth;
    public:
        Enemy() :healthPoints(10), attackStrength(10), experienceWorth(10){} // בנאי דיפולטי
        Enemy(const char* enemyName);
        Enemy(const char* enemyName, int healthPoints);
        Enemy(const char* enemyName, int healthPoints, int attackStrength);
        Enemy(const char* enemyName, int healthPoints, int attackStrength, int exWorth);
        ~Enemy();

        char* getName()
        {
            return this->enemyName;
        }
        int getHealt() {return this->healthPoints;}
        int getAttack() {return this->attackStrength;}
        int getExperience() {return this->experienceWorth;}
        char *getEnemyName(){return this->enemyName;}

        void setHealth(int x) { this->healthPoints = x;}
        void setExperience(int x) { this->experienceWorth = x;}
        void setEnemyName(const char *name);
};

#endif /* _Enemy_H_*/

