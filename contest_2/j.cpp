#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::array<int, 3>> AssignDogs(
    const std::vector<std::pair<int, int>>& sheep,
    const std::vector<std::pair<int, int>>& dogs) {
  int n = static_cast<int>(dogs.size());
  int limit = n / 2;
  int i = 0;
  int j = n - limit;
  std::vector<std::array<int, 3>> ans;

  for (const std::pair<int, int>& sheep_item : sheep) {
    if (i == limit || j == n) {
      break;
    }
    if (dogs[i].first >= sheep_item.first) {
      continue;
    }
    while (j < n && dogs[j].first <= sheep_item.first) {
      ++j;
    }
    if (j == n) {
      break;
    }

    ans.push_back({sheep_item.second, dogs[i].second, dogs[j].second});
    ++i;
    ++j;
  }
  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int m = 0;
  int n = 0;
  std::cin >> m >> n;
  std::vector<std::pair<int, int>> sheep(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> sheep[i].first;
    sheep[i].second = i + 1;
  }

  std::vector<std::pair<int, int>> dogs(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> dogs[i].first;
    dogs[i].second = i + 1;
  }
  std::sort(sheep.begin(), sheep.end());
  std::sort(dogs.begin(), dogs.end());
  std::vector<std::array<int, 3>> ans = AssignDogs(sheep, dogs);

  std::cout << ans.size() << '\n';
  for (const std::array<int, 3>& triple : ans) {
    std::cout << triple[0] << ' ' << triple[1] << ' ' << triple[2] << '\n';
  }
  return 0;
}
