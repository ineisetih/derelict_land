cmake_minimum_required(VERSION 3.10)
project(derelict_land)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(derelict_land
    main.cpp
    Character.cpp
    CommandHandler.cpp
    EnemyFactory.cpp
    GameInitialisation.cpp
    GameMaster.cpp
    locations.CPP
    items.cpp
    NPC.cpp
    Player.cpp
    UIlogic.cpp
    Inventory.cpp
    Enemy.cpp
    
)

