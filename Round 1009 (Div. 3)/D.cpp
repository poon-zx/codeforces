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
  int n,m;
  cin>>n>>m;
  vector<ll> circles(n);
  vector<ll> radi(n);
  for (int i=0;i<n;i++) {
    cin>>circles[i];
  }
  for (int i=0;i<n;i++) {
    cin>>radi[i];
  }
  unordered_map<ll,ll> map;
  for (int i=0;i<circles.size();i++) {
    ll start_x=circles[i]-radi[i];
    ll end_x=circles[i]+radi[i];
    ll mid=circles[i];
    bool flip=false;
    for (ll j=start_x;j<=end_x;j++) {
      ll start=2*(ll)(sqrt(pow(radi[i],2)-pow(j-mid,2)))+1;
      if (map.find(j)==map.end()) {
        map[j]=start;
      } else {
        map[j]=max(map[j],start);
      }
    }
  }
  ll res=0;
  for (auto &it:map) {
    res+=(ll)it.second;
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