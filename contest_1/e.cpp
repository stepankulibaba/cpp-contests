#include <iostream>
#include <vector>

int TernarySearch(int n, int x, std::vector<int>& a, std::vector<int>& b) {
  int l = 0;
  int r = n - 1;

  while (r - l > 1) {
    int first = l + ((r - l + 1) / 3);
    int second = r - ((r - l + 1) / 3);

    if (b[first] > a[second] + x) {
      l = first;
    } else {
      r = second;
    }
  }

  if (b[l] < a[r] + x) {
    return l;
  }
  return r;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  int q;
  int x;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<int> b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> x;
    std::cout << TernarySearch(n, x, a, b) + 1 << "\n";
  }
  return 0;
}