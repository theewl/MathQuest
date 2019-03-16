#include "Enemy.h"

Enemy::Enemy(int level)
{
    this->level = level;
    this->hpMax = level * 10;
    this->hp = this->hpMax;
    this->dmgMin = this->level * 4;
    this->dmgMax = this->level * 5;
    this->dropChance = rand() % 100;
    this->def = rand() % 100;
    this->accuracy = rand() % 100;
}

Enemy::~Enemy()
{
    
}

string Enemy::getAsString() const
{
    return "Level: " + to_string(this->level) + "\n" +
        "HP: " + to_string(this->hp) + " / " + to_string(this->hpMax) + "\n" +
        "Damage: " + to_string(this->dmgMin) + " - " + to_string(this->dmgMax) + "\n" +
        "Defense: " + to_string(this->def) + "\n" +
        "Accuracy: " + to_string(this->accuracy) + "\n" +
        "Drop Chance: " + to_string(this->dropChance) + "\n";


}
