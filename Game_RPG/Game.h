//Game header file

#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <math.h>
#include <vector>
#include <fstream>
#include "Functions.h"
#include "Event.h"
#include <sstream>


using namespace std;

class Game
{
public:
    Game();
    virtual ~Game();
    
    //Operators
    
    //Functions
    void initGame();
    void mainMenu();
    void createNewCharacter();
    void levelUpCharacter();
    void saveCharacter();
    void loadCharacters();
    void Travel();
    
    //Accessors
    inline bool getPlaying() const
    {
        return this->playing;
    };
    
    //Modifiers
    
private:
    int choice;
    bool playing;
    string fileName;
    int activeCharacter;
    vector<Character> characters;

};


