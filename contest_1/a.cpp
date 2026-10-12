#include <iostream>
#include <vector>

int Min(int a, int b) {
  if (a > b) {
    return b;
  }
  return a;
}

int main() {
  int n;
  int q;
  int l;
  int r;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<int> suffix(n);
  std::vector<int> preffix(n);

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  suffix[0] = a[0];
  preffix[0] = a[n - 1];
  for (int i = 1; i < n; i++) {
    if (a[i] < suffix[i - 1]) {
      suffix[i] = a[i];
    } else {
      suffix[i] = suffix[i - 1];
    }
    if (a[n - i - 1] < preffix[i - 1]) {
      preffix[i] = a[n - i - 1];
    } else {
      preffix[i] = preffix[i - 1];
    }
  }

  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> l >> r;
    std::cout << Min(suffix[l - 1], preffix[n - r]) << "\n";
  }

  return 0;
}