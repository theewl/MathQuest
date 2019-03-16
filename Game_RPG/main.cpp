#include "Game.h"
#include "GameCPP.h"
#include "CharacterCPP.h"
#include "InventoryCPP.h"
#include "ItemCPP.h"
#include "EnemyCPP.h"
#include "EventCPP.h"
#include "PuzzleCPP.h"


using namespace std;

//Main.cpp: Loads the game.
int main()
{
    srand(time(NULL));

    
    Game game;
    game.initGame();

    while(game.getPlaying())
    {
        game.mainMenu();
    }
    
    return 0;
}





