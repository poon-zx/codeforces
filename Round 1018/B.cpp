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
  vector<pair<ll,ll>> l(n,pair<ll,ll>());
  for (int i=0;i<n;i++) cin>>l[i].first;
  for (int i=0;i<n;i++) cin>>l[i].second;
  ll res=0;
  vector<ll> minss(n);
  for (int i=0;i<n;i++) {
    res+=max(l[i].first,l[i].second);
    minss[i]=min(l[i].first,l[i].second);
  }
  sort(minss.begin(),minss.end(),greater<ll>());
  for (int i=0;i<k-1;i++) res+=minss[i];
  res+=1;
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