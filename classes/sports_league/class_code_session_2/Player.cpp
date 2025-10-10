#include "Player.h"

// constructors
Player::Player() : name(""), jerseyNumber(0), position("") {
}

Player::Player(std::string _name, unsigned int _jerseyNumber, std::string _position)
    : name(_name), jerseyNumber(_jerseyNumber), position(_position) {
}

// destructor
Player::~Player() {}

//getter and setter methods
std::string Player::getName() const {
    return name;
}

void Player::setName(std::string newName) {
    name = newName;
}

unsigned int Player::getJerseyNumber() const {
    return jerseyNumber;
}

void Player::setJerseyNumber(unsigned int newJerseyNumber) {
    //only allow odd jersey numbers
    if(newJerseyNumber % 2 == 0) { //even, printing error message but could throw exception
        std::cout << "Error! only odd jersey numbers allowed, not updated." << std::endl;
    } else {
        jerseyNumber = newJerseyNumber;
    }
}

std::string Player::getPosition() const {
    return position;
}

void Player::setPosition(std::string newPosition) {
    position = newPosition;
}


// member functions
void Player::print(std::ostream& _os) const {
    _os << name << "\t" << jerseyNumber << "\t" << position;
}

