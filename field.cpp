#include "field.hpp"
#include "level.hpp"
#include <fstream>
#define RED "\033[31m" /* Red */
#define YELLOW "\033[33m" /* Yellow */
#define RESET "\033[0m"
#define WHITE "\033[37m" /* White */

Field::Field(){}

//Feld für Level vergrößern und bei feld_ausgeben() und feld_leer() jeweils anpassen
//Feld empty ist für das zurück setzen für erreichen eines neuen Levels
//Du kannst hier Variablen als Parameter eingeben die das Feld jeweils vergrößern oder so
void Field::field_output(){ 
    Level level;
    int* level_setup;
    std::string level_from_file;
    std::ifstream file_saved_levels("saved_levels.txt");
    while(getline(file_saved_levels, level_from_file)){
        std::cout << level_from_file;
    }
    file_saved_levels.close();
/*
    if(level_from_file=='1'){
        level_setup = level.level_1();
    }
    elseif(level_from_file=='2'){
        level_setup = level.level_2();
    }
    elseif(level_from_file=='3'){
        level_setup = level.level_3();
    }
    elseif(level_from_file=='4'){
        level_setup = level.level_4();
    }
    elseif(level_from_file=='5'){
        level_setup = level.level_5();
    }
    elseif(level_from_file=='6'){
        level_setup = level.level_6();
    }
    else{
        level_setup = level.level_7();
    }*/
    level_setup = level.level_1();
    int columns = level_setup[0];
    int lines = level_setup[1];

    for(int field_label = 1; field_label <= lines; field_label++){
        std::cout << "|  " << field_label << " ";
    }
    std::cout << "\n";
    int max_field_separation = lines * 4;
    for(int field_separation = 1; field_separation <= max_field_separation; field_separation = field_separation + 4){
        std::cout << "_____";
    }
    std::cout << "\n";
    for (int i = lines-1; i >= 0; i--) //i Lines , j columns
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
        for(int field_separation = 1; field_separation <= max_field_separation; field_separation = field_separation + 4){
                std::cout << "_____";
            }
        std::cout << "\n";
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

