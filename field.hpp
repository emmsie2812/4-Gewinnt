#pragma once 
#include <iostream>

class Field{
    
    public:
        void fieldOutput(int columns, int lines);
        void fieldEmpty();
        char gameField[10][10];
        Field();
};