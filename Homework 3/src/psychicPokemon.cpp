/* @Author
* Student Name: Hacer Akıncı
* Student ID : 150200007
*/

#include "psychicPokemon.h"
#include "electricPokemon.h"

PsychicPokemon::PsychicPokemon(const std::string myName, int myHP, const int myDamage, const int myPowerUp, const int myRecharge)
:Pokemon{myName, myHP, myDamage, myPowerUp, myRecharge}{}

void PsychicPokemon::print() const
{
    std::cout << "Psychic Pokemon " << name << " has entered the arena." << std::endl 
    << "Class: Psychic" << std::endl;

    Pokemon::print(); 
}

bool PsychicPokemon::attack(ElectricPokemon& opponent, int round)
{
    // PowerUp status
    // If it has never used powerUp or it is recharged, it may use powerUp
    if ( this->powerUpRound == 0 || round - this->powerUpRound > this->recharge )
    {
        int powerUpChance = rand()%100; // Psychic pokemon powerUp chance

        if(powerUpChance < this->powerUp)
        {
            this->isPowerUp = true;
            this->powerUpRound = round;
        }
    }
    
    int opponentHP = opponent.getHP();
    int myDamage = damage;

    if(this->isOwnTerrain){
        myDamage*=2;
    }

    opponent.setHP(opponentHP - myDamage);

    // Win status
    if(opponent.getHP() <= 0)
    {
        opponent.setHP(0);
        opponent.setIsFainted(true);
        return true;
    }
    return false;
}
