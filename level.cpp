#include "level.hpp"
//#include "CppRandom.hpp"
//#include <random>
#include <iostream>
#include <fstream>

int* Level::level_1(){
    level_setup[0] = 4; //columns
    level_setup[1] = 4; //lines
    level_setup[2] = 4; //win_coins
    level_setup[3] = 1; //Level
    std::cout << "Level 1";
   return level_setup;
}
int* Level::level_2(){
    level_setup[0] = 5; //columns
    level_setup[1] = 5; //lines
    level_setup[2] = 4; //win_coins
    std::cout << "Level 2";
   return level_setup;
}
int* Level::level_3(){
    level_setup[0] = 6; //columns
    level_setup[1] = 6; //lines
    level_setup[2] = 4; //win_coins
    std::cout << "Level 3";
   return level_setup;
}
int* Level::level_4(){
    level_setup[0] = 4; //columns
    level_setup[1] = 6; //lines
    level_setup[2] = 4; //win_coins
    std::cout << "Level 4";
   return level_setup;
}
int* Level::level_5(){
    level_setup[0] = 6; //columns
    level_setup[1] = 6; //lines
    level_setup[2] = 5; //win_coins
    
   return level_setup;
}
int* Level::level_6(){
    level_setup[0] = 7; //columns
    level_setup[1] = 7; //lines
    level_setup[2] = 6; //win_coins
    
   return level_setup;
}

int* Level::level_7(){                                                                  //To do
   /* int field_column_random = GetRandomNumberBetween(5,10);
    int field_line_random = GetRandomNumberBetween(5,10);
    int field_win_coins = GetRandomNumberBetween(4,6);

    level_setup[0] = field_column_random; //columns
    level_setup[1] = field_line_random; //lines
    level_setup[2] = field_win_coins; //win_coins
    */
    level_setup[0] = 7; //columns
    level_setup[1] = 7; //lines
    level_setup[2] = 6; //win_coins*/
    return level_setup;
    printf("Hier in level 7");
}

int Level::getLevel(){
    std::string level_from_file;
    std::ifstream file_saved_levels("saved_levels.txt");
    while(getline(file_saved_levels, level_from_file)){
        std::cout << level_from_file;
    }
    file_saved_levels.close();
/*
            if(level_from_file=="1"){
                return level.level_1();
            }
            else if(level_from_file=="2"){
                return level.level_2();
            }
            else if(level_from_file=="3"){
                return level.level_3();
            }
            else if(level_from_file=="4"){
                return level.level_4();
            }
            else if(level_from_file=="5"){
                return level.level_5();
            }
            else if(level_from_file=="6"){
                return level.level_6();
            }
            else if(level_from_file=="7"){
                return level.level_7();
            }

            switch(level_from_file) {
                case "1":
                    level_setup = level.level_1();
                    break;
                case "2":
                case "3":
                case "4":
                case "5":
                case "6":
                case "7":
                default
            }*/
        int thisIsLevel = 3;
        return thisIsLevel;

}

