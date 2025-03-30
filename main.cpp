#include "GameInitialisation.h"
#include "CommandHandler.h"
#include <iostream>

int main() {
  try {
    GameInitialisation::StartGame();

    CommandHandler* handler = CommandHandler::GetInstance();
    std::string input;
    while (true) {
      std::cout << "> ";
      std::getline(std::cin, input);

      if (input == "exit") {
        break;
      }

      handler->ExecuteCommand(input);
    }
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }

  return 0;
}

