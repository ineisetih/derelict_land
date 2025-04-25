#ifndef GAME_MASTER_H
#define GAME_MASTER_H

#include "Player.h"
#include "DefaultLogic.h"
#include "MainMenuLogic.h"
#include "TownLogic.h"
#include "FightLogic.h"
#include "ShopLogic.h"
#include "LogicHandler.h"
#include "Director.h"

class GameMaster {
 private:
  static GameMaster* instance;
  Player* current_player;
  DefaultLogic* current_logic;
  Director* director;

  GameMaster() : current_player(nullptr), current_logic(nullptr), director(new Director()){};

 public:
  ~GameMaster();
  static GameMaster* GetInstance();
  void InitializePlayer();
  void SetPlayer(Player* player);
  Player* GetPlayer() const;
  DefaultLogic* GetCurrentLogic() const;
  void SetCurrentLogic(DefaultLogic* logic);
  Director* GetDirector() const;
};

#endif
