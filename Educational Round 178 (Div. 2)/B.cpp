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
  vector<ll> v(n);
  for (int i=0;i<n;i++) cin>>v[i];
  vector<ll> suff(n),pref(n);
  suff[n-1]=v[n-1];
  for (int i=n-2;i>=0;i--) {
    suff[i]=v[i]+suff[i+1];
  }
  pref[0]=v[0];
  for (int i=1;i<n;i++) {
    pref[i]=max(pref[i-1],v[i]);
  }
  for (int i=n-1;i>=0;i--) {
    if(i==n-1) cout<<pref[i]<<" ";
    else {
      cout<<max(suff[i],suff[i+1]+pref[i])<<" ";
    }
  }
  cout<<"\n";
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