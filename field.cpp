#include "field.hpp"
#define RED "\033[31m" /* Red */
#define YELLOW "\033[33m" /* Yellow */
#define RESET "\033[0m"
#define WHITE "\033[37m" /* White */

Field::Field(){}

//Feld für Level vergrößern und bei feld_ausgeben() und feld_leer() jeweils anpassen
//Feld empty ist für das zurück setzen für erreichen eines neuen Levels
//Du kannst hier Variablen als Parameter eingeben die das Feld jeweils vergrößern oder so
void Field::fieldOutput(int columns, int lines){ 
    for(int fieldLabel = 1; fieldLabel <= lines; fieldLabel++){
        std::cout << "|  " << fieldLabel << " ";
    }
    std::cout << "\n";
    int maxFieldSeparation = lines * 4;
    for(int fieldSeparation = 1; fieldSeparation <= maxFieldSeparation; fieldSeparation = fieldSeparation + 4){
        std::cout << "_____";
    }
    std::cout << "\n";
    for (int i = lines-1; i >= 0; i--) //i Lines , j columns
    {
        std::cout << "|  ";

        for (int j = 0; j < columns; j++)
        {
            std::string color = WHITE;
            if(gameField[j][i] == 'O'){
                color = YELLOW;
            }
            
            if(gameField[j][i] == 'X'){
                color = RED;
            }
            std::cout << color << gameField[j][i] << RESET "  |  ";
        }

        std::cout << "\b\n"; 
        for(int fieldSeparation = 1; fieldSeparation <= maxFieldSeparation; fieldSeparation = fieldSeparation + 4){
                std::cout << "_____";
            }
        std::cout << "\n";
    }
}

void Field::fieldEmpty(){
    for (unsigned int i = 0; i < 5; ++i)
    {
        for (unsigned int j = 0; j < 5; ++j)
        {
            gameField[j][i] = ' ';
        }
    }
}

