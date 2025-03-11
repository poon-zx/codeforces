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
  int n,st,en;
  cin>>n>>st>>en;
  vector adj(n + 1, vector<int> ());
  for (int i=1;i<n;i++) {
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector dis(n+1, vector<int>());
  vector<int> d(n+1);
  auto dfs = [&](auto &&self, int v, int par) -> void {
    d[v]=d[par]+1;
    dis[d[v]].push_back(v);
    for (int u:adj[v]) {
      if (u==par) continue;
      self(self,u,v);
    }
  };
  dfs(dfs,en,0);
  for (int i=n;i>=1;i--) {
    for (int j:dis[i]) {
      cout<<j<<" ";
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