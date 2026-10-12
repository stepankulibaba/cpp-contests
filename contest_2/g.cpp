#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void PrepareArray(std::vector<std::pair<int, int>>& a) {
  std::sort(a.begin(), a.end());

  std::vector<std::pair<int, int>> filtered;
  for (const std::pair<int, int>& item : a) {
    if (filtered.empty() || filtered.back().first != item.first) {
      filtered.push_back(item);
    }
  }
  a.swap(filtered);
}

std::pair<int, int> FindPair(const std::vector<std::pair<int, int>>& b,
                             const std::vector<std::pair<int, int>>& c,
                             long long s) {
  int i = 0;
  int j = static_cast<int>(c.size()) - 1;
  int m = static_cast<int>(b.size());
  std::pair<int, int> best = {-1, -1};

  while (i < m && j >= 0) {
    long long sum = static_cast<long long>(b[i].first) + c[j].first;
    if (sum < s) {
      ++i;
    } else if (sum > s) {
      --j;
    } else {
      std::pair<int, int> pair = {b[i].second, c[j].second};
      if (best.first == -1 || pair < best) {
        best = pair;
      }
      ++i;
      --j;
    }
  }
  return best;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long s = 0;
  std::cin >> s;
  int n = 0;
  std::cin >> n;
  std::vector<int> a(n);
  for (int& value : a) {
    std::cin >> value;
  }

  int m = 0;
  std::cin >> m;
  std::vector<std::pair<int, int>> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i].first;
    b[i].second = i;
  }

  int k = 0;
  std::cin >> k;
  std::vector<std::pair<int, int>> c(k);
  for (int i = 0; i < k; ++i) {
    std::cin >> c[i].first;
    c[i].second = i;
  }
  PrepareArray(b);
  PrepareArray(c);

  for (int i = 0; i < n; ++i) {
    std::pair<int, int> ans = FindPair(b, c, s - a[i]);
    if (ans.first != -1) {
      std::cout << i << ' ' << ans.first << ' ' << ans.second << '\n';
      return 0;
    }
  }
  std::cout << -1 << '\n';
  return 0;
}
