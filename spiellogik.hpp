#pragma once
#include "field.hpp"
#include <iostream>

class Spiellogik{

    private:
        int user_input;

    public:
        void place_chip_user(int columns, int lines);
        void place_chip_random(int columns, int lines);
        bool full_gamefield_errormessage(int columns, int lines);
        int win_lose(int columns, int lines, int win_coins);
        Field field;
        Spiellogik();
        Spiellogik(Field &game_field);
};