#include "Player.h"

// constructors
Player::Player() : name(""), jerseyNumber(0), position("") {
}

Player::Player(std::string _name, unsigned int _jerseyNumber, std::string _position)
    : name(_name), jerseyNumber(_jerseyNumber), position(_position) {
}

// destructor
Player::~Player() {}

// member functions
void Player::print(std::ostream& _os) const {
    _os << name << "\t" << jerseyNumber << "\t" << position;
}

