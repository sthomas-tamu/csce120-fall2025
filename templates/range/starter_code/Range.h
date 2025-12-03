#ifndef _RANGE_H
#define _RANGE_H

template <typename T>
class Range {
  private:
    //TODO: add data to keep track of the min and max value added to the range, include a flag that records if the range is empty or not

  public:
    //TODO: create a default constructor that initializes your data

    void add(T value) {
      //TODO: update the range's min and/or max if value is outside the current range
    }

    T getMin() const { 
      //TODO: return the min of the range; throw an exception if the range hasn't had any values added to it yet
    }

    T getMax() const { 
      //TODO: return the max of the range; throw an exception if the range hasn't had any values added to it yet
    }

    T getRange() const { 
      //TODO: return the absolute value of the max minus the min; throw an exception if the range hasn't had any values added to it yet
    }

    bool empty() const {
      //TODO: return true if the range hasn't had any values added to it yet, false otherwise
    }
};

#endif
