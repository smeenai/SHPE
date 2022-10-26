#include <iostream>
#include <vector>

int computeSum(const std::vector<int>& numbers) {
  int sum = 0;
  for (int number : numbers) {
    sum += number;
  }
  return sum;
}

double computeAverage(const std::vector<int>& numbers) {
  // compute and return the average using computeSum
  // v.size() will get you the length of a vector v
  return 0;
}

int main() {
  std::vector<int> numbers = { 3, 4, 5, 6 };
  std::cout << "Average of numbers is " << computeAverage(numbers) << "\n";
}
