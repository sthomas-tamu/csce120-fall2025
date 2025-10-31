#ifndef _DIGIT_H_
#define _DIGIT_H_

//define characters for on and off bulbs
static const char OFF = ' ';
static const char ON = '#';

//set digit height
static const int DIGIT_HEIGHT = 7;
static const int DIGIT_WIDTH = 4;

//set on/off pattern for each digit
static const char digits[10][DIGIT_HEIGHT][DIGIT_WIDTH] = 
  {
    { //0 
      { ON,  ON,  ON,  ON},
      { ON, OFF, OFF,  ON},
      { ON, OFF, OFF,  ON},
      { ON, OFF, OFF,  ON},
      { ON, OFF, OFF,  ON},
      { ON, OFF, OFF,  ON},
      { ON,  ON,  ON,  ON} 
    },
    { //1
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON} 
    },
    { //2
      { ON,  ON,  ON,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      { ON,  ON,  ON,  ON},
      { ON, OFF, OFF, OFF},
      { ON, OFF, OFF, OFF},
      { ON,  ON,  ON,  ON} 
    },
    { //3
      { ON,  ON,  ON,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      { ON,  ON,  ON,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      { ON,  ON,  ON,  ON} 
    },
    { //4
      { ON, OFF, OFF,  ON},
      { ON, OFF, OFF,  ON},
      { ON, OFF, OFF,  ON},
      { ON,  ON,  ON,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON} 
    },
    { //5 
      { ON,  ON,  ON,  ON},
      { ON, OFF, OFF, OFF},
      { ON, OFF, OFF, OFF},
      { ON,  ON,  ON,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      { ON,  ON,  ON,  ON} 
    },
    { //6 
      { ON,  ON,  ON,  ON},
      { ON, OFF, OFF, OFF},
      { ON, OFF, OFF, OFF},
      { ON,  ON,  ON,  ON},
      { ON, OFF, OFF,  ON},
      { ON, OFF, OFF,  ON},
      { ON,  ON,  ON,  ON} 
    },
    { //7
      { ON,  ON,  ON,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON} 
    },
    { //8 
      { ON,  ON,  ON,  ON},
      { ON, OFF, OFF,  ON},
      { ON, OFF, OFF,  ON},
      { ON,  ON,  ON,  ON},
      { ON, OFF, OFF,  ON},
      { ON, OFF, OFF,  ON},
      { ON,  ON,  ON,  ON} 
    },
    { //9
      { ON,  ON,  ON,  ON},
      { ON, OFF, OFF,  ON},
      { ON, OFF, OFF,  ON},
      { ON,  ON,  ON,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON},
      {OFF, OFF, OFF,  ON} 
    }
  };

//the fractional 9/10 cent
static const char remainder_cents[DIGIT_HEIGHT][3] = 
  {
    { ON,  ON,  ON},
    { ON, OFF,  ON},
    { ON,  ON,  ON},
    {OFF, OFF,  ON},
    {OFF, OFF,  ON},
    {OFF, OFF, OFF},
    {OFF, OFF, OFF}
  };

#endif
