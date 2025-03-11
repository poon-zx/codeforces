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

constexpr int MOD = 998244353;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

int add(int x,int y) {
  x+=y;
  if (x>=MOD) {x-=MOD;}
  if (x<0) {x+=MOD;}
  return x;
};

void solve() {
  int n;
  cin>>n;
  vector<int> p(n),d(n);
  vector<vector<int>> vs(n);
  for (int v=1;v<n;v++) {
    cin>>p[v];
    --p[v];
    d[v]=d[p[v]]+1;
    vs[d[v]].push_back(v);
  }
  vector<int> dp(n),tot(n);
  dp[0]=tot[0]=1;
  for (int i=1;i<n;i++) {
    for (int v:vs[i]) {
      dp[v]=add(tot[d[v]-1],d[v]==1?0:-dp[p[v]]);
      tot[d[v]]=add(tot[d[v]],dp[v]);
    }
  }
  int ans=0;
  for (int v=0;v<n;v++) {
    ans=add(ans,dp[v]);
  }
  cout<<ans<<"\n";
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