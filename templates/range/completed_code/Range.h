#ifndef _RANGE_H
#define _RANGE_H

template <typename T>
class Range {
  private:
    bool hasData;
    T min, max;

  public:
    Range() : hasData{false} {}
    Range(const Range& source) : hasData{source.hasData}, min{source.min}, max{source.max} {}

    bool empty() const { return !hasData; }

    void add(T value) {
      if(!hasData) {
          hasData = true;
          min = max = value;
      } else {
          if(value < min) { min = value; }
          if(value > max) { max = value; }
      }
    }

    T getMin() const { 
        if(!hasData) { throw std::runtime_error("no data in Range"); }
        return min;
    }

    T getMax() const { 
        if(!hasData) { throw std::runtime_error("no data in Range"); }
        return max;
    }

    T getRange() const { 
        if(!hasData) { throw std::runtime_error("no data in Range"); }
        return abs(max - min);
    }
};

#endif
