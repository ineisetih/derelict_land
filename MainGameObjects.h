#ifndef MAINGAMEOBJECTS
#define MAINGAMEOBJECTS

#include <iostream>
#include "player.h"
#include "UILogic.h"



class GameInitialisation {
public:
void StartGame();

};

class Director {
    private:
    int story_points;
public:
    int GetStoryPoints();
    void SetStoryPoints(int story_points);
    
};

class GameMaster {
public:
    Player* current_player;
    DefualtLogic* current_logic;
    Director* current_director;
//    Console* console;
};

#endif



