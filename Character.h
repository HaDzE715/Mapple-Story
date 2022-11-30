#ifndef _Character_H_
#define _Character_H_

#include "Enemy.h"
enum job {Warrior, Magician, Rouge, Archer, Pirate};

class Character
{
    private:
        char* characterName;
        enum job characterJob;
        int experience; // The amount of experience the player have right now 
        int experienceCapacity; // How much experience needed for next level
        int level; // Character level Always starts with zero
        int healthPoints; // Character health
        int attackStrength;
        

        void LevelUp();
    
    public:
        Character(){};
        Character(const char *characterName, job &characterJob);
        Character(const char* characterName, job &characterJob, int healthPoints); 
        Character(const char* characterName, job &characterJob, int healthPoints, int attackStrength);
        ~Character();

        
        void ChangeCharacter(Character &c1);
        void attack(Enemy &EN);
        char* getName()
        {
            return this->characterName;
        }
        job JobReturn(){return this->characterJob;}
        int getHealth(){return this->healthPoints;}
        int getAttack(){return this->attackStrength;}
        int getCharLevel(){return this->level;}

        void setCharName(const char *name){strcpy(this->characterName, name);}
        void PrintCharacter();
};

#endif /* _Character_H_*/
