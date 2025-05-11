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
  vector<vector<int>> adjList(n+1);
  for(int i=0;i<n-1;i++) {
    int a,b;
    cin>>a>>b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  vector<vector<int>> res;
  vector<bool> used(n+1,false);
  vector<bool> seen(n+1,false);
  vector<int> p(n+1,-1);
  while(true) {
    if(count(used.begin()+1,used.end(),false)==0) break;
    seen.assign(n+1,false);
    auto dfs=[&](auto self,int u,int parent)->pair<int,int> {
      pair<int,int> curr={1,u}; // dist,furthest node
      p[u]=parent;
      seen[u]=true;
      for(auto &v:adjList[u]) {
        if(!used[v]&&v!=parent) {
          auto nxt=self(self,v,u);
          nxt.first++;
          curr=max(curr,nxt);
        }
      }
      return curr;
    };
    for(int i=1;i<=n;i++) {
      if(!used[i]&&!seen[i]) {
        auto [dist1,j]=dfs(dfs,i,-1);
        auto [dist2,k]=dfs(dfs,j,-1);
        res.push_back({dist2,max(j,k),min(j,k)});
        while(k!=-1) {
          used[k]=true;
          k=p[k];
        }
      }
    }
  }
  sort(res.rbegin(),res.rend());
  for(auto &x:res) cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" ";
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