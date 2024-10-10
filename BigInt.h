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
      
      
      return os;
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
  digits.reserve(str.size());
  std::transform(str.rbegin(), str.rend(), std::back_inserter(digits), [](char ch) {
  return ch-'0';
  });
}

void ds::BigInt::add(const BigInt& a, const BigInt& b, BigInt& result) const
{
  // TODO: Implement this
    int carry = 0;
    size_t maxSize = std::max(a.digits.size(), b.digits.size());

    for (size_t i = 0; i < maxSize || carry; ++i){
      int d1 = (i < a.digits.size()) ? a.digits[i] : 0;
      int d2 = (i < b.digits.size()) ? b.digits[i] : 0;
    
      int sum = d1 + d2 + carry;
      result.digits.push_back(sum % 10);
      carry = sum / 10;
    }
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
  int borrow = 0;

  for (size_t i = 0; i < a.digits.size(); ++i){
    int d1 = a.digits[i];
    int d2 = (i < b.digits.size()) ? b.digits[i] : 0;

    int diff = d1 - d2 - borrow;
    if (diff < 0){
      diff += 10;
      borrow = 1;
    }
    else{
      borrow = 0;
    }
    result.digits.push_back(diff);
  }

  // Remove leading zeros in the result
  while (result.digits.size() > 1 && result.digits.back() == 0){
    result.digits.pop_back();
  }
}

// Needed to implement absolute difference
bool ds::BigInt::operator>=(const BigInt& other) const
{
  // TODO: Implement 
  if (digits.size() != other.digits.size()){
    return digits.size() > other.digits.size();
  }

  // Compare from most significant to least significant
  for (int i = digits.size() - 1; i >= 0; --i){
    if (digits[i] != other.digits[i]){
      return digits[i] > other.digits[i];
    }
  }

  return true;  // They are equal
}
