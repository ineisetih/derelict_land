#ifndef MAINGAMEOBJECTS
#define MAINGAMEOBJECTS

#include <iostream>
#include "player.h"



class GameInitialisation {
public:
void StartGame();

};
class GameMaster {
public:
    GameInitialisation* current_gameInitialisation;
    Player* current_player;
//    Director* current_director;
//    Console* console;

};

#endif



