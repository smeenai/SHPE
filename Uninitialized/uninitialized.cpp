#include <iostream>
#include <vector>

int computeSum(const std::vector<int>& numbers) {
  // Use -Wall -Werror to catch (-Wextra can be useful too)
  int sum;
  for (int number : numbers) {
    sum += number;
  }
  return sum;
}

int main() {
  std::vector<int> numbers = { 1, 2, 3, 4 };
  std::cout << "Sum of numbers is " << computeSum(numbers) << "\n";
}
