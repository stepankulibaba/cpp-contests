#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  int m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  std::vector<int> b(m);

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  int min_dist;
  int l;
  int r;
  int last_value;
  bool color_is_red;
  if (a[0] < b[0]) {
    l = 1;
    r = 0;
    last_value = a[0];
    min_dist = b[0] - a[0];
    color_is_red = true;
  } else {
    l = 0;
    r = 1;
    last_value = b[0];
    min_dist = a[0] - b[0];
    color_is_red = false;
  }

  while ((l < n) and (r < m)) {
    if (a[l] < b[r]) {
      if ((not color_is_red) and (min_dist > a[l] - last_value)) {
        min_dist = a[l] - last_value;
      }
      color_is_red = true;
      last_value = a[l];
      l++;
    } else {
      if (color_is_red and (min_dist > b[r] - last_value)) {
        min_dist = b[r] - last_value;
      }
      color_is_red = false;
      last_value = b[r];
      r++;
    }
  }
  if (l == n) {
    min_dist = std::min(b[r] - last_value, min_dist);
  } else {
    min_dist = std::min(a[l] - last_value, min_dist);
  }
  std::cout << min_dist;
  return 0;
}