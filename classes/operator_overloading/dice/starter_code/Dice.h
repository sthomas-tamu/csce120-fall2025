class Dice {
  private:
    unsigned int num_sides;
    unsigned int current_value;

  public:
    Dice(unsigned int n) : num_sides(n), current_value(0) {}
    ~Dice() {}

    unsigned int getSides() const;
    unsigned int getValue() const;

    void roll();
};
