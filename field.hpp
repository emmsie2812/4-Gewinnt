#pragma once 
#include <iostream>

class Field{

    private:
        

    public:
        void field_output(int columns, int lines);
        void field_empty();
        char game_field[10][10];
        Field();
};