#include <cstdint>
#include <iostream>
#include <limits>

const std::int64_t cMaxTime = std::numeric_limits<std::int64_t>::max();

bool IsEnough(std::int64_t seconds, std::int64_t x, std::int64_t k,
              std::int64_t m, std::int64_t a, std::int64_t b) {
  if (x == 0) {
    return true;
  }

  std::int64_t first_days = seconds - (seconds / k);
  std::int64_t second_days = seconds - (seconds / m);
  std::int64_t first = 0;
  if (a > 0) {
    if (first_days > (x - 1) / a) {
      return true;
    }
    first = a * first_days;
  }
  return b > 0 && second_days > (x - first - 1) / b;
}

int main() {
  std::int64_t a;
  std::int64_t b;
  std::int64_t k;
  std::int64_t m;
  std::int64_t x;

  std::cin >> a >> k >> b >> m >> x;
  std::int64_t l = 0;
  std::int64_t r = cMaxTime;

  while (l < r) {
    std::int64_t mid = l + ((r - l) / 2);
    if (IsEnough(mid, x, k, m, a, b)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  std::cout << l << '\n';
  return 0;
}
