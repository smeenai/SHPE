#include <iostream>
#include <string>

std::string reverseString(std::string str) {
  // SOLUTION 1: use std::reverse.
  // str.begin() and str.end() are iterators; they allow algorithms to operate
  // over any container (e.g. std::vector also has .begin() and .end(), so you
  // can reverse a vector the same way you reverse a string).
  // `#if 0` and `#if 1` are preprocessor directives that are convenient for
  // enabling and disabling blocks of code. Change the 1 to 0 to switch to the
  // second solution.
#if 1
  std::reverse(str.begin(), str.end());
#else
  // SOLUTION 2: loop and swap corresponding characters
  // size_t is just another integer type that's conventially used for lengths
  // and sizes.
  // It can be tricky to get the `e / 2` condition right. I would test with both
  // odd and even length strings to make sure it does what you want.
  for (size_t i = 0, e = str.length(); i < e / 2; i++) {
    std::swap(str[i], str[e - 1 - i]);
  }
#endif
  return str;
}

int main() {
  std::string str = "hello world";
  std::cout << str << " backwards is " << reverseString(str) << "\n";
}
