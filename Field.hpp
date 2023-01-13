#pragma once 
#include <iostream>

/*********************************************************************

To output the game field by cout 

*********************************************************************/

class Field {
    
    public: 
        Field();
        void fieldOutput(int columns, int row);     //To output the game field by cout 
        char gameField[10][10];                     //size game field 10x10
};