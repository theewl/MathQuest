#pragma once

#include<stdlib.h>
#include<string>

class Enemy
{
public:
    Enemy(int level = 0);
    virtual ~Enemy();
    inline bool isAlive() //inline?
    {
        return this->hp > 0;
    }
    
    string getAsString() const;
    
    inline void takeDmg(int dmg)
    {
        this->hp -= dmg;
    }
    inline int getDmg() const
    {
        return rand() % this->dmgMax - this->dmgMin;
    }
    
    inline int getExp() const
    {
        return this->level * 100;
    }
    
private:
    int level;
    int hp;
    int hpMax;
    int dmgMin;
    int dmgMax;
    float dropChance;
    int def;
    int accuracy;
};
