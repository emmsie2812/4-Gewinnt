#include "screens.hpp"
#include "level.cpp"

Screens::Screens(){}

void Screens::win_screen_vertikal(){
    std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*      Nice turn!       *\n*   You won vertically  *\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
}

void Screens::win_screen_horizontal(){
    std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*      Nice turn!       *\n*  you won horizontally *\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
}

void Screens::win_screen_diagonal(){
    std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*      Nice turn!       *\n*   You won diagonally  *\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
}

void Screens::lose_screen_vertikal(){
    std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*  That wasn't great... *\n* You lost vertically!  *\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
}

void Screens::lose_screen_horizontal(){
    std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*  That wasn't great... *\n* You lost horizontally!*\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
}

void Screens::lose_screen_diagonal(){
    std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*  That wasn't great... *\n*   You lost diagonal!  *\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
}


void main_menu(){


}
        
int* start_menu(){
    Level level;
    bool invalid_input = true;
    while(!invalid_input){
        std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*  (:  Hello Dear! :)   *\n*Do you want to start a new Game?*\n*Then please press 1*\n*Or do you want to reload your score?*\n*Then please press 2*\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
        int start_input; 
        cin >> start_input; // Get user input from the keyboard
        if(start_input==1){
            std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*Let's start a new game!*\n*                       *\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
            level_setup = level.level_1();
        }
        else if(start_input==2){
            std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*     (: Good luck :)     *\n*                       *\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
            std::string level_from_file;
            std::ifstream file_saved_levels("saved_levels.txt");
            while(getline(file_saved_levels, level_from_file)){
                //std::cout << level_from_file;
            }
            file_saved_levels.close();

            if(level_from_file=="1"){
                level_setup = level.level_1();
            }
            else if(level_from_file=="2"){
                level_setup = level.level_2();
            }
            else if(level_from_file=="3"){
                level_setup = level.level_3();
            }
            else if(level_from_file=="4"){
                level_setup = level.level_4();
            }
            else if(level_from_file=="5"){
                level_setup = level.level_5();
            }
            else if(level_from_file=="6"){
                level_setup = level.level_6();
            }
            else if(level_from_file=="7"){
                level_setup = level.level_7();
            }
        }
    }
    return level_setup;
}
        
        
void end_menu(){

}

       