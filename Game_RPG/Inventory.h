#pragma once
#include "WeaponCPP.h"
#include "ArmorCPP.h"

class Inventory
{
public:
    Inventory();
    ~Inventory();
    Inventory(const Inventory &obj);
    inline int size() const
    {
        return this->numOfItems;
    };
    Item& operator[] (const int index);
    void addItem(const Item &item);
    void removeItem(int index); //remove from specific index
    inline void debugPrint() const
    {
        for ( size_t i = 0; i < this->numOfItems; i++)
        {
            cout << this->itemArr[i]->debugPrint() << endl;
        }
    }
private:
    void expand();
    void initialize(const int from = 0);
    int cap;
    int numOfItems;
    Item **itemArr;
};
