#ifndef UILOGIC
#define UILOGIC

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "locations.h"

class ICommand {
 public:
  virtual void CommandExecute() = 0;
  virtual ~ICommand() = default;
};

class DefaultLogic {
 private:
  std::unordered_map<std::string, std::shared_ptr<ICommand>> commands;

 public:
  void DoCommand(std::string &console_command);
  void AddCommand(std::string command_name, std::shared_ptr<ICommand> command);
};

class LogicHandler {
 private:
  LogicHandler() = default;

 public:
  static LogicHandler *LogicHandlerInstance;
  static LogicHandler *GetInstance();
  DefaultLogic *CurrentLogic;
  void ChangeLogic(DefaultLogic *new_logic);
};

// class CommandHandler {
//  private:
//   CommandHandler() = default;
// static CommandHandler *command_handler_instance;
//  public:

//   static CommandHandler *GetInstance();
//   void ExecuteCommand(std::string &console_command);
// };

class MainMenuLogic : public DefaultLogic {
 private:
  MainMenuLogic() = default;
  static MainMenuLogic *MainMenuLogicInstance;

 public:
  static MainMenuLogic *GetInstance();
};

class TownLogic : public DefaultLogic {
 private:
  TownLogic() = default;
  static TownLogic *TownLogicInstance;

 public:
  static TownLogic *GetInstance();
};

class ShopLogic : public DefaultLogic {
 private:
  ShopLogic() = default;
  static ShopLogic *ShopLogicInstance;

 public:
  static ShopLogic *GetInstance();
};

class FightLogic : public DefaultLogic {
 private:
  FightLogic() = default;
  static FightLogic *MainFightLogicInstance;

 public:
  static FightLogic *GetInstance();
};

class NewGame : public ICommand {
 public:
  void CommandExecute() override;
};

class ExploreCommand : public ICommand {
 public:
  void CommandExecute() override {
    auto location = LocationGenerator::GenerateLocation();
    location->DisplayInfo();

    if (location->HasProperty("Enemies nearby")) {
      std::cout << "You encounter enemies!" << '\n';
      LogicHandler::GetInstance()->ChangeLogic(FightLogic::GetInstance());
    }
  }
};

class OpenShopCommand : public ICommand {
 public:
  void CommandExecute() override;
};

class ShowInventoryCommand : public ICommand {
 public:
  void CommandExecute() override;
};
#endif  // UILOGIC