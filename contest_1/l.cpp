#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  std::string t;
  std::cin >> s >> t;

  const int cN = static_cast<int>(s.size());
  std::vector<int> removal_step(cN);
  for (int step = 0; step < cN; ++step) {
    int position;
    std::cin >> position;
    removal_step[position - 1] = step;
  }

  auto contains_t_after = [&](int deletions) {
    int matched = 0;
    for (int i = 0; i < cN && matched < static_cast<int>(t.size()); ++i) {
      if (removal_step[i] >= deletions && s[i] == t[matched]) {
        ++matched;
      }
    }
    return matched == static_cast<int>(t.size());
  };

  int left = 0;
  int right = cN;
  while (left < right) {
    const int cMiddle = left + ((right - left + 1) / 2);
    if (contains_t_after(cMiddle)) {
      left = cMiddle;
    } else {
      right = cMiddle - 1;
    }
  }

  std::cout << left << '\n';
}
