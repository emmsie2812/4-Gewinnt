#include "field.hpp"
#include "spiellogik.hpp"
#include <unistd.h>
#include <chrono>

//kein User input solange random dran
// wenn feld voll anzeigen das in ein anderes feld platzieren


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
        spiellogik->place_chip_user();
        spiellogik->field.field_output(5,5);
        int winlose = spiellogik->win_lose(5,5,4);
        //4 steht fuer wie viele Coins du brauchst um zu gewinnen, abgepasst um deine Level einfacher zu gestalten
        if(end_game(winlose)){
            break;
        }
        std::cout<<"Enemy Turn: \n";
        sleep(1);
        spiellogik->place_chip_random();
        spiellogik->field.field_output(5,5);
        winlose = spiellogik->win_lose(5,5,4);
        if(end_game(winlose)){
            break;
        }   
    }
    return 0;
}

bool end_game(int winlose){
        if(winlose == 1){
            std::cout << "You Win\n";
            //hier kannst du was einfuegen um zum naechsten Level zu gelangen
            return true;
        }
        if(winlose == 2){
            std::cout << "You Lose\n";
            return true;
        }
        return false;
}