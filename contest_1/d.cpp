#include <cmath>
#include <iomanip>
#include <iostream>

long double F(int a, int b, int c, int d, double value) {
  return (a * value * value * value) + (b * value * value) + (c * value) + d;
}

int main() {
  int a;
  int b;
  int c;
  int d;

  std::cin >> a >> b >> c >> d;

  const long double cInitValue = 1001.0;
  const int cSteps = 2000;
  const int cPrecision = 10;

  long double l = -cInitValue;
  long double r = cInitValue;
  long double mid;
  for (int i = 0; i <= cSteps; i++) {
    mid = (l + r) / 2;
    long double value_mid = F(a, b, c, d, mid);
    if (F(a, b, c, d, l) * value_mid > 0) {
      l = mid;
    } else {
      r = mid;
    }
  }

  std::cout << std::fixed << std::setprecision(cPrecision) << mid;

  return 0;
}