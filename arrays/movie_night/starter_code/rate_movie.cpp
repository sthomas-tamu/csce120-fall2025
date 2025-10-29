#include <iostream>
#include <sstream>

int main() {
    std::cout << "=== Movie Night Rating System ===" << std::endl;
    std::cout << "Rate our movie from 1-10" << std::endl << std::endl;

    // TODO 2: Revise to handle any size group, not just 5, still using c-style arrays

    // TODO Challenge: Revise to also report the name of the person who gave the highest and lowest rating

    // Create ratings array
    const int GROUP_SIZE = 5;
    int ratings[GROUP_SIZE];

    // Collect ratings
    try {
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
    
    //TODO 1: compute and print highest and lowest rating

    // Display results
    std::cout << "\n=== Results ===" << std::endl;
    std::cout << "Average rating: " << average << std::endl;
    
    // Recommendation
    if(average >= 7) {
        std::cout << "Consensus: Great movie!" << std::endl;
    } else if(average >= 5) {
        std::cout << "Consensus: It was okay." << std::endl;
    } else {
        std::cout << "Consensus: Pick a different movie next time!" << std::endl;
    }
   
    return 0;
}
