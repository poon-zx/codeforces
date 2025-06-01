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

vector<ll> res;

void solve(vector<ll> &weights, vector<vector<int>> &adj,int v,int p,ll mini,ll maxi) {
  res[v]=max(weights[v],-1LL*mini+weights[v]);
  mini=min(weights[v],maxi*-1LL+weights[v]);
  for(int u:adj[v]) {
    if(u==p) continue;
    solve(weights,adj,u,v,mini,res[v]);
  }
}

void solve() {
  int n;
  cin>>n;
  vector<ll> weights(n+1);
  for(int i=1;i<=n;i++) cin>>weights[i];
  vector<vector<int>> adj(n+1,vector<int>());
  for(int i=0;i<n-1;i++) {
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  res.resize(n+1,0);
  solve(weights,adj,1,-1,0,0);
  for(int i=1;i<=n;i++) cout<<res[i]<<" ";
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