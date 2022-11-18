cmake_minimum_required(VERSION 3.23)
project(PokervsJL_fichiers_seulement)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PokervsJL_fichiers_seulement
        Card.cpp
        Card.h
        GameComparaison.cpp
        GameComparaison.h
        GameGeneration.cpp
        GameGeneration.h
        main.cpp)
