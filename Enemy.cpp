#include <iostream>
#include "Enemy.h"
//#include "Character.h"
#include <string.h>

using namespace std;

Enemy::Enemy(const char* enemyName) : experienceWorth(22), healthPoints(10), attackStrength(10)
{
  this->enemyName = new char [strlen (enemyName)];

  if (this->enemyName == NULL)
  {
    cout<<"No Memory allocated";
  }

   strcpy(this->enemyName, enemyName);
}

Enemy::Enemy(const char* enemyName, int healthPoints) : experienceWorth(22), attackStrength(10)
{
    this->enemyName = new char [strlen (enemyName)];

    if (this->enemyName == NULL)
    {
        cout<<"No Memory allocated";
    }

    strcpy(this->enemyName, enemyName);

    this->healthPoints = healthPoints;
}

Enemy::Enemy(const char* enemyName, int healthPoints, int attackStrength) : experienceWorth(22)
{
   this->enemyName = new char [strlen (enemyName)];

    if (this->enemyName == NULL)
    {
        cout<<"No Memory allocated";
    }

    strcpy(this->enemyName, enemyName);

    this->healthPoints = healthPoints;
    this->attackStrength = attackStrength;
}
Enemy::Enemy(const char* enemyName, int healthPoints, int attackStrength, int exWorth)
{
   this->enemyName = new char [strlen (enemyName)];

    if (this->enemyName == NULL)
    {
        cout<<"No Memory allocated";
    }

    strcpy(this->enemyName, enemyName);

    this->healthPoints = healthPoints;
    this->attackStrength = attackStrength;
    this->experienceWorth = exWorth;
}

void Enemy::setEnemyName(const char *name)
{
    int len = strlen(name);
    this->enemyName = new char[len];
    strcpy(enemyName, name);
}

Enemy::~Enemy()
{
    delete this->enemyName;
}