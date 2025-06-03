#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <ios>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

using ld = long double;

constexpr int MOD = 1'000'000'007;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  //
  int n, m;
  std::cin >> n >> m;

  std::vector<int> rooms(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> rooms[i];
  }

  std::ranges::sort(rooms);
  std::span<int> smallestN{rooms.begin(), rooms.begin() + n};
  std::span<int> biggestN{rooms.end() - n, rooms.end()};

  // std::array<std::span<int>, 2> sorted{{smallestN, biggestN}};

  for (int i = 0; i < n; ++i) {
    int idx = i / 2;
    for (int j = 0; j < 6; ++j) {
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          std::cout << smallestN[idx];
        } else {
          std::cout << biggestN[n - 1 - idx];
        }
      } else {
        if (j % 2 == 0) {
          std::cout << biggestN[n - 1 - idx];
        } else {
          std::cout << smallestN[idx];
        }
      }
      std::cout << ' ';
    }
    std::cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin>>tc;
  while (tc--) {
    solve();
  }

  return 0;
}