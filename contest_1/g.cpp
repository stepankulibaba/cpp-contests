#include <iostream>
#include <vector>

int main() {
  int n;
  int m;
  int k;
  int l;
  int r;
  int b;
  int d;

  std::cin >> n >> m;
  std::vector<long long> delta_2(n + 2, 0);
  std::vector<long long> preffix(n + 1, 0);
  for (int i = 0; i < m; i++) {
    std::cin >> l >> r >> b >> d;
    delta_2[l - 1] += b;
    delta_2[l] += d - b;
    delta_2[r] -= (b + (d * (r - l)) + d);
    delta_2[r + 1] += b + (d * (r - l));
  }
  for (int j = 0; j < 2; j++) {
    for (int i = 1; i < n; i++) {
      delta_2[i] += delta_2[i - 1];
    }
  }
  for (int i = 1; i < n + 1; i++) {
    preffix[i] = delta_2[i - 1] + preffix[i - 1];
  }

  std::cin >> k;
  for (int i = 0; i < k; i++) {
    std::cin >> l >> r;
    std::cout << preffix[r] - preffix[l - 1] << "\n";
  }
  return 0;
}