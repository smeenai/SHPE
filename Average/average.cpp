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
  // ANSWER: average is sum / number of elements, and we can call computeSum to
  // get the sum. int / int gives you int in C++ (it rounds down to the nearest
  // integer), so we need to cast to a double to get decimals.
  return static_cast<double>(computeSum(numbers)) / numbers.size();
}

int main() {
  std::vector<int> numbers = { 3, 4, 5, 6 };
  std::cout << "Average of numbers is " << computeAverage(numbers) << "\n";
}
