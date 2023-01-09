#include "field.hpp"
#include "spiellogik.hpp"
#include "screens.hpp"
#include <unistd.h>
#include <chrono>


bool end_game(int winlose);

int main(){
    Field *game_field = new Field();
    Spiellogik *spiellogik = new Spiellogik(*game_field);
    bool time = true;

    spiellogik->field.field_output(5,5);//einmal anzeigen um zu sehen wie das spielfeld aussieht
    //field_output(Spalten, Zeilen)

    //fieldoutput und win_lose haben die columns und lines als Input damit kannst du deine if abfragen steuern das 
    //if level 3 erreicht fieldoutput 6,6 als beispiel damit du den Sinn der Inputs verstehst :)

    while(time){ 
        std::cout<<"Your Turn:";
        spiellogik->place_chip_user(5,5);
        spiellogik->field.field_output(5,5); //Größe des Spielfeldes
        int winlose = spiellogik->win_lose(5,5,4);
        //4 steht fuer wie viele Coins du brauchst um zu gewinnen, abgepasst um deine Level einfacher zu gestalten
        if(end_game(winlose)){ //Kontrolle ob gewonnen oder verloren 
            break; //Hier erreicht dann spiel beendet hier kannst du was einfügen um ins nächste Level zu gelangen
        }
        std::cout<<"Enemy Turn: \n";
        sleep(1);
        spiellogik->place_chip_random(5,5);
        spiellogik->field.field_output(5,5);
        winlose = spiellogik->win_lose(5,5,4);
        if(end_game(winlose)){
            break;
        }   
    }
    return 0;
}

bool end_game(int winlose){
    Screens screen;
        switch (winlose)
        {
        case 1:
            sleep(1);
            screen.win_screen_horizontal();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;
        case 2:
            sleep(1);
            screen.lose_screen_horizontal();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;
        case 3:
            sleep(1);
            screen.win_screen_vertikal();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;
        case 4:
            sleep(1);
            screen.lose_screen_vertikal();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;
        case 5:
            sleep(1);
            screen.win_screen_diagonal();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;
        case 6:
            sleep(1);
            screen.lose_screen_diagonal();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;       
        default:
            return false;
            break;
        }
}