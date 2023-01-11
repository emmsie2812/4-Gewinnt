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

    Field *gameField = new Field();
    Spiellogik *spiellogik = new Spiellogik(*gameField);
    bool time = true;

    spiellogik->field.fieldOutput(columns, lines);//einmal anzeigen um zu sehen wie das spielfeld aussieht
    //fieldOutput(Spalten, Zeilen)

    //fieldoutput und winLose haben die columns und lines als Input damit kannst du deine if abfragen steuern das 
    //if level 3 erreicht fieldoutput 6,6 als beispiel damit du den Sinn der Inputs verstehst :)

    while(time){ 
        std::cout<<"Your Turn:";
        spiellogik->placeChipUser(columns,lines);
        spiellogik->field.fieldOutput(columns, lines); //Größe des Spielfeldes
        int winlose = spiellogik->winLose(columns,lines,wincoins);
        //4 steht fuer wie viele Coins du brauchst um zu gewinnen, abgepasst um deine Level einfacher zu gestalten
        if(end_game(winlose)){ //Kontrolle ob gewonnen oder verloren 
            break; //Hier erreicht dann spiel beendet hier kannst du was einfügen um ins nächste Level zu gelangen
        }
        std::cout<<"Enemy Turn: \n";
        sleep(1);
        spiellogik->placeChipRandom(columns,lines);
        spiellogik->field.fieldOutput(columns, lines);
        winlose = spiellogik->winLose(columns,lines,wincoins);
        if(end_game(winlose)){
            break;
        }   
    }
    return 0;
}

bool end_game(int winlose){
        //sleep(1);
        switch (winlose)
        {
        case 1:
            screen.endMenuWin();
            return true;
            break;
        case 2:
            screen.endMenuLose();
            return true;
            break;
        case 3:
            screen.endMenuWin();
            return true;
            break;
        case 4:
            screen.endMenuLose();
            return true;
            break;
        case 5:
            screen.endMenuWin();
            return true;
            break;
        case 6:
            screen.endMenuLose();
            return true;
            break;       
        default:
            return false;
            break;
        }
}