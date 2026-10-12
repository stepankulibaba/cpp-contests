#include <iostream>
#include <vector>

long long Merge(std::vector<int>& a, std::vector<int>& buffer, int l, int mid,
                int r) {
  int i = l;
  int j = mid;
  long long ans = 0;

  for (int pos = l; pos < r; ++pos) {
    if (i < mid && (j == r || a[i] <= a[j])) {
      buffer[pos] = a[i];
      ++i;
    } else {
      buffer[pos] = a[j];
      ++j;
      ans += mid - i;
    }
  }

  for (int pos = l; pos < r; ++pos) {
    a[pos] = buffer[pos];
  }
  return ans;
}

long long CountInversions(std::vector<int>& a, std::vector<int>& buffer, int l,
                          int r) {
  if (r - l <= 1) {
    return 0;
  }

  int mid = l + ((r - l) / 2);
  long long ans = CountInversions(a, buffer, l, mid);
  ans += CountInversions(a, buffer, mid, r);
  ans += Merge(a, buffer, l, mid, r);
  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  std::cin >> n;
  std::vector<int> a(n);
  for (int& value : a) {
    std::cin >> value;
  }

  std::vector<int> buffer(n);
  std::cout << CountInversions(a, buffer, 0, n) << '\n';
  return 0;
}
