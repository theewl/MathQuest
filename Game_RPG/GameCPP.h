//This is a header file that represents a .cpp class. 

#include "Game.h"

Game::Game()
{
    choice = 0;
    playing = true;
    activeCharacter = 0;
    fileName = "Characters.txt";
    
}

Game::~Game()
{
    
}

void Game::initGame()
{
    createNewCharacter();

}

void Game::mainMenu()
{
    cout << "Enter to continue..." << "\n";
    cin.get();
    
    if(this->characters[activeCharacter].getExp() >= this->characters[activeCharacter].getExpNext())
    {
        cout << "You can level up!!! \n\n";
    }
    
    cout <<"Main Menu" << endl << endl;
    cout << "0: Quit" << endl;
    cout << "1: Travel" << endl;
    cout << "2: Shop" << endl;
    cout << "3: Level up" << endl;
    cout << "4: Rest" << endl;
    cout << "5: Character Sheet" << endl;
    cout << "6: New Character" << endl;
    cout << "7: Save Character" << endl;
    cout << "8: Load Characters" << endl;

    cout << endl;
    
    cout << endl << "Choice: ";
    cin >> choice;
    
    while(cin.fail())
    {
        cout << "Faulty input!" << "\n";
        cin.clear();
        cin.ignore( 100, '\n');
        
        cout << endl << "Choice: ";
        cin >> choice;
    }
    
    cin.ignore(100, '\n');
    cout << endl;
    
    switch(choice)
    {
        case 0: //Quit
            playing = false; //end game
            break;
        case 1: //Travel
            
            Travel();
            
            
            break;
        case 3: //Level up
            this->levelUpCharacter();
            break;
        case 5: //Character Sheet
            characters[activeCharacter].printStats();
            break;
        case 6:
            cin.ignore();
            createNewCharacter();
            saveCharacter();
            break;
        case 7:
            saveCharacter();
            break;
        case 8:
            loadCharacters();
            break;
        default:
            break;
            
    }
    //cin.ignore(); //to ignore choice

}

void Game::createNewCharacter()
{
    
    string name = "";
    cout << "Character Name: ";
    getline(cin, name);
    
    characters.push_back(Character()); 
    activeCharacter = characters.size() - 1; //b/c we start at 0
    characters[activeCharacter].initialize(name);
}

void Game::levelUpCharacter()
{
    this->characters[activeCharacter].levelUp();
    
    if ( this->characters[activeCharacter].getStatPoints() > 0)
    {
        cout << "You can upgrade your stats!" << "\n";
    
        cout << endl << "Stats to upgrade: " << "\n";
        cout << "0: +Strength" << "\n";
        cout << "1: +Vitality" << "\n";
        cout << "2  +Dexterity" << "\n";
        cout << "3: +Intelligence" << "\n";

        cin >> choice;
    
        while(cin.fail() || this->choice > 3)
        {
            cout << "Faulty input!" << "\n";
            cin.clear();
            cin.ignore( 100, '\n');
            
            cout << endl << "Stats to upgrade: " << "\n";
            cin >> this->choice;
        }
        
        cin.ignore(100, '\n'); //?
        cout << "\n"; //try with endl
        
        switch(this->choice)
        {
            case 0:     //strength
                this->characters[activeCharacter].addToStat(0, 1);
                break;
            case 1:     //vitality
                this->characters[activeCharacter].addToStat(1, 1);
                break;
            case 2:     //dexterity
                this->characters[activeCharacter].addToStat(2, 1);
                break;
            case 3:     //intelligence
                this->characters[activeCharacter].addToStat(3, 1);
                break;
            default:
                break;
        }
    }
}

void Game::saveCharacter()
{
    ofstream out(fileName);
    
    if(out.is_open())
    {
        for (size_t x = 0 ; x < characters.size(); x++)
        {
            out << characters[x].getAsString() << "\n";
        }
    }
    cout << "Save Successful!" << endl;
    cout << endl;
    out.close();
}
void Game::loadCharacters()
{
    ifstream in(fileName);
    
    this->characters.clear();
    
    string name = "";
    int level;
    int distanceTraveled;
    int gold = 0;
    int exp = 0;
    int str = 0;
    int vit = 0;
    int dex = 0;
    int intell = 0;
    int hp = 0;
    int stamina = 0;
    int statPoints = 0;
    int skillPoints = 0;
    
    string line = "";
    stringstream ss;
    
    if(in.is_open())
    {
        while(getline(in, line))
        {
            ss.str(line);
            ss >> name;
            ss >> distanceTraveled;
            ss >> gold;
            ss >> level;
            ss >> exp;
            ss >> str;
            ss >> vit;
            ss >> dex;
            ss >> intell;
            ss >> hp;
            ss >> stamina;
            ss >> statPoints;
            ss >> skillPoints;
            
            Character temp(name, distanceTraveled, gold, level, exp, str, vit, dex, intell, hp, stamina, statPoints, skillPoints);
            
            this->characters.push_back(Character(temp));
            
            cout << "Character " << temp.getName() << " loaded." << "\n";
            
            ss.clear();
        }
    }
    cout << "Load Successful!" << endl;
    cout << endl;
    in.close();
    if(this->characters.size() <= 0)
    {
        throw "Error! No characters loaded or empty file";
    }
}

void Game::Travel()
{
    this->characters[activeCharacter].travel();
    
    Event event;
    
    event.generateEvent(this->characters[activeCharacter]);
}
