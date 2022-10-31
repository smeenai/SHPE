#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = { 0, 1, 2 };
  std::cout << "numbers[0] is " << numbers[0] << "\n";
  std::cout << "numbers[1] is " << numbers[1] << "\n";
  std::cout << "numbers[2] is " << numbers[2] << "\n";
  // ASAN, Visual Studio debug mode, or .at() instead of [] will catch this.
  std::cout << "numbers[3] is " << numbers[3] << "\n";
}
