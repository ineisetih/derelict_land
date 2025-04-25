#include "GameMaster.h"

GameMaster* GameMaster::instance = nullptr;

GameMaster::~GameMaster() {
  delete current_player;
  delete director;
}

GameMaster* GameMaster::GetInstance() {
  if (!instance) {
    instance = new GameMaster();
  }
  return instance;
}

void GameMaster::InitializePlayer() {
  current_player = Player::CreatePlayer();
}

void GameMaster::SetPlayer(Player* player) {
  current_player = player;
}

Player* GameMaster::GetPlayer() const {
  return current_player;
}

DefaultLogic* GameMaster::GetCurrentLogic() const {
  return current_logic;
}

void GameMaster::SetCurrentLogic(DefaultLogic* logic) {
  current_logic = logic;
}

Director* GameMaster::GetDirector() const {
  return director;
}
