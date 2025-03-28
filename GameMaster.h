#ifndef GAME_MASTER_H
#define GAME_MASTER_H

#include "Player.cpp"
#include "UILogic.h"

class Director {
 private:
  int story_points = 0;

 public:
  int GetStoryPoints() const {
    return story_points;
  }
  void SetStoryPoints(int points) {
    story_points = points;
  }
};

class GameMaster {
 private:
  static GameMaster* instance;
  Player* current_player;
  DefaultLogic* current_logic;
  Director* director;

  GameMaster() : current_player(nullptr), current_logic(nullptr), director(new Director()) {
  }

 public:
  ~GameMaster() {
    delete current_player;
    delete director;
  }

  static GameMaster* GetInstance() {
    if (!instance) {
      instance = new GameMaster();
    }
    return instance;
  }

  void InitializePlayer(const std::string& name, float health, float damage) {
    current_player = Player::CreatePlayer(name, health, damage);
  }

  Player* GetPlayer() const {
    return current_player;
  }
  DefaultLogic* GetCurrentLogic() const {
    return current_logic;
  }
  void SetCurrentLogic(DefaultLogic* logic) {
    current_logic = logic;
  }
  Director* GetDirector() const {
    return director;
  }
};

#endif