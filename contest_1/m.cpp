#include <iostream>
#include <vector>

int main() {
  int n;
  long long k;
  std::cin >> n >> k;

  std::vector<long long> a(n);

  long long total = 0;
  long long max_a = 0;

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    total += a[i];

    if (a[i] > max_a) {
      max_a = a[i];
    }
  }

  if (k > total) {
    std::cout << -1 << '\n';
    return 0;
  }

  if (k == 0) {
    for (int i = 0; i < n; ++i) {
      std::cout << i + 1 << ' ';
    }
    std::cout << '\n';
    return 0;
  }

  long long left = 0;
  long long right = max_a;

  while (left < right) {
    long long mid = (left + right + 1) / 2;

    long long moves = 0;

    for (int i = 0; i < n; ++i) {
      if (a[i] < mid) {
        moves += a[i];
      } else {
        moves += mid;
      }
    }

    if (moves <= k) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }

  long long rounds = left;

  long long used = 0;

  for (int i = 0; i < n; ++i) {
    if (a[i] < rounds) {
      used += a[i];
    } else {
      used += rounds;
    }
  }

  long long remaining_moves = k - used;

  std::vector<int> alive;

  for (int i = 0; i < n; ++i) {
    if (a[i] > rounds) {
      alive.push_back(i);
    }
  }

  if (alive.empty()) {
    std::cout << '\n';
    return 0;
  }

  int start = static_cast<int>(remaining_moves);

  for (int i = start; i < static_cast<int>(alive.size()); ++i) {
    std::cout << alive[i] + 1 << ' ';
  }

  for (int i = 0; i < start; ++i) {
    int child = alive[i];

    if (a[child] > rounds + 1) {
      std::cout << child + 1 << ' ';
    }
  }

  std::cout << '\n';

  return 0;
}