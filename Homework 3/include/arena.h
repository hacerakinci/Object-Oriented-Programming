/* @Author
* Student Name: Hacer Akıncı
* Student ID : 150200007
*/


#include "electricPokemon.h"
#include "psychicPokemon.h"

#pragma once

class Arena{

    public:
    Arena();

    void addPokemon( char, std::string, int, int ); //type, name, hp, damage  
    void simulateBattle();

    private:

    // those functions do not need to be defined in public
    void spawnTerrain();
    void restartTerrain();

    void printRoundStats(int, int); // round, head
    void printMatchResults();

    // Member variables
    ElectricPokemon *myElectricPokemon;
    PsychicPokemon *myPsychicPokemon; 

    std::string terrain;
    int round;
    int terrainRound; // it keeps how many rounds are left for the current terrain
};