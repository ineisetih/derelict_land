#ifndef UILOGIC
#define UILOGIC

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class ICommand {
 public:
  virtual void CommandExecute() = 0;
  virtual ~ICommand() = default;
};

class DefualtLogic {
 private:
  std::unordered_map<std::string, std::shared_ptr<ICommand>> commands;

 public:
  void DoCommand(std::string &console_command);
  void AddComand(std::string &command_name, std::shared_ptr<ICommand> command);
};

class LogicHandler {
 private:
  LogicHandler() = default;

 public:
  static LogicHandler *LogicHandlerInstance;
  static LogicHandler *GetInstance();
  DefualtLogic *CurrentLogic;
  void ChangeLogic(DefualtLogic *new_logic);
};

class CommandHandler {
 private:
  CommandHandler() = default;

 public:
  static CommandHandler *CommandHandlerInstance;
  static CommandHandler *GetInstance();
  void ExecuteCommand(std::string &console_command);
};


class MainMenuLogic : public DefualtLogic {
 private:
  MainMenuLogic() = default;
  static MainMenuLogic *MainMenuLogicInstance;

 public:
  static MainMenuLogic *GetInstance();
};

class TownLogic : public DefualtLogic {
 private:
  TownLogic() = default;
  static TownLogic *TownLogicInstance;

 public:
  static TownLogic *GetInstance();
};

class ShopLogic : public DefualtLogic {
 private:
  ShopLogic() = default;
  static ShopLogic *MainShopLogicInstance;

 public:
  static ShopLogic *GetInstance();
};

class FightLogic : public DefualtLogic {
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

#endif  // UILOGIC