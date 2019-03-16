#include "Weapon.h"

Weapon::Weapon(int dmgMin, int dmgMax, string name, int level, int buyValue, int sellValue, int rarity)
: Item(name, level,  buyValue, sellValue, rarity) //inherit
{
    this->dmgMin = dmgMin;
    this->dmgMax = dmgMax;
}

Weapon::~Weapon()
{
    
}

Weapon* Weapon::clone() const
{
    return new Weapon(*this);
}

string Weapon::toString()
{
    string str = to_string(this->dmgMin) + " " + to_string(this->dmgMax);
    
    return str;
}
