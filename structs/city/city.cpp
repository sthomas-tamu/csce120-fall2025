#include <iostream>

struct Coordinates {
    double x = 0;
    double y = 0;
};


// define a nested struct
struct City {
    std::string name = "";
    std::string state = "";
    Coordinates location;
};

void PrintCity(City city) {
   std::cout << city.name << ", " << city.state << " located at [" << city.location.x << ", " << city.location.y << "]";
}


int main() {
    // declare a nested struct variable
    Coordinates coords({30.2672, -97.7431});
    City capital({"Austin", "TX", coords});
    
    std::cout << "The state capital is in ";
    PrintCity(capital);
    std::cout << "." << std::endl;

 
    //declare a nested struct variable all on one line
    City aggieland({"College Station", "TX", {30.601389, -96.314444}});

    std::cout << std::endl << "The best university is in ";
    PrintCity(aggieland);
    std::cout << ", WHOOP!" << std::endl;
}
