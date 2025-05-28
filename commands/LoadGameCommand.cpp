#include "LoadGameCommand.h"
#include "SaveManager.h"
#include "TownLogic.h"
#include "LogicHandler.h"

#include <iostream>

// Выполняет команду загрузки игры.
// Запрашивает у пользователя имя игрока, загружает его данные.
// В случае успеха, выводит информацию о загруженном игроке и переключает логику на городскую.
void LoadGameCommand::CommandExecute() {
  std::cout << "Enter player name to load: ";
  std::string name;
  std::getline(std::cin, name);

  std::shared_ptr<Player> player = SaveManager::LoadGame(name);
  if (!player) {
    std::cerr << "Load failed: player not found in database." << std::endl;
    return;
  }

  std::cout << "Loaded player: " << name << " (Level " << player->GetLevel() << ")" << std::endl;
  LogicHandler::GetInstance()->ChangeLogic(TownLogic::GetInstance());
}
