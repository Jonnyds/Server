cmake_minimum_required(VERSION 3.8)
project(Server)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Server.cpp Server.h Command.h CommandsManager.cpp CommandsManager.h
        StartCommand.h StartCommand.cpp JoinCommand.h JoinCommand.cpp ListGamesCommand.h
        ListGamesCommand.cpp CloseCommand.h CloseCommand.cpp PlayCommand.h PlayCommand.cpp
        GameManager.cpp GameManager.h HandleClient.cpp HandleClient.h GameList.cpp GameList.h)

add_executable(main ${SOURCE_FILES})