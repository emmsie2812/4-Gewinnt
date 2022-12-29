#pragma once
#include "field.hpp"
#include <iostream>

class Spiellogik{

    private:
        int user_input;

    public:
        void place_chip_user(int columns, int lines);
        void place_chip_random(int columns, int lines);
        bool invalid_input(int columns, int lines, int user_input);
        int win_lose(int columns, int lines, int win_coins);
        int diagonal_win_lose(int columns, int lines,int win_coins);
        int vertical_win_lose(int columns, int lines,int win_coins);
        int horizontal_win_lose(int columns, int lines,int win_coins);
        Field field;
        Spiellogik();
        Spiellogik(Field &game_field);
};