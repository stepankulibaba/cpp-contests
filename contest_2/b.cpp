#include <iostream>
#include <vector>

const int cMod = 10004321;
const int cPrev = 123;
const int cEarlier = 45;

void SwapValues(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}

void InsertionSort(std::vector<int>& a, int l, int r) {
  for (int i = l + 1; i < r; ++i) {
    int pos = i;
    while (pos > l && a[pos - 1] > a[pos]) {
      SwapValues(a[pos - 1], a[pos]);
      --pos;
    }
  }
}

int SelectKth(std::vector<int>& a, int l, int r, int k) {
  while (r - l > 5) {
    int medians = 0;
    for (int group = l; group < r; group += 5) {
      int last = std::min(group + 5, r);
      InsertionSort(a, group, last);
      int mid = group + ((last - group) / 2);
      SwapValues(a[l + medians], a[mid]);
      ++medians;
    }

    int median_pos = l + (medians / 2);
    int pivot = SelectKth(a, l, l + medians, median_pos);

    int left = l;
    int pos = l;
    int right = r;

    while (pos < right) {
      if (a[pos] < pivot) {
        SwapValues(a[pos], a[left]);
        ++left;
        ++pos;
      } else if (a[pos] > pivot) {
        --right;
        SwapValues(a[pos], a[right]);
      } else {
        ++pos;
      }
    }

    if (k < left) {
      r = left;
    } else if (k >= right) {
      l = right;
    } else {
      return pivot;
    }
  }

  InsertionSort(a, l, r);
  return a[k];
}

std::vector<int> GenerateArray(int n, int x, int y) {
  std::vector<int> a(n);
  a[0] = x;
  if (n > 1) {
    a[1] = y;
  }

  for (int i = 2; i < n; ++i) {
    long long next = (1LL * a[i - 1] * cPrev) + (1LL * a[i - 2] * cEarlier);
    a[i] = static_cast<int>(next % cMod);
  }

  return a;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  int k = 0;
  int x = 0;
  int y = 0;
  std::cin >> n >> k >> x >> y;

  std::vector<int> a = GenerateArray(n, x, y);
  std::cout << SelectKth(a, 0, n, k - 1) << '\n';

  return 0;
}
