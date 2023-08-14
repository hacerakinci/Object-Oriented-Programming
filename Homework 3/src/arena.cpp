/* @Author
* Student Name: Hacer Akıncı
* Student ID : 150200007
*/

#include "arena.h"

Arena::Arena()
{
    round = 1;
    terrainRound = 0;
}

void Arena::addPokemon(char myType, std::string myName, int myHP, int myDamage )
{
    std::string type;

    if (myType == 'e')
    {
        myElectricPokemon = new ElectricPokemon (myName, myHP, myDamage, 20, 3);
        myElectricPokemon->print();
    }
    else if (myType == 'p')
    {
        myPsychicPokemon = new PsychicPokemon (myName, myHP, myDamage, 30, 5);
        myPsychicPokemon->print();
    }    

    std::cout<<std::endl;
}

void Arena::simulateBattle()
{
    int heads;

    while (true){
        
        // first round or previous terrain time is over 
        if (terrainRound == 0)
        {
            spawnTerrain();
        }
    
        heads = rand()%2; // 0 for Electric Pokemon, 1 for Psychic Pokemon


        if ( heads == 0 ) // First Electric pokemon will attack
        {
            // attack function returns if opponent is fainted or not
            if (myElectricPokemon->attack(*myPsychicPokemon, round)) break;
            
            if (myPsychicPokemon->attack(*myElectricPokemon, round)) break;
        }

        else if (heads == 1) // First Psychic pokemon will attack
        {
            // attack function returns if opponent is fainted or not
            if (myPsychicPokemon->attack(*myElectricPokemon, round)) break;

            if (myElectricPokemon->attack(*myPsychicPokemon, round)) break;
        }

        printRoundStats(round, heads);
        terrainRound--;
        round++;
    }

    printRoundStats(round, heads);
    printMatchResults();
    restartTerrain();
}

void Arena::spawnTerrain()
{
    std::string terrains[3] = {"electric", "psychic", "none"};

    int chance = rand()%100; 

    /*  
        The chances of terrains are 20, 20, 60 in order. So if 
        chance is 0 - 20, terrain is electric terrain
        chance is 20 - 40, terrain is psychic terrain
        chance is 40 - 100, terrain is none
    */

    int place; // keeps the index of chosen terrain 
    if (chance < 20) place = 0; // electric terrain
    else if (chance < 40) place = 1; // psychic terrain
    else place = 2; // none

    terrain = terrains[place];

    if (terrain == "electric")
    {
        terrainRound = 5;
        myElectricPokemon->setIsOwnTerrain(true);
        myPsychicPokemon->setIsOwnTerrain(false);
    }
    else if (terrain == "psychic")
    {
        terrainRound = 5;
        myElectricPokemon->setIsOwnTerrain(false);
        myPsychicPokemon->setIsOwnTerrain(true);
    }
    else // none
    {
        terrainRound = 1;
        myElectricPokemon->setIsOwnTerrain(false);
        myPsychicPokemon->setIsOwnTerrain(false);
    }
}

void Arena::restartTerrain()
{
    terrain = "";
    terrainRound = 0;
    round = 1;
    delete(myElectricPokemon);
    delete(myPsychicPokemon);
}

void Arena::printRoundStats(int round, int heads)
{
    
    std::cout << "Round: " << round << std::endl
    << "Current Terrain: " << terrain << std::endl;

    // keeps the who is first attacked 
    Pokemon* first;

    if (heads == 0) first = myElectricPokemon;
    else first = myPsychicPokemon; 

    std::cout << first->getName() << " goes first " << std::endl;

    // If there is a power up situation, print

    // I check power up situation without isPowerUp variable
    // because if pokemon uses power first then I should change it to false, and it cannot be seen in this function
    if (round == myElectricPokemon->getPowerUpRound())
    {
        std::cout << myElectricPokemon->getName() << " has initiated a power up." << std::endl;
    }      
    if (round == myPsychicPokemon->getPowerUpRound())
    {
        std::cout << myPsychicPokemon->getName() << " has initiated a power up." << std::endl; 
    }  

    // Print HP of pokemons
    std::cout << myElectricPokemon->getName()<<" HP: "<< myElectricPokemon->getHP()<< std::endl;
    std::cout << myPsychicPokemon->getName()<<" HP: "<< myPsychicPokemon->getHP()<< std::endl;

    // Find who is leading
    Pokemon* lead;

    if ( myElectricPokemon->getHP() > myPsychicPokemon->getHP() ) lead = myElectricPokemon;
    else if ( myElectricPokemon->getHP() < myPsychicPokemon->getHP() ) lead = myPsychicPokemon;
    else lead = NULL; // draw status

    if (lead != NULL)
    {
        std::cout << lead->getName() << " is in the lead!" << std::endl;
    }
    else
    {
        std::cout << " There is a draw" << std::endl;
    }

    std::cout<<std::endl;
}

void Arena::printMatchResults()
{
    std::cout << "Match Results: " << std::endl;

    Pokemon* winner; 

    if ( myElectricPokemon->getIsFainted() ) winner = myPsychicPokemon;
    else winner = myElectricPokemon;

    std::cout << winner->getName() << " has won the match!" << std::endl;

    std::cout<<std::endl;

}

