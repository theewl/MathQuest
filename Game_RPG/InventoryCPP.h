#include "Inventory.h"

Inventory::Inventory()
{
    this->cap = 5;
    this->numOfItems = 0;
    this->itemArr = new Item*[cap];
    this->initialize();
}

Inventory::Inventory(const Inventory &obj)
{
    this->cap = obj.cap;
    this-> numOfItems = obj.numOfItems;
    this->itemArr = new Item*[this->cap];
    
    for (size_t i = 0; i < this->numOfItems; i++)
    {
        this->itemArr[i] = obj.itemArr[i]->clone();
    }
    
    initialize(this->numOfItems);
}

Item& Inventory::operator[](const int index)
{
    if (index < 0 || index >= this->numOfItems)
        throw("Bad Index");
    
    return *this->itemArr[index];
}

Inventory::~Inventory()
{
    for (size_t i = 0; i < this->numOfItems; i++) //size_t?
    {
        delete this->itemArr[i];
    }
    delete[] itemArr;
}

void Inventory::expand()
{
    this->cap *= 2;
    
    Item **tempArr = new Item*[this->cap];
    
    for ( size_t i = 0; i < this->numOfItems; i++)
    {
        tempArr[i] = this->itemArr[i];
    }

    delete[] this->itemArr;
    
    this->itemArr = tempArr;
    
    this->initialize(this->numOfItems);

}
void Inventory::initialize(const int from)
{
    for (size_t i = from; i < cap; i++)
    {
        this->itemArr[i] = nullptr;
    }

}

void Inventory::addItem(const Item &item)
{
    if(this->numOfItems >= this->cap)
    {
        expand();
    }
    this->itemArr[this->numOfItems++] = item.clone();
}
void Inventory::removeItem(int index)
{
    
}
