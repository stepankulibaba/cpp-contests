#include <iostream>
#include <utility>
#include <vector>

void Merge(std::vector<std::pair<int, int>>& a,
           std::vector<std::pair<int, int>>& buffer, std::vector<int>& ans,
           int l, int mid, int r) {
  int i = l;
  int j = mid;

  for (int pos = l; pos < r; ++pos) {
    if (i < mid && (j == r || a[i].first <= a[j].first)) {
      ans[a[i].second] += j - mid;
      buffer[pos] = a[i];
      ++i;
    } else {
      buffer[pos] = a[j];
      ++j;
    }
  }

  for (int pos = l; pos < r; ++pos) {
    a[pos] = buffer[pos];
  }
}

void CountInversions(std::vector<std::pair<int, int>>& a,
                     std::vector<std::pair<int, int>>& buffer,
                     std::vector<int>& ans, int l, int r) {
  if (r - l <= 1) {
    return;
  }

  int mid = l + ((r - l) / 2);
  CountInversions(a, buffer, ans, l, mid);
  CountInversions(a, buffer, ans, mid, r);
  Merge(a, buffer, ans, l, mid, r);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n);
  for (int pos = 0; pos < n; ++pos) {
    std::cin >> a[pos].first;
    a[pos].second = pos;
  }

  std::vector<std::pair<int, int>> buffer(n);
  std::vector<int> ans(n, 0);
  CountInversions(a, buffer, ans, 0, n);

  for (int x : ans) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  return 0;
}
