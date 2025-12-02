#ifndef _PAIR_H_
#define _PAIR_H_

#include <iostream>

class Pair {
  private:
    int first;
    int second;

  public:
    Pair(int a, int b) : first(a), second(b) {}

    int getFirst() const { return first; }
    int getSecond() const { return second; }

    void print(std::ostream& os) const {
        os << "(" << first << ", " << second << ")";
    }

    bool operator<(const Pair& p) {
        if(first == p.first) {
            return second < p.getSecond();
        } else {
            return first < p.getFirst();
        }
    }
};

#endif
