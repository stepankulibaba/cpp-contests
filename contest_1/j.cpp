#include <iostream>
#include <vector>

int main() {
  int n;
  int d;
  std::cin >> n >> d;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  long long cnt = 0;
  int r = 1;
  bool finished = false;
  for (int l = 0; l < n; l++) {
    while (a[r] - a[l] <= d) {
      if (r == n - 1) {
        finished = true;
        break;
      }
      r++;
    }
    if (finished) {
      break;
    }
    cnt += n - r;
  }
  std::cout << cnt;
  return 0;
}