/* @Author
* Student Name: Hacer Akıncı
* Student ID : 150200007
*/

#include "pokemon.h"

Pokemon::Pokemon(const std::string myName, int myHP, const int myDamage, const int myPowerUp, const int myRecharge)
:name{myName}, hp{myHP}, damage{myDamage}, powerUp{myPowerUp}, recharge{myRecharge} {}


// Setters

void Pokemon::setHP(int newHP)
{
    hp = newHP;
}

void Pokemon::setIsFainted(bool flag)
{
    isFainted = flag;
}

void Pokemon::setIsPowerUp(bool flag)
{
    isPowerUp = flag;
}

void Pokemon::setIsOwnTerrain(bool flag)
{
    isOwnTerrain = flag;
}

void Pokemon::setPowerUpRound(int round)
{
    powerUpRound = round;
}

void Pokemon::print() const
{
    std::cout << "\tName: "<< name << std::endl 
    << "\tHP: "<< hp << std::endl 
    << "\tDamage: "<< damage << std::endl;
}