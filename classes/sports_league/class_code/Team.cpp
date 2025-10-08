#include "Team.h"

//TODO implement based on Team.h

//constructors
Team::Team(std::string _name) : name(_name), numWins(0), numLosses(0), numTies(0) {
}

Team::Team(std::string _name, const std::vector<Player>& _players)
    : name(_name), players(_players), numWins(0), numLosses(0), numTies(0) {

}

void Team::printRoster(std::ostream& _os) const {
    for(unsigned int i =0; i<players.size(); ++i) {
        players.at(i).print(_os);
        _os << std::endl;
    }
}

