#pragma once
#include "field.hpp"
#include <iostream>

class Spiellogik{

    private:
        int user_input;

    public:
        void place_chip_user();
        void place_chip_random();
        Field field;
        Spiellogik();
        Spiellogik(Field &game_field);
};