#ifndef UILOGIC
#define UILOGIC

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class ICommand{
    public:
    virtual void SomeBasicShit() = 0;
};

class DefualtLogic{
    private:
    std::unordered_map<std::string, ICommand*> commands;
    public:
    
    void DoCommand(std::string console_command);
    void AddComand(std::string command_name, ICommand* command);
};


class MainMenuLogic : public DefualtLogic{
    private:
    MainMenuLogic();
public:
static MainMenuLogic* MainMenuLogicInstance;
static MainMenuLogic* getMainManu();

};

class NewGame : public ICommand{
    public:
    void SomeBasicShit() override;
};



#endif // UILOGIC