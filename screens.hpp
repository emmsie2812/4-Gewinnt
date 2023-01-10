#pragma once
#include <iostream>

class Screens{

    public:
        Screens();
        void win_screen_vertikal();
        void win_screen_horizontal();
        void win_screen_diagonal();
        void lose_screen_vertikal();
        void lose_screen_horizontal();
        void lose_screen_diagonal();
        void main_menu();
        int* start_menu();
        void end_menu();

};