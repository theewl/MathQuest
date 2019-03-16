#include "Armor.h"

Armor::Armor(int type, int def, string name, int level, int buyValue, int sellValue, int rarity)
    :Item(name, level,  buyValue, sellValue, rarity) //inherit
{
    this->type = type;
    this->def = def;
}

Armor::~Armor()
{
    
}

Armor* Armor::clone() const
{
    return new Armor(*this);
}

string Armor::toString()
{
    string str = to_string(this->type) + " " + to_string(this->def);
    
    return str;
}
