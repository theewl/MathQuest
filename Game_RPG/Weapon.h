#pragma once
#include "Item.h"

class Weapon: public Item
{
public:
    Weapon(int dmgMin = 0, int dmgMax = 0, string name = "NONE", int level = 0, int buyValue = 0, int sellValue = 0, int rarity = 0);
    virtual ~Weapon();
    
    //Functions
    string toString();
    
    //Pure Virtual
    virtual Weapon* clone() const;

private:
    int dmgMin;
    int dmgMax;
};
