cmake_minimum_required(VERSION 3.12)

project(ChessGame)

file(GLOB SRC_FILES src/*.cpp)

add_executable(chess_game ${SRC_FILES})

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/conan)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};${CMAKE_CURRENT_SOURCE_DIR}/conan)

find_package(SFML REQUIRED)

target_include_directories(chess_game PUBLIC include ${SFML_INCLUDE_DIR})

target_link_libraries(chess_game sfml::sfml)
