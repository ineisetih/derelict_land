#include "UILogic.h"
#include "player.h"
#include "MainGameObjects.h"
#include <iostream>
#include <string>




int main() {
    MainMenuLogic* main_menu_logic = MainMenuLogic::GetInstance();
    GameMaster::current_logic = main_menu_logic;
    std::string console_command;
    while (true) {
        std::cin >> console_command;
        GameMaster::current_logic->DoCommand(console_command);
    }
    return 0;
}