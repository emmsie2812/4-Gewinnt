#include "screens.hpp"

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

       