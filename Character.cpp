#include <iostream>
#include <string.h>
#include "Character.h"

using namespace std;

Character::Character(const char *newCharacterName, job &characterJob)
{
    characterName = new char[strlen(newCharacterName)];
    
    if(characterName == NULL)
    {
        cout<<"No Memory allocated"; // malloc
    }

    strcpy(this->characterName, newCharacterName); 
    
    this->characterJob = characterJob;

    if  (characterJob == 0)
    {
        this->healthPoints = 50;
        this->attackStrength = 15;
    }
    if (characterJob == 1)
    {
        this->healthPoints = 20;
        this->attackStrength = 30;
    }
    if (characterJob == 2)
    {
        this->healthPoints = 30;
        this->attackStrength = 20;
    }
    if (characterJob == 3)
    {
        this->healthPoints = 35;
        this->attackStrength = 10;
    }
    if (characterJob == 4)
    {
        this->healthPoints = 25;
        this->attackStrength = 25;
    }

    this->experienceCapacity = 20;
    this->level = 0;
    this->experience = 0;
}

Character::Character(const char* characterName, job &characterJob, int healthPoints)
{
    this->characterName = new char[strlen(characterName)];
    if(this->characterName == NULL)
        cout<<"No Memory allocated for Character"; // malloc
    strcpy(this->characterName, characterName); 
    this->characterJob = characterJob;
    this->healthPoints = healthPoints;

    if  (characterJob == 0)
    {
        this->attackStrength = 15;
    }
    if (characterJob == 1)
    {
        this->attackStrength = 30;
    }
    if (characterJob == 2)
    {
        this->attackStrength = 20;
    }
    if (characterJob == 3)
    {
        this->attackStrength = 10;
    }
    if (characterJob == 4)
    {
        this->attackStrength = 25;
    }

    this->experienceCapacity = 20;
    this->level = 0;
} 

Character::Character(const char* characterName, job &characterJob, int healthPoints, int attackStrength)
{
    this->characterName = new char[strlen(characterName)];

    if(this->characterName == NULL)
        cout<<"Memory Allocation Failed for CharacterName";

    strcpy(this->characterName, characterName); 

    this->characterJob = characterJob;
    this->healthPoints = healthPoints;
    this->attackStrength = attackStrength;
    this->experienceCapacity = 20;
    this->level = 0;
}

void Character::ChangeCharacter(Character &c1)
{
    strcpy(this->characterName, c1.getName());
    this->characterJob = c1.characterJob;
    this->experience = c1.experience;
    this->experienceCapacity = c1.experienceCapacity;
    this->level = c1.level;
    this->healthPoints = c1.healthPoints;
    this->attackStrength = c1.attackStrength;
}
Character::~Character()
{
    delete this->characterName;
}

void Character::LevelUp()
{
    if(this->experience >= this->experienceCapacity)
    {
        this->experienceCapacity *= 2;
        this->level++;
        // cout<<"Good Job you have leveled up your level is: " << this->level << endl;
    }
}

void Character::attack(Enemy &EN)
{
    int x = this->healthPoints;

    if(this->attackStrength >= EN.getAttack())
    {
        this->experience += EN.getExperience();
        this->healthPoints = this->healthPoints % 7;
        EN.setHealth(0);
        // cout<<"Your health is: " << this->getHealth() << endl;
        cout << this->getName() << " Attacked  " << EN.getEnemyName() << " And gained " << EN.getExperience() << " Points of Experience" << endl;
    }
    else
    {
        this->experience  = 0;
        cout<<this->getName()<< " lost this round, experience is reduced to 0." << endl;
    }

    this->healthPoints = x;
    this->LevelUp();
}

void Character::PrintCharacter()
{
    cout << "Character Name is: " << this->getName() << endl;
    cout << endl;
}


