#include <algorithm>
#include <cmath>
#include <iostream>

const long long cRightBound = 2 * 1'000'000'000'000'000'000;
const long long cMaxSqrt = 2'000'000'000'000;

int FindFloorSqrt(long long n) {
  long long l = 1;
  long long r = std::min(n, cMaxSqrt);
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    if (mid <= n / mid) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}
bool Ok(long long x, long long k) { return k <= x - FindFloorSqrt(x); }

long long FindAnswer(long long k) {
  long long right = cRightBound;
  long long left = k;
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (Ok(mid, k)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  if ((left - FindFloorSqrt(left)) == k) {
    return left;
  }
  return right;
}

int main() {
  int t;
  long long k;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> k;
    std::cout << FindAnswer(k) << "\n";
  }
  return 0;
}
