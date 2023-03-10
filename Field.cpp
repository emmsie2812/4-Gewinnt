#include "Field.hpp"
#include "Screen.hpp"
#define RED "\033[31m" /* Red */
#define YELLOW "\033[33m" /* Yellow */
#define RESET "\033[0m"
#define WHITE "\033[37m" /* White */

Field::Field() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            gameField[i][j] = '\0';
        }
    }
}

void Field::fieldOutput(int columns, int row) { 
/*********************************************************************
To output the game field by cout 
*********************************************************************/

    Screen screen;
    screen.levelDescription();              //Output
    for (int fieldLabel = 1; fieldLabel <= columns; fieldLabel++) {
        std::cout << "| " << fieldLabel << " ";
    }
    std::cout << "|\n";
    int maxFieldSeparation = columns * 4;
    for (int fieldSeparation = 1; fieldSeparation <= maxFieldSeparation; fieldSeparation = fieldSeparation + 4) {
        std::cout << "____";
    }
    std::cout << "\n";
    for (int i = row-1; i >= 0; i--) {      //i rows , j columns
        std::cout << "| ";

        for (int j = 0; j < columns; j++) {
            std::string color = WHITE;
            bool spotEmpty = true;
            if (gameField[j][i] == 'O') {
                color = YELLOW;
                spotEmpty = false;
            }
            
            if (gameField[j][i] == 'X') {
                color = RED;
                spotEmpty = false;
            }
            if(spotEmpty){
                std::cout << "  | ";
            } else {
                std::cout << color << gameField[j][i] << RESET " | ";
            }
           
        }

        std::cout << "\b\n"; 
        for (int fieldSeparation = 1; fieldSeparation <= maxFieldSeparation; fieldSeparation = fieldSeparation + 4) {
                std::cout << "____";
            }
        std::cout << "\n";
    }
}

void Field::emptyField(){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            gameField[i][j] = '\0';
        }
    }
}
