#ifndef _PAIR_H_
#define _PAIR_H_

#include <iostream>

template <typename T, typename U = T>
class Pair {
  private:
    T first;
    U second;

  public:
    Pair(T a, U b) : first(a), second(b) {}

    T getFirst() const { return first; }
    U getSecond() const { return second; }

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
