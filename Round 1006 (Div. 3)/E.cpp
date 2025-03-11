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

vector<pair<ll,ll>> rec(ll k,ll x0,ll y0) {
  if (!k) {
    return {};
  }
  ll delta=0;
  while (delta*(delta-1)/2<=k) {
    delta++;
  }
  delta--;
  auto remaining=rec(k-delta*(delta-1)/2,x0+delta+1,y0+1);
  vector<pair<ll,ll>> ans;
  for (int x=x0;x<x0+delta;x++) {
    ans.push_back({x,y0});
  }
  ans.insert(ans.end(),remaining.begin(),remaining.end());
  return ans;
}

void solve() {
  ll k;
  cin>>k;
  if (k==0) {
    cout<<"1\n2 3\n";
    return;
  }
  auto ans=rec(k,0,0);
  cout<<ans.size()<<"\n";
  for (auto [x,y]:ans) {
    cout<<x<<" "<<y<<"\n";
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