#pragma once
#include "field.hpp"
#include <iostream>

class Spiellogik{

    private:
        int user_input;

    public:
        void place_chip_user();
        void place_chip_random();
        int win_lose(int columns, int lines);
        Field field;
        Spiellogik();
        Spiellogik(Field &game_field);
};