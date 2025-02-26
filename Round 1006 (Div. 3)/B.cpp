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
  pair<ll,ll> p;
  for (int i=0;i<n;i++) {
    char c;
    cin>>c;
    if (c=='-') {p.first++;}
    else {p.second++;}
  }
  if (n<3) {
    cout<<0<<"\n";
    return;
  }
  if (p.first<2||p.second<1) {
    cout<<0<<"\n";
    return;
  }
  ll res=0;
  if (p.first%2==0) {
    ll half=p.first/2;
    res=half*half*p.second;
  } else {
    ll half=p.first/2;
    ll half1=half+1;
    res=p.second*half*half1;
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