#include "Event.h"

Event::Event()
{
    this-> numOfEvents = 2;
}

Event::~Event()
{
    
}

void Event::generateEvent(Character &character)
{
    int i = rand() % this->numOfEvents;
    
    switch(i)
    {
        case 0:
            //Enemy encounter
            enemyEncounter(character);
            break;
        case 1:
            //Puzzle
            puzzleEncounter(character);
            break;
        case 2:
            break;
        default:
            break;
    }
}

void Event::enemyEncounter( Character &character)
{
    //While()
}

void Event::puzzleEncounter ( Character &character)
{
    bool completed = false;
    int userAns = 0;
    int chances = 3;
    int gainExp = (chances * character.getLevel() * (rand() % 10) + 1);
    Puzzle puzzle("1.txt"); //change to path directory
    
    while(!completed && chances > 0)
    {
        cout << "Chances: " << chances << "\n\n";
        chances--;
        cout << puzzle.getAsString() << "\n";
        
        cout << "\nYour Answer: ";
        cin >> userAns;
        cout << "\n";
        
        while(cin.fail())
        {
            cout << "Faulty input!" << "\n";
            cin.clear();
            cin.ignore( 100, '\n');
            
            cout << endl << "\nYour Answer: ";
            cin >> userAns;
        }
        
        cin.ignore(100, '\n');
        cout << "\n";
        
        if(puzzle.getCorrectAns() == userAns)
        {
            completed = true;
            
            character.gainExp(gainExp);
            cout << "You gained " << gainExp << " Exp." << "\n\n";
            
        }

    }
    if (completed)
    {
        cout << "Success! \n\n";
    }
    else
    {
        cout << "Failure... \n\n";
    }
}
