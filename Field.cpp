#include "Field.hpp"
#include "Screen.hpp"
#define RED "\033[31m" /* Red */
#define YELLOW "\033[33m" /* Yellow */
#define RESET "\033[0m"
#define WHITE "\033[37m" /* White */

Field::Field(){}

void Field::fieldOutput(int columns, int row) { 
/*********************************************************************
To output the game field by cout 
*********************************************************************/

    Screen screen;
    screen.levelDescription();              //Output
    for (int fieldLabel = 1; fieldLabel <= columns; fieldLabel++) {
        std::cout << "|  " << fieldLabel << " ";
    }
    std::cout << "|\n";
    int maxFieldSeparation = columns * 4;
    for (int fieldSeparation = 1; fieldSeparation <= maxFieldSeparation; fieldSeparation = fieldSeparation + 4) {
        std::cout << "_____";
    }
    std::cout << "\n";
    for (int i = row-1; i >= 0; i--) {      //i rows , j columns
        std::cout << "|  ";

        for (int j = 0; j < columns; j++) {
            std::string color = WHITE;
            if (gameField[j][i] == 'O') {
                color = YELLOW;
            }
            
            if (gameField[j][i] == 'X') {
                color = RED;
            }
            std::cout << color << gameField[j][i] << RESET "  |  ";
        }

        std::cout << "\b\n"; 
        for (int fieldSeparation = 1; fieldSeparation <= maxFieldSeparation; fieldSeparation = fieldSeparation + 4) {
                std::cout << "_____";
            }
        std::cout << "\n";
    }
}

void Field::fieldEmpty() {   //@Emma ungenutzt. Kann man löschen????
/*********************************************************************
empty game field
*********************************************************************/

   for (unsigned int i = 0; i < 5; ++i) {
        for (unsigned int j = 0; j < 5; ++j) {
            gameField[j][i] = ' ';
        }
    }
}
