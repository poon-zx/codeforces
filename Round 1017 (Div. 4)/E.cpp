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
  vector<ll> cnt(30,0);
  vector<ll> v(n);
  for (int i=0;i<n;i++) {
    cin>>v[i];
    for (int j=0;j<30;j++) {
      cnt[j]+=((v[i]>>j)&1);
    }
  }
  ll res=0;
  for (int i=0;i<n;i++) {
    ll curr=0;
    for (int j=0;j<30;j++) {
      bool t=((v[i]>>j)&1);
      if(t) curr+=(1<<j)*(n-cnt[j]);
      else curr+=(1<<j)*cnt[j];
    }
    res=max(curr,res);
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