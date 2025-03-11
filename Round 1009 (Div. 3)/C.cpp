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

pair<int,bool> count_bits(unsigned int n) {
  int res=0;
  bool all_ones=true;
  while (n>0) {
    if ((n&1)==0) all_ones=false;
    n=n>>1;
    res++;
  }
  return {res,all_ones};
};

void solve() {
  ll n;
  cin>>n;
  if (n<=4) {
    cout<<-1<<"\n";
    return;
  }
  unsigned int bin = (unsigned int)n;
  if ((bin&(bin-1))==0) {
    cout<<-1<<"\n";
    return;
  }
  pair<int,bool> bits=count_bits(bin);
  int res=(1<<(bits.first-1))-1;
  if (bits.second) {
    cout<<-1<<"\n";
    return;
  }
  cout<<res<<"\n";
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