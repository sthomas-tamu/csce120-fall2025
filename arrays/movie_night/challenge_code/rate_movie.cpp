#include <iostream>
#include <sstream>

// CHALLENGE: creating a simple struct to pair the person's name and movie rating
struct Rating {
    std::string name;
    int score;
};

int main() {
    std::cout << "=== Movie Night Rating System ===" << std::endl;
    std::cout << "Rate our movie from 1-10" << std::endl << std::endl;

    // Create ratings array
    int GROUP_SIZE = 0;
    Rating* ratings = nullptr; // CHALLENGE: updated to be an array of Rating structs instead of int

    // Collect group size and allocate ratings array
    try {
        std::cout << "Enter the number of people in the group:" << std::endl;
        std::cin >> GROUP_SIZE;
        // check that group_size is greater than 0
        if(std::cin.fail() || GROUP_SIZE <= 0) {
            throw std::invalid_argument("Invalid group size. Group must have at least 1 person.");
        }
        ratings = new Rating[GROUP_SIZE];
      
        // Collect ratings
        std::cout << "Enter " << GROUP_SIZE << " ratings:" << std::endl;
        for(int i = 0; i < GROUP_SIZE; i++) {
            std::cout << "Person " << (i+1) << ":\n";

            // CHALLENGE: updated to read in the person's name, because reading a string, must clear any remaining in put first
            std::cout << "\tname: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, ratings[i].name);
            // check that cin did not fail
            if(std::cin.fail()) {
                std::ostringstream message;
                message << "Invalid name for person " << i+1 << ".";
                throw std::invalid_argument(message.str());
            }

            std::cout << "\trating: ";
            std::cin >> ratings[i].score; // CHALLENGE: updated to read into the score data member, here and everywhere else
            // check that rating is an integer between 1 and 10
            if(std::cin.fail() || ratings[i].score < 1 || ratings[i].score > 10) {
                std::ostringstream message;
                message << "Invalid rating for person " << i+1 << ". Rating must be an integer between 1 and 10.";
                throw std::invalid_argument(message.str());
            }
        }
    }
    catch (std::invalid_argument& e) {
        std::cout << "ERROR: " << e.what() << " Exiting.\n";
        return -1;
    }
    
    // Calculate average
    int sum = 0;
    for(unsigned int i = 0; i < GROUP_SIZE; i++) {
        sum += ratings[i].score;
    }
    double average = static_cast<double>(sum) / GROUP_SIZE;
    
    // Find highest and lowest
    Rating highest = ratings[0];
    Rating lowest = ratings[0];
    for(int i = 1; i < GROUP_SIZE; i++) {
        if(ratings[i].score > highest.score) {
            highest = ratings[i];
        }
        if(ratings[i].score < lowest.score) {
            lowest = ratings[i];
        }
    }
    
    // Display results
    std::cout << "\n=== Results ===" << std::endl;
    std::cout << "Average rating: " << average << std::endl;
    std::cout << "Highest rating: " << highest.score << ", given by \'" << highest.name << "\'" << std::endl; // CHALLENGE: updated to print both the rating and the name
    std::cout << "Lowest rating: " << lowest.score << ", given by \'" << lowest.name << "\'" << std::endl; // CHALLENGE: updated to print both the rating and the name
    
    // Recommendation
    if(average >= 7) {
        std::cout << "Consensus: Great movie!" << std::endl;
    } else if(average >= 5) {
        std::cout << "Consensus: It was okay." << std::endl;
    } else {
        std::cout << "Consensus: Pick a different movie next time!" << std::endl;
    }
   
    // Release ratings array
    delete[] ratings; // CHALLENGE: no change here since still a single array
    ratings = nullptr;
 
    return 0;
}
