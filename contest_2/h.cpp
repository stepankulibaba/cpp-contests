#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

const int cByteBits = 8;

std::uint32_t NextRand24(std::uint32_t& cur, std::uint32_t a, std::uint32_t b) {
  cur = (cur * a) + b;
  return cur >> cByteBits;
}

std::vector<std::uint32_t> GeneratePoints(int n, std::uint32_t a,
                                          std::uint32_t b) {
  std::vector<std::uint32_t> points(n);
  std::uint32_t cur = 0;
  for (std::uint32_t& point : points) {
    std::uint32_t x = NextRand24(cur, a, b);
    std::uint32_t y = NextRand24(cur, a, b);
    point = (x << cByteBits) ^ y;
  }
  return points;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  std::uint32_t a = 0;
  std::uint32_t b = 0;
  std::cin >> n >> a >> b;

  std::vector<std::uint32_t> points = GeneratePoints(n, a, b);
  int mid = n / 2;
  std::nth_element(points.begin(), points.begin() + mid, points.end());
  long long median = points[mid];

  long long sum = 0;
  for (std::uint32_t point : points) {
    long long dist = static_cast<long long>(point) - median;
    if (dist < 0) {
      dist = -dist;
    }
    sum += dist;
  }

  std::cout << sum << '\n';
  return 0;
}
