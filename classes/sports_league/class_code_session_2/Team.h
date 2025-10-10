#ifndef _TEAM_H_
#define _TEAM_H_

#include <string>
#include <vector>

#include "Player.h"

enum GameOutcome { WIN, LOSE, TIE }; //defines what game outcomes are possible (instead of using a string for example)

//   define class Team:
//     data members - name, list of players, numWins, numLosses, numTies
//     member functions - constructor, destructor, printRoster, printRecord

class Team {
  private:
    std::string name;
    std::vector<Player> players;
    unsigned int numWins, numLosses, numTies;

  public:
    //constructors
    Team(std::string _name);
    Team(std::string _name, const std::vector<Player>& _players);

    //destructor
    ~Team();

    //getter and setter methods
    std::string getName() const;
    //not providing setName, only allowing name to be set when constructed
    
    //not allowing getPlayers, only can print the roster
    //not allowing setPlayers, can only add a player
    void addPlayer(Player& p); //using Player& in case grows large so don't make temp copy

    //not allowing getRecord, only can print the record
    //not allowing setRecord, can only updateRecord and resetRecord

    //print functions
    void print(std::ostream& _os) const;
    void printRoster(std::ostream& _os) const;
    void printRecord(std::ostream& _os) const;

    //update record
    void updateRecord(GameOutcome _gameOutcome);
    void resetRecord();
};

#endif
