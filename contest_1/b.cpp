#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

const int cPrecision = 10;

int main() {
  int n;
  int q;
  int l;
  int r;
  std::cin >> n;

  std::vector<long double> a(n);
  std::vector<long double> preffix(n + 1);
  preffix[0] = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    preffix[i + 1] = preffix[i] + std::log(a[i]);
  }

  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> l >> r;
    long double pre_answer = (preffix[r + 1] - preffix[l]) / (r - l + 1);
    std::cout << std::fixed << std::setprecision(cPrecision)
              << std::exp(pre_answer) << "\n";
  }
  return 0;
}