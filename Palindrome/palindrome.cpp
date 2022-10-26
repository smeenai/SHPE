#include <algorithm>
#include <iostream>
#include <string>

std::string reverseString(std::string str) {
  std::reverse(str.begin(), str.end());
  return str;
}

bool isPalindrome(const std::string& str) {
  return false;
}

bool isPalindromeWithoutSpaces(const std::string& str) {
  return false;
}

int main() {
  std::string str1 = "a man a plan a canal panama";
  std::string str2 = "amanaplanacanalpanama";

  if (isPalindrome(str1)) {
    std::cout << str1 << " is a palindrome\n";
  } else {
    std::cout << str1 << " is not a palindrome\n";
  }

  if (isPalindrome(str2)) {
    std::cout << str2 << " is a palindrome\n";
  } else {
    std::cout << str2 << " is not a palindrome\n";
  }

  if (isPalindromeWithoutSpaces(str1)) {
    std::cout << str1 << " is a palindrome when spaces are removed\n";
  } else {
    std::cout << str1 << " is not a palindrome when spaces are removed\n";
  }
}
