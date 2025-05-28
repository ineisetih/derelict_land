#include "LocationsGenerator.h"
#include "ExploreCommand.h"
#include "FightLogic.h"
#include "TownLogic.h"
#include "LogicHandler.h" 

// Выполняет команду исследования.
// Генерирует новую локацию, отображает информацию о ней.
// Если в локации есть враги, изменяет игровую логику на боевую.
void ExploreCommand::CommandExecute() {
  auto location = LocationGenerator::GenerateLocation();
  location->DisplayInfo();
  LogicHandler::GetInstance()->ChangeLogic(TownLogic::GetInstance());

  if (location->HasProperty("Enemies nearby")) {
    std::cout << "You encounter enemies!" << '\n';
    LogicHandler::GetInstance()->ChangeLogic(FightLogic::GetInstance());
  }
}
