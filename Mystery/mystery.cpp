#include <iostream>
#include <vector>

int mystery(const std::vector<int>& numbers) {
  int something = 0;
  for (int number : numbers) {
    something += number;
  }
  return something;
}

int main() {
  std::vector<int> numbers = {1, 2, 4, 8, 16};
  std::cout << "Mystery function result is " << mystery(numbers) << "\n";
}
