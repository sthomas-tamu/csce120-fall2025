#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <string>

class Player {
  private: //default is private so not needed, but adding to be explicit/clear
    // define the data members
    std::string name;
    unsigned int jerseyNumber;
    std::string position;

  public: 
    // constructors
    Player(); // default constructor, no input parameters
    Player(std::string _name, unsigned int _jerseyNumber, std::string _position);

    // destructor
    ~Player();

    //getter and setter methods
    std::string getName() const;
    void setName(std::string newName);

    unsigned int getJerseyNumber() const;
    void setJerseyNumber(unsigned int newJerseyNumber);

    std::string getPosition() const;
    void setPosition(std::string newPosition);

    // function that prints to any ostream, set to const to prevent side-effects
    void print(std::ostream& _os) const;
};

#endif
