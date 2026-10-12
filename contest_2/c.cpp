#include <algorithm>
#include <iostream>
#include <vector>

bool CanCover(const std::vector<long long>& points, int k, long long len) {
  int used = 0;
  long long finish = 0;

  for (long long point : points) {
    if (used == 0 || point > finish) {
      ++used;
      if (used > k) {
        return false;
      }
      finish = point + len;
    }
  }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  int k = 0;
  std::cin >> n >> k;

  std::vector<long long> points(n);
  for (long long& point : points) {
    std::cin >> point;
  }
  std::sort(points.begin(), points.end());

  long long l = 0;
  long long r = points.back() - points.front();
  while (l < r) {
    long long mid = l + ((r - l) / 2);
    if (CanCover(points, k, mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  std::cout << l << '\n';
  return 0;
}
