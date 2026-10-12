#include <cstdint>
#include <iostream>
#include <vector>

const int cBytes = 8;
const int cBits = 8;
const int cBase = 256;
const std::uint64_t cMask = 255;

void RadixSort(std::vector<std::uint64_t>& a) {
  std::vector<std::uint64_t> buffer(a.size());

  for (int byte = 0; byte < cBytes; ++byte) {
    int shift = byte * cBits;
    std::vector<int> pos(cBase, 0);
    for (std::uint64_t x : a) {
      ++pos[(x >> shift) & cMask];
    }

    int offset = 0;
    for (int& p : pos) {
      int n = p;
      p = offset;
      offset += n;
    }

    for (std::uint64_t x : a) {
      int digit = static_cast<int>((x >> shift) & cMask);
      buffer[pos[digit]] = x;
      ++pos[digit];
    }
    a.swap(buffer);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  std::cin >> n;
  std::vector<std::uint64_t> a(n);
  for (std::uint64_t& x : a) {
    std::cin >> x;
  }

  RadixSort(a);
  for (std::uint64_t x : a) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  return 0;
}
