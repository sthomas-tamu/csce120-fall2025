#include <vector>

#include "Team.h"

int main() {
    // create a vector of players
    std::vector<Player> players;
    players.push_back(Player("Maggie Aggie", 1, "goalie"));
    players.push_back(Player("Miss Rev", 2, "striker"));

    // create a team with these players
    Team aggies("Aggies", players);

    // print the team information
    aggies.print(std::cout);

    // update record to reflect some game outcomes
    aggies.updateRecord(WIN);
    aggies.updateRecord(LOSE);
    aggies.updateRecord(TIE);
    aggies.updateRecord(WIN);
    aggies.updateRecord(WIN);
    aggies.updateRecord(WIN);
    aggies.updateRecord(LOSE);
    aggies.updateRecord(LOSE);

    std::cout << std::endl << "After playing some games, the record is now ";
    aggies.printRecord(std::cout);

    return 0;
}
