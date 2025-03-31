#ifndef UILOGIC
#define UILOGIC

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "locations.h"
#include "Enemy.h"

class ICommand {
 public:
  virtual void CommandExecute() = 0;
  virtual ~ICommand() = default;
};

class DefaultLogic {
 protected:
  std::unordered_map<std::string, std::shared_ptr<ICommand>> commands;

 public:
  DefaultLogic();
  void DoCommand(std::string &console_command);
  auto GetCommands();
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
  std::vector<Enemy *> enemies;

 public:
  static FightLogic *GetInstance();
  void AddEnemy(Enemy *enemy);
  void RemoveEnemy(Enemy *enemy);
  std::vector<Enemy *> GetEnemies();
};

class NewGame : public ICommand {
 public:
  void CommandExecute() override;
};

class ExploreCommand : public ICommand {
 public:
  void CommandExecute() override;
};

class OpenShopCommand : public ICommand {
 public:
  void CommandExecute() override;
};

class ShowInventoryCommand : public ICommand {
 public:
  void CommandExecute() override;
};

class ShowCommandsList : public ICommand {
 private:
  DefaultLogic *logic;

 public:
  ShowCommandsList(DefaultLogic *logic);
  void CommandExecute() override;
};

class Exit : public ICommand {
 public:
  void CommandExecute() override;
};

class ShowPlayerStats : public ICommand {
 public:
  void CommandExecute() override;
};
#endif  // UILOGIC