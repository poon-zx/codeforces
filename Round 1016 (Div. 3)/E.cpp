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
  int n,k;
  cin>>n>>k;
  vector<ll> v(n);
  ll maxx=0;
  for (int i=0;i<n;i++) {
    cin>>v[i];
    maxx=max(maxx,v[i]);
  }
  ll l=0;
  ll r=maxx+1;
  ll res=0;
  while (l<=r) {
    ll m=l+(r-l)/2;
    int curr=1;
    unordered_set<ll> set;
    for (int i=0;i<n;i++) {
      set.insert(v[i]);
      bool found=true;
      for (ll j=0;j<m;j++) {
        if (set.find(j)==set.end()) {
          found=false;
          break;
        }
      }
      if (found) {
        curr++;
        set.clear();
      }
    }
    if (curr>k) {
      res=max(res,m);
      l=m+1;
    } else r=m-1;
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