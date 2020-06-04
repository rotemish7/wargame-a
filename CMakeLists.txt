cmake_minimum_required(VERSION 3.15)
project(wargame)

set(CMAKE_CXX_STANDARD 14)

add_executable(wargame Board.hpp FootSoldier.cpp FootSoldier.hpp FootCommander.cpp FootCommander.hpp Paramedic.cpp Paramedic.hpp ParamedicCommander.cpp ParamedicCommander.hpp Sniper.cpp Sniper.hpp SniperCommander.cpp SniperCommander.hpp Test.cpp Board.cpp Soldier.hpp)