#ifndef _TEAM_H_
#define _TEAM_H_

#include <string>
#include <vector>

#include "Player.h"

// TODO:
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

    void printRoster(std::ostream& _os) const;
    
};

#endif
