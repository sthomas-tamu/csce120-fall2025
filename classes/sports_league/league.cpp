#include <iostream>
#include <string>
#include <vector>

class Player {
    std::string name;
    unsigned int jerseyNumber;
    std::string position;

  public: 
    // constructor
    Player() {
        name = "";
        jerseyNumber = 0;
        position = "";
    }

    // constructor that initializes the data members
    Player(std::string _name, unsigned int _jerseyNumber, std::string _position)
        : name(_name), jerseyNumber(_jerseyNumber), position(_position) {
    }

    // function that prints to any ostream, set to const to prevent side-effects
    void print(std::ostream& _os) const {
        _os << name << "\t" << jerseyNumber << "\t" << position;
    }
};

int main() {
    // create a vector of players
    std::vector<Player> players;
    players.push_back(Player("Maggie Aggie", 1, "goalie"));
    players.push_back(Player("Miss Rev", 2, "striker"));
   

    // print the players
    std::cout << "The players are: " << std::endl;
    for(unsigned int i=0; i<players.size(); ++i) {
        players.at(i).print(std::cout);
        std::cout << std::endl;
    }

    return 0;
}
