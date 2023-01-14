#pragma once 
#include <iostream>

/*********************************************************************

To output the game field by cout 

*********************************************************************/

class Field {
    
    public: 
        Field();
        void fieldOutput(int columns, int row);     //To output the game field by cout 
        void emptyField();
        char gameField[10][10];                     //size game field 10x10
};