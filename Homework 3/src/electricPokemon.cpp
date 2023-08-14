/* @Author
* Student Name: Hacer Akıncı
* Student ID : 150200007
*/

#include "electricPokemon.h"
#include "psychicPokemon.h"

ElectricPokemon::ElectricPokemon(const std::string myName, int myHP, const int myDamage, const int myPowerUp, const int myRecharge)
:Pokemon{myName, myHP, myDamage, myPowerUp, myRecharge}{}

void ElectricPokemon::print() const
{
    std::cout << "Electric Pokemon " << name << " has entered the arena." << std::endl 
    << "Class: Electric" << std::endl;

    Pokemon::print(); 
}

void ElectricPokemon::setIsConfusion(bool flag)
{
    isConfusion = flag;
}

void ElectricPokemon::setConfusionRound(int round)
{
    confusionRound = round;
}

bool ElectricPokemon::attack(PsychicPokemon& opponent, int round)
{
    // PowerUp status
    // If it has never used powerUp or it is recharged, it may use powerUp
    if ( this->powerUpRound == 0  || round - this->powerUpRound > this->recharge )
    {
        int powerUpChance = rand()%100; // Electric pokemon powerUp chance 

        if ( powerUpChance < this->powerUp )
        {
            this->isPowerUp = true;
            this->powerUpRound = round;
        }
    }
    
    int opponentHP = opponent.getHP();
    int myDamage = this->damage;

    if ( this->isPowerUp )
    {
        myDamage*=3;
        this->isPowerUp = false;
    }

    // Check if psychic pokemon used power, but also electric pokemon should not be in its own terrain
    if ( opponent.getIsPowerUp() && !this->isOwnTerrain )
    {
        opponent.setIsPowerUp(false);

        this->isConfusion = true;
        this->confusionRound = round;
    }

    if ( this->isConfusion ){
        // the confusion is over 
        if(round - this->confusionRound == 3 || this->isOwnTerrain)
        {
            this->isConfusion = false;
        }
        else myDamage = 0;
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
