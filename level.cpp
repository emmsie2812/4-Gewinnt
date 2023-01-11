#include "level.hpp"
//#include "CppRandom.hpp"
//#include <random>
#include <iostream>
#include <fstream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Defined levels. An array is returned. 
//At position 0 the columns
//At position 1 the lines
//At position 2 the needed number of stones to win
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int* Level::level_1(){
    levelSetup[0] = 4; //columns
    levelSetup[1] = 4; //lines
    levelSetup[2] = 4; //win_coins
   return levelSetup;
}
int* Level::level_2(){
    levelSetup[0] = 5; //columns
    levelSetup[1] = 5; //lines
    levelSetup[2] = 4; //win_coins
   return levelSetup;
}
int* Level::level_3(){
    levelSetup[0] = 6; //columns
    levelSetup[1] = 6; //lines
    levelSetup[2] = 4; //win_coins
   return levelSetup;
}
int* Level::level_4(){
    levelSetup[0] = 4; //columns
    levelSetup[1] = 6; //lines
    levelSetup[2] = 4; //win_coins
   return levelSetup;
}
int* Level::level_5(){
    levelSetup[0] = 6; //columns
    levelSetup[1] = 6; //lines
    levelSetup[2] = 5; //win_coins
   return levelSetup;
}
int* Level::level_6(){
    levelSetup[0] = 7; //columns
    levelSetup[1] = 7; //lines
    levelSetup[2] = 6; //win_coins
   return levelSetup;
}

int* Level::level_7(){                                                                  //To do
   /* int field_column_random = GetRandomNumberBetween(5,10);
    int field_line_random = GetRandomNumberBetween(5,10);
    int field_win_coins = GetRandomNumberBetween(4,6);

    levelSetup[0] = field_column_random; //columns
    levelSetup[1] = field_line_random; //lines
    levelSetup[2] = field_win_coins; //win_coins
    */
    levelSetup[0] = 7; //columns
    levelSetup[1] = 7; //lines
    levelSetup[2] = 6; //win_coins*/
    return levelSetup;
    //printf("Hier in level 7");
}

int Level::getLevel(){
    std::string levelFromFile;
    std::ifstream fileSavedLevels("saved_levels.txt");
    //while(getline(fileSavedLevels, levelFromFile)){
        //std::cout << levelFromFile;
    //}
    fileSavedLevels.close();
/*
            if(levelFromFile=="1"){
                return level.level_1();
            }
            else if(levelFromFile=="2"){
                return level.level_2();
            }
            else if(levelFromFile=="3"){
                return level.level_3();
            }
            else if(levelFromFile=="4"){
                return level.level_4();
            }
            else if(levelFromFile=="5"){
                return level.level_5();
            }
            else if(levelFromFile=="6"){
                return level.level_6();
            }
            else if(levelFromFile=="7"){
                return level.level_7();
            }

            switch(levelFromFile) {
                case "1":
                    levelSetup = level.level_1();
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

