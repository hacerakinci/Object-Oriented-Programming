/* @Author
* Student Name: Hacer Akıncı
* Student ID : 150200007
*/

#include <iostream>
#include <string>
#include <time.h>

#pragma once

class Pokemon{
    public:
    // Constructor
    Pokemon(const std::string, int, const int, const int, const int); // name, hp, damage

    // Getters
    std::string getName()   { return name; };
    int getHP()             { return hp; };
    int getDamage()         { return damage; };
    int getPowerUp()        { return powerUp; };
    int getRecharge()       { return recharge; } ;
    int getPowerUpRound()   { return powerUpRound;};
    bool getIsFainted()     { return isFainted; };
    bool getIsPowerUp()     { return isPowerUp; };
    bool getIsOwnTerrain()  { return isOwnTerrain; };

    // Setters
    void setHP(int); 
    void setIsFainted(bool);
    void setIsPowerUp(bool);
    void setIsOwnTerrain(bool);
    void setPowerUpRound(int);
    
    void print() const;

    protected:
    const std::string name;
    int hp;
    const int damage;
    const int powerUp;
    const int recharge;
    
    bool isFainted = false;
    bool isPowerUp = false;
    bool isOwnTerrain = false;
    
    // this variable keeps which round pokemon used powerUp. In this way we can check if the requried recharge time is passed or not
    int powerUpRound = 0;   
};
