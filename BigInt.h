#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

namespace ds
{
  class BigInt
  {
  public:
    BigInt() = default;
    explicit BigInt(std::string str);
    // Since we are not managing dynamic memory, we don't need the rule of three!
    void output() { std::cout << *this << std::endl;}
    // BONUS: TODO: Implement the * operator
    BigInt operator+(const BigInt& other) const 
    {
      BigInt result;
      BigInt::add(*this, other, result);
      return result;
    }
    BigInt operator-(const BigInt& other) const 
    {
      BigInt result;
      if (*this >= other)
      {
        BigInt::subtract(*this, other, result);
      }
      else
      {
        BigInt::subtract(other, *this, result);
      }
      return result;
    }
    // While this function strictly isn't required, it is helpful for `-` operator
    bool operator>=(const BigInt& other) const;
    // This operator is used in testing / implementing output
    friend std::ostream& operator<<(std::ostream& os, const BigInt& d)
    {
      // TODO: Implement this
    }
  private:
    // Add and Subtract are private as they are internal implementation details
    void add(const BigInt& a, const BigInt& b, BigInt& result) const;
    void subtract(const BigInt& a, const BigInt& b, BigInt& result) const;
    std::vector<int> digits;
  };

}

ds::BigInt::BigInt(std::string str)
{
  // TODO: Implement this
  // HINT: Can you use std::transform?
}

void ds::BigInt::add(const BigInt& a, const BigInt& b, BigInt& result) const
{
  // TODO: Implement this
}

/**
  * @brief Subtract two BigInts
  * @param a the first BigInt
  * @param b the second BigInt
  * @param result the result of the subtraction
  *
  * @pre a >= b
  */
void ds::BigInt::subtract(const BigInt& a, const BigInt& b, BigInt& result) const
{
  // TODO: Implement this 
}

// Needed to implement absolute difference
bool ds::BigInt::operator>=(const BigInt& other) const
{
  // TODO: Implement this
}
