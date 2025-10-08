#include <vector>

#include "Player.h"
#include "Team.h"

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

    // TODO:
    // create a team with these players
    Team aggies("Aggies", players);

    // print the team roster
    std::cout << "Team Roster:" << std::endl;
    aggies.printRoster(std::cout);

    // print the team record

    return 0;
}
