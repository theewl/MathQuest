#include "Item.h"

Item::Item(string name, int level, int buyValue, int sellValue, int rarity) //has to be in order
{
    this->name = name;
    this->level = level;
    this->buyValue = buyValue;
    this->sellValue = sellValue;
    this->rarity = rarity;

}

Item::~Item()
{
    
}
