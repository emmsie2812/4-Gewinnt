#include "field.hpp"
#include "spiellogik.hpp"
#include "screens.hpp"
#include <unistd.h>
#include <chrono>



bool end_game(int winlose);
int levelFromStartmenu;
Screens screen;

int main(){
    //Configuration->setColums();
    //Configuration->setLines()
    //startGame()
    //
    /*int columns = level_setup[0];
    int lines = level_setup[1];
    int wincoins = level_setup[2];
    int get_level = level_setup[3];*/

    levelFromStartmenu = screen.startMenu();
    screen.clear();
    int columns = 5;
    int lines = 5;
    int wincoins = 4;

    Field *game_field = new Field();
    Spiellogik *spiellogik = new Spiellogik(*game_field);
    bool time = true;

    spiellogik->field.field_output(columns, lines);//einmal anzeigen um zu sehen wie das spielfeld aussieht
    //field_output(Spalten, Zeilen)

    //fieldoutput und win_lose haben die columns und lines als Input damit kannst du deine if abfragen steuern das 
    //if level 3 erreicht fieldoutput 6,6 als beispiel damit du den Sinn der Inputs verstehst :)

    while(time){ 
        std::cout<<"Your Turn:";
        spiellogik->place_chip_user(columns,lines);
        spiellogik->field.field_output(columns, lines); //Größe des Spielfeldes
        int winlose = spiellogik->win_lose(columns,lines,wincoins);
        //4 steht fuer wie viele Coins du brauchst um zu gewinnen, abgepasst um deine Level einfacher zu gestalten
        if(end_game(winlose)){ //Kontrolle ob gewonnen oder verloren 
            break; //Hier erreicht dann spiel beendet hier kannst du was einfügen um ins nächste Level zu gelangen
        }
        std::cout<<"Enemy Turn: \n";
        sleep(1);
        spiellogik->place_chip_random(columns,lines);
        spiellogik->field.field_output(columns, lines);
        winlose = spiellogik->win_lose(columns,lines,wincoins);
        if(end_game(winlose)){
            break;
        }   
    }
    return 0;
}

bool end_game(int winlose){
    
        switch (winlose)
        {
        case 1:
            sleep(1);
            screen.endMenuWin();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;
        case 2:
            sleep(1);
            screen.endMenulose();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;
        case 3:
            sleep(1);
            screen.endMenuWin();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;
        case 4:
            sleep(1);
            screen.endMenulose();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;
        case 5:
            sleep(1);
            screen.endMenuWin();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;
        case 6:
            sleep(1);
            screen.endMenulose();
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
            break;       
        default:
            return false;
            break;
        }
}