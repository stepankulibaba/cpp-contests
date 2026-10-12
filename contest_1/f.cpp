#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int k;
  int new_value;
  std::cin >> k;

  for (int i = 1; i < n; i++) {
    std::cin >> new_value;
    k = k ^ new_value;
  }
  std::cout << k;
  return 0;
}