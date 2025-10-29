#include <iostream>
#include <sstream>

int main() {
    std::cout << "=== Movie Night Rating System ===" << std::endl;
    std::cout << "Rate our movie from 1-10" << std::endl << std::endl;

    // TODO Challenge: Revise to also report the name of the person who gave the highest and lowest rating

    // Create ratings array
    int GROUP_SIZE = 0;
    int* ratings = nullptr;

    // Collect group size and allocate ratings array
    try {
        std::cout << "Enter the number of people in the group:" << std::endl;
        std::cin >> GROUP_SIZE;
        // check that group_size is greater than 0
        if(std::cin.fail() || GROUP_SIZE <= 0) {
            throw std::invalid_argument("Invalid group size. Group must have at least 1 person.");
        }
        ratings = new int[GROUP_SIZE];
      
        // Collect ratings
        std::cout << "Enter " << GROUP_SIZE << " ratings:" << std::endl;
        for(int i = 0; i < GROUP_SIZE; i++) {
            std::cout << "Person " << (i+1) << ": ";
            std::cin >> ratings[i];
            // check that rating is an integer between 1 and 10
            if(std::cin.fail() || ratings[i] < 1 || ratings[i] > 10) {
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
        sum += ratings[i];
    }
    double average = static_cast<double>(sum) / GROUP_SIZE;
    
    // Find highest and lowest
    int highest = ratings[0];
    int lowest = ratings[0];
    for(int i = 1; i < GROUP_SIZE; i++) {
        if(ratings[i] > highest) {
            highest = ratings[i];
        }
        if(ratings[i] < lowest) {
            lowest = ratings[i];
        }
    }
    
    // Display results
    std::cout << "\n=== Results ===" << std::endl;
    std::cout << "Average rating: " << average << std::endl;
    std::cout << "Highest rating: " << highest << std::endl;
    std::cout << "Lowest rating: " << lowest << std::endl;
    
    // Recommendation
    if(average >= 7) {
        std::cout << "Consensus: Great movie!" << std::endl;
    } else if(average >= 5) {
        std::cout << "Consensus: It was okay." << std::endl;
    } else {
        std::cout << "Consensus: Pick a different movie next time!" << std::endl;
    }
   
    // Release ratings array
    delete[] ratings;
    ratings = nullptr;
 
    return 0;
}
