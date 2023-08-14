/* @Author
* Student Name: Hacer Akıncı
* Student ID : 150200007
*/

#include "pokemon.h"

#pragma once

class PsychicPokemon; // Forward declaration

class ElectricPokemon: public Pokemon{ 
    public:
    // Constructor
    ElectricPokemon(const std::string, int, const int, const int, const int); // name, hp, damage

    void print() const; // override

    // if pokemon win after attack, return true
    bool attack(PsychicPokemon&, int);

    /* 
        After psychic pokemon attack, electric pokemon should be tracked for the confusion with the functions and variables below
    */

    // Getters
    bool getIsConfusion()  { return isConfusion; };
    int getconfusionRound(){ return confusionRound; };

    // Setters
    void setIsConfusion(bool);
    void setConfusionRound(int);
    
    private:
    bool isConfusion = false; 
    int confusionRound = 0; // it keeps which round got confusion attack
};