cmake_minimum_required(VERSION 3.20)
project(derelict_land)

# --- C++ Standard ---
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# --- Build Type ---
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# --- Source and Include Directories ---
set(SOURCE_DIR ${CMAKE_SOURCE_DIR})
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(INVENTORY_SYSTEM_DIR ${CMAKE_SOURCE_DIR}/inventory_system)
set(COMMANDS_DIR ${CMAKE_SOURCE_DIR}/commands)
set(MAIN_GAME_OBJ_DIR ${CMAKE_SOURCE_DIR}/main_game_obj)
set(ENTITY_DIR ${CMAKE_SOURCE_DIR}/entity)
set(LOCATIONS_DIR ${CMAKE_SOURCE_DIR}/locations)
set(LOGIC_DIR ${CMAKE_SOURCE_DIR}/logic)
set(ITEMS_DIR ${CMAKE_SOURCE_DIR}/items)
set(UTILITY_DIR ${CMAKE_SOURCE_DIR}/utility)

# --- Collect Source Files ---
file(GLOB_RECURSE SOURCE_FILES
    "${SOURCE_DIR}/main.cpp"
    "${COMMANDS_DIR}/*.cpp"
    "${MAIN_GAME_OBJ_DIR}/*.cpp"
    "${ENTITY_DIR}/*.cpp"
    "${INVENTORY_SYSTEM_DIR}/*.cpp"
    "${LOCATIONS_DIR}/*.cpp"
    "${LOGIC_DIR}/*.cpp"
    "${ITEMS_DIR}/*.cpp"
    "${UTILITY_DIR}/*.cpp"
)


# --- Executable ---
add_executable(derelict_land ${SOURCE_FILES})

# --- Include Directories ---
target_include_directories(derelict_land PUBLIC
    ${INCLUDE_DIR}
    ${COMMANDS_DIR}
    ${MAIN_GAME_OBJ_DIR}
    ${ENTITY_DIR}
    ${INVENTORY_SYSTEM_DIR}
    ${LOCATIONS_DIR}
    ${LOGIC_DIR}
    ${ITEMS_DIR}
    ${UTILITY_DIR}
)

# --- Install ---
install(TARGETS derelict_land DESTINATION bin)
