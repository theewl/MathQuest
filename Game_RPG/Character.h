#pragma once
#include <string>
#include "Inventory.h"
#include "Enemy.h"
using namespace std;

class Character
{
public:
    Character();
    Character(string name, int distanceTraveled, int gold, int level, int exp, int str,
              int vit, int dex, int intell, int hp,
              int stamina, int statPoints, int skillPoints);
    virtual ~Character();
    
    //Functions
    void initialize(const string name);
    void printStats() const;
    void levelUp();
    string getAsString() const;
    void updateStats();
    void addToStat(int stat, int value);
    
    //Accessors

    inline const int& getDistanceTraveled() const //return reference
    {
        return this->distanceTraveled;
    }
    
    inline const string& getName() const //return reference
    {
        return this->name;
    }
   
    inline const int& getLevel() const //return reference
    {
        return this->level;
    }
    
    inline const int& getExp() const //return reference
    {
        return this->exp;
    }
    
    inline const int& getExpNext() const //return reference
    {
        return this->expNext;
    }
    
    inline const int& getStatPoints() const
    {
        return this->statPts;
    }
    
    inline const int& getHP() const //return reference
    {
        return this->hp;
    }
    
    inline const int& getHPMax() const //return reference
    {
        return this->hpMax;
    }
    
    inline const int& getStamina() const //return reference
    {
        return this->stamina;
    }
    
    inline const int& getDamageMin() const //return reference
    {
        return this->damageMin;
    }
    
    inline const int& getDamageMax() const //return reference
    {
        return this->damageMax;
    }
    
    inline const int& getDef() const //return reference
    {
        return this->def;
    }
    
    inline const int& getAccuracy() const //return reference
    {
        return this->accuracy;
    }
    
    //Modifiers
    inline void setDistanceTraveled(const int& distance)
    {
        this->distanceTraveled = distance;
    }
    
    inline void travel()
    {
        this->distanceTraveled++;
    }
    
    inline void gainExp(const int& exp)
    {
        this->exp += exp;
    }
    
private:
    int distanceTraveled;
    
    Inventory inventory;
    Weapon weapon;
    Armor armor_chest;
    Armor armor_head;
    Armor armor_arms;
    Armor armor_legs;
    int gold;
    
    string name;
    int level;
    int exp;
    int expNext;
    int hp;
    int hpMax;
    int stamina;
    int staminaMax;
    int damageMin;
    int damageMax;
    int def;
    int accuracy;
    int luck;
    
    int str;
    int vit;
    int dex;
    int intell;
    
    
    int statPts;
    int skillPts;
    
};
