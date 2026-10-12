#include <iostream>
#include <vector>

bool BinarySearch(int b, int n, std::vector<int>& a) {
  int r = n - 1;
  int l = 0;

  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (a[mid] == b) {
      return true;
    }
    if (a[mid] > b) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return ((a[l] == b) or (a[r] == b));
}
int main() {
  int n;
  int k;
  int b;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  for (int i = 0; i < k; i++) {
    std::cin >> b;
    if (BinarySearch(b, n, a)) {
      std::cout << "YES";
    } else {
      std::cout << "NO";
    }
    std::cout << "\n";
  }

  return 0;
}