#include "UIlogic.h"


#include <iostream>
#include <list>

void DefualtLogic::DoCommand(std::string console_command){
    ICommand* command;
    
 if (commands.find(console_command) != commands.end()){
    command = commands[console_command];
 } else {
    std::string str;
    std::cin >> str;
    DoCommand(str);
    return;
 }
 command->SomeBasicShit();
}

MainMenuLogic* MainMenuLogic::getMainManu(){
    if (MainMenuLogicInstance == nullptr){
        std::cout << "52";
        MainMenuLogicInstance = new MainMenuLogic;
    }
    return MainMenuLogicInstance;
}

void DefualtLogic::AddComand(std::string command_name, ICommand* command){
    commands[command_name] = command;
}

void NewGame::SomeBasicShit(){
    std::cout << "Player created";
}


int main(){
    MainMenuLogic* main_menu = MainMenuLogic::getMainManu();
    NewGame new_game;
    main_menu->AddComand("1", &new_game);
    std::string console_command;
    std::cin >> console_command;
    main_menu->DoCommand(console_command);
};