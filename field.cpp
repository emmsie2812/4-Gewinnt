#include "field.hpp"
#define RED "\033[31m" /* Red */
#define YELLOW "\033[33m" /* Yellow */
#define RESET "\033[0m"
#define WHITE "\033[37m" /* White */

Field::Field(){}

//Feld für Level vergrößern und bei feld_ausgeben() und feld_leer() jeweils anpassen
//Feld empty ist für das zurück setzen für erreichen eines neuen Levels
//Du kannst hier Variablen als Parameter eingeben die das Feld jeweils vergrößern oder so
void Field::field_output(int columns, int lines){ 
    std::cout << "| 1  | 2  | 3  | 4  | 5  |\n";
    std::cout << "___________________________\n";

    for (int i = lines-1; i >= 0; i--)
    {
        std::cout << "|  ";

        for (int j = 0; j < columns; j++)
        {
            std::string color = WHITE;
            if(game_field[j][i] == 'O'){
                color = YELLOW;
            }
            
            if(game_field[j][i] == 'X'){
                color = RED;
            }
            std::cout << color << game_field[j][i] << RESET "  |  ";
        }

        std::cout << "\b\n"; 

        std::cout << "___________________________\n";
    }
}

void Field::field_empty(){
    for (unsigned int i = 0; i < 5; ++i)
    {
        for (unsigned int j = 0; j < 5; ++j)
        {
            game_field[j][i] = ' ';
        }
    }
}

