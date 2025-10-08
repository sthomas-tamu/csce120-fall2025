#include "Team.h"

//TODO implement based on Team.h

//constructors
Team::Team(std::string _name) : name(_name), numWins(0), numLosses(0), numTies(0) {
}

Team::Team(std::string _name, const std::vector<Player>& _players)
    : name(_name), players(_players), numWins(0), numLosses(0), numTies(0) {
}

//destructor
Team::~Team() {}

//print functions
void Team::print(std::ostream& _os) const {
    _os << name << std::endl;

    printRecord(_os);

    _os << "Roster:" << std::endl;
    printRoster(_os);
}

void Team::printRecord(std::ostream& _os) const {
    _os << "Wins: " << numWins << "\tLosses: " << numLosses << "\tTies: " << numTies << std::endl;
}

void Team::printRoster(std::ostream& _os) const {
    for(unsigned int i =0; i<players.size(); ++i) {
        _os << "\t";
        players.at(i).print(_os);
        _os << std::endl;
    }
}

void Team::updateRecord(GameOutcome _gameOutcome) {
    switch(_gameOutcome) {
        case WIN:
            numWins++;
            break;
        case LOSE:
            numLosses++;
            break;
        case TIE:
            numTies++;
            break;
    }
}
