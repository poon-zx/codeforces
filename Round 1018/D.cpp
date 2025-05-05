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
  int n;
  cin>>n;
  unordered_map<int,int> cntVer, cntDiag;
  for (int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;
    cntVer[x]++;
    cntDiag[x+y]++;
  }
  int s;
  for (auto [c,cnt]:cntVer) {
    if (cnt%2==1) {
      s=c;
      break;
    }
  }
  int t;
  for (auto [c,cnt]:cntDiag) {
    if (cnt%2==1) {
      t=c-s;
      break;
    }
  }
  cout<<s<<" "<<t<<"\n";
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