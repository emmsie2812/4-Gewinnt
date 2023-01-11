#include "screens.hpp"
//#include "level.cpp"
//#include <conio.h>
#include <iostream>

Screens::Screens(){

}

void Screens::win_screen_vertikal(){
    //clrscr();
    std::cout << "\n\n\n\n\n\n\n\n"
                "*************************\n"
                "*                       *\n"
                "*                       *\n"
                "*                       *\n"
                "*                       *\n"
                "*      Nice turn!       *\n"
                "*   You won vertically  *\n"
                "*                       *\n"
                "*                       *\n"
                "*                       *\n"
                "*                       *\n"
                "*************************\n"
                "\n\n\n";
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
        
int start_menu(){


    /*
    initLevel()
    askUser()
    setupLevel()
    */
    
    bool valid_input = false;
    while(!valid_input){
        std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*     (:  Hello!  :)    *\n*Do you want to start a new Game?*\n*Then please press 1*\n*Or do you want to reload your score?*\n*Then please press 2*\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
        int start_input; 
        std::cin >> start_input; // Get user input from the keyboard
        if(start_input==1){
            std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*Let's start a new game!*\n*                       *\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
            valid_input = true;
            int start_new = 1;
            return start_new;
        }
        else if(start_input==2){
            ////////////////////////////////////////////
            // Lese Datei aus und prüfe, ob Bereich 1-7
            ///////////////////////////////////////////
            
            //int* level_setup[3];


            std::cout << "\n\n\n\n\n\n\n\n**************************\n*                       *\n*                       *\n*                       *\n*                       *\n*     (: Good luck :)     *\n*                       *\n*                       *\n*                       *\n*                       *\n*                       *\n*************************\n\n\n";
            
            valid_input = true;
        }
        else{
            std::cout << "Please try again 1 or 2!";
        }
    }
    return 10;
}
        
        
void end_menu(){

}

       