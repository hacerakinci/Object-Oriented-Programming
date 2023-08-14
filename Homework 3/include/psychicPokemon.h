/* @Author
* Student Name: Hacer Akıncı
* Student ID : 150200007
*/


#include "pokemon.h"

#pragma once

class ElectricPokemon;

class PsychicPokemon: public Pokemon{
    public:
    PsychicPokemon(const std::string, int, const int, const int, const int); // name, hp, damage
    
    void print() const; // override

    // if pokemon win after attack, return true
    bool attack(ElectricPokemon&, int);

};