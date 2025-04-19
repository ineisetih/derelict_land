#include "LocationsGenerator.h"
#include "ExploreCommand.h"
#include "FightLogic.h"
#include "GameMaster.h"

void ExploreCommand::CommandExecute() {
  auto location = LocationGenerator::GenerateLocation();
  location->DisplayInfo();

  if (location->HasProperty("Enemies nearby")) {
    std::cout << "You encounter enemies!" << '\n';
    LogicHandler::GetInstance()->ChangeLogic(FightLogic::GetInstance());
  }
}
