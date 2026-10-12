#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

std::vector<int> BuildOrder(const std::vector<int>& a,
                            const std::vector<int>& b) {
  std::vector<std::pair<int, int>> early;
  std::vector<std::pair<int, int>> late;
  int n = static_cast<int>(a.size());

  for (int i = 0; i < n; ++i) {
    if (a[i] <= b[i]) {
      early.emplace_back(a[i], i);
    } else {
      late.emplace_back(b[i], i);
    }
  }
  std::sort(early.begin(), early.end());
  std::sort(late.rbegin(), late.rend());

  std::vector<int> order;
  for (const std::pair<int, int>& work : early) {
    order.push_back(work.second);
  }
  for (const std::pair<int, int>& work : late) {
    order.push_back(work.second);
  }
  return order;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<int> b(n);
  for (int& time : a) {
    std::cin >> time;
  }
  for (int& time : b) {
    std::cin >> time;
  }

  std::vector<int> order = BuildOrder(a, b);
  long long t1 = 0;
  long long t2 = 0;
  for (int i : order) {
    t1 += a[i];
    t2 = std::max(t2, t1) + b[i];
  }

  std::cout << t2 << '\n';
  for (int i : order) {
    std::cout << i + 1 << ' ';
  }
  std::cout << '\n';
  for (int i : order) {
    std::cout << i + 1 << ' ';
  }
  std::cout << '\n';
  return 0;
}
