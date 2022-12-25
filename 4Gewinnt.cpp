#include "field.hpp"
#include "spiellogik.hpp"
#include <unistd.h>

int main(){
    Field *game_field = new Field();
    Spiellogik *spiellogik = new Spiellogik(*game_field);
    bool time = true;

    while(time){ //dauer des spieles wenn if erreicht spiel beendet GameOver
        spiellogik->field.field_output(5,5);
        spiellogik->place_chip_user();
        spiellogik->field.field_output(5,5);
        usleep(5000);
        spiellogik->place_chip_random();
    }
    return 0;
}