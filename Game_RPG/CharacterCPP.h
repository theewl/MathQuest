//This is a header file that represents a .cpp class.

#include "Character.h"

Character::Character()
{
    this->distanceTraveled = 0;
    
    this->gold = 0;
    
    this->name = "";
    this->level = 0;
    this->exp = 0;
    this->expNext = 0;
    
    this->hp = 0;
    this->hpMax = 0;
    this->stamina = 0;
    this->staminaMax = 0;
    this->damageMin = 0;
    this->damageMax = 0;
    this->def = 0;
    this->accuracy = 0;
    this->luck = 0;
    
    this->statPts = 0;
    this->skillPts = 0;
    
    this-> str = 0;
    this-> vit = 0;
    this-> dex = 0;
    this-> intell = 0;
}

Character::Character(string name, int distanceTraveled, int gold, int level, int exp, int str,
                     int vit, int dex, int intell, int hp,
                     int stamina, int statPoints, int skillPoints)
{
    this->distanceTraveled = distanceTraveled;
    
    this->gold = gold;
    
    this->name = name;
    this->level = level;
    this->exp = exp;
    this->expNext = 0;
    
    this->hp = hp;
    this->hpMax = 0;
    this->stamina = stamina;
    this->staminaMax = 0;
    this->damageMin = 0;
    this->damageMax = 0;
    this->def = 0;
    this->accuracy = 0;
    this->luck = 0;
    
    this->statPts = statPoints;
    this->skillPts = skillPoints;
    
    this-> str = str;
    this-> vit = vit;
    this-> dex = dex;
    this-> intell = intell;
    
    this->updateStats();
}

Character::~Character()
{
    
}

void Character::initialize(const string name)
{
    this->distanceTraveled = 0;
    
    this->gold = 100;
    
    this-> str = 5;
    this-> vit = 5;
    this-> dex = 5;
    this-> intell = 5;
    
    this->name = name;
    this->level = 1;
    this->exp = 0;
    this->expNext = expNext = static_cast<int>((50/3)*((pow(level,3) - 6*pow(level,2)) + 17*level -12)) + 100;
    
    
    this->hpMax = (this->vit * 2) + ( this->str/2);
    this->hp = hpMax;
    this->staminaMax = this->vit + (this->str/2) + (this->dex/3);
    this->stamina = this->staminaMax;
    this->damageMin = this->str;
    this->damageMax = this->str + 2;
    this->def = this->dex + (this->intell/2);
    this->accuracy = (this->dex / 2);
    this->luck = this->intell;
    
    this->statPts = 0;
    this->skillPts = 0;
    

}

void Character::printStats() const
 {
     cout << "Character Stats" << endl;
     cout << "Name: " << this->name << endl;
     cout << "Level: " << this->level << endl;
     cout << "Exp: " << this->exp << endl;
     cout << "Exp to next level: " << this->expNext << endl;
     cout << "Strength: " << this->str << endl;
     cout << "Vitality: " << this->vit << endl;
     cout << "Dexterity: " << this->dex << endl;
     cout << "Intelligence: " << this->intell << endl;
     cout << "HP: " << this->hp << "/" << this->hpMax << endl;
     cout << "Stamina: " << this->stamina << "/" << this->staminaMax << endl;
     cout << "Damage: " << this->damageMin << "-" << this->damageMax << endl;
     cout << "Defense: " << this->def << endl;
     cout << "Accuracy: " << this->accuracy << endl;
     cout << "Luck: " << this->luck << endl;
     cout << endl;
     
 }

void Character::updateStats()
{
    this->expNext = expNext = static_cast<int>((50/3)*((pow(level,3) - 6*pow(level,2)) + 17*level -12)) + 100;
    
    this->hpMax = (this->vit * 2) + ( this->str/2);
    this->staminaMax = this->vit + (this->str/2) + (this->dex/3);
    this->damageMin = this->str;
    this->damageMax = this->str + 2;
    this->def = this->dex + (this->intell/2);
    this->accuracy = (this->dex / 2);
    this->luck = this->intell;

}

void Character::addToStat(int stat, int value)
{
    if(this->statPts < value)
    {
        cout << "Error! Not enough stat points" << endl;
    }
    else
    {
        switch(stat)
        {
            case 0:
                this->str += value;
                break;
            case 1:
                this->vit += value;
                break;
            case 2:
                this->dex += value;
                break;
            case 3:
                this->intell += value;
                break;
            default:
                cout << "Stat doesn't exist..." << "\n";
                break;
        }
        

    this->statPts -= value;
    }
}

void Character::levelUp()
{
    if(this->exp >= this->expNext)
    {
        this->exp -= this->expNext;
        this-> level++;
        this->expNext = static_cast<int>((50/3)*((pow(level,3) - 6*pow(level,2)) + 17*level -12)) + 100;
        
        this->statPts++;
        this->skillPts++;
        
        this->updateStats();

        
        cout << "You are now level: " << this->level << "\n\n";
    }
    else
    {
        cout << "Not enough exp." << "\n\n";
    }
}

string Character::getAsString() const
{
    return name + " "
        + to_string(distanceTraveled) + " "
        + to_string(gold) + " "
        + to_string(level) + " "
        + to_string(exp) + " "
        + to_string(str) + " "
        + to_string(vit) + " "
        + to_string(dex) + " "
        + to_string(intell) + " "
        + to_string(hp) + " "
        + to_string(stamina) + " "
        + to_string(statPts) + " "
        + to_string(skillPts) + " ";
}




