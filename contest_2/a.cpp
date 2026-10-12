#include <iostream>
#include <vector>

void Merge(std::vector<std::pair<int, int>>& segments,
           std::vector<std::pair<int, int>>& buffer, int l, int mid, int r) {
  int i = l;
  int j = mid;
  int pos = l;

  while (i < mid && j < r) {
    if (segments[i].first <= segments[j].first) {
      buffer[pos] = segments[i];
      ++i;
    } else {
      buffer[pos] = segments[j];
      ++j;
    }
    ++pos;
  }

  while (i < mid) {
    buffer[pos] = segments[i];
    ++i;
    ++pos;
  }

  while (j < r) {
    buffer[pos] = segments[j];
    ++j;
    ++pos;
  }

  for (int i = l; i < r; ++i) {
    segments[i] = buffer[i];
  }
}

void MergeSort(std::vector<std::pair<int, int>>& segments,
               std::vector<std::pair<int, int>>& buffer, int l, int r) {
  if (r - l <= 1) {
    return;
  }

  int mid = l + ((r - l) / 2);
  MergeSort(segments, buffer, l, mid);
  MergeSort(segments, buffer, mid, r);
  Merge(segments, buffer, l, mid, r);
}

std::vector<std::pair<int, int>> UniteIntervals(
    const std::vector<std::pair<int, int>>& segments) {
  std::vector<std::pair<int, int>> ans;

  for (const std::pair<int, int>& segment : segments) {
    if (ans.empty() || segment.first > ans.back().second) {
      ans.push_back(segment);
    } else if (segment.second > ans.back().second) {
      ans.back().second = segment.second;
    }
  }

  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  std::cin >> n;
  std::vector<std::pair<int, int>> segments(n);
  for (std::pair<int, int>& segment : segments) {
    std::cin >> segment.first >> segment.second;
  }

  std::vector<std::pair<int, int>> buffer(n);
  MergeSort(segments, buffer, 0, n);
  std::vector<std::pair<int, int>> ans = UniteIntervals(segments);

  std::cout << ans.size() << '\n';
  for (const std::pair<int, int>& segment : ans) {
    std::cout << segment.first << ' ' << segment.second << '\n';
  }

  return 0;
}
