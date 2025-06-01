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
  int n,m,a,b;
  cin>>n>>m>>a>>b;
  vector<pair<int,int>> rec={{a,m},{n-a+1,m},{n,b},{n,m-b+1}};
  int ans=n+m;
  for(auto [n1,m1]:rec) {
    int res=0;
    while(n1>1) {
      res++;
      n1=(n1+1)/2;
    }
    while(m1>1) {
      res++;
      m1=(m1+1)/2;
    }
    ans=min(ans,res);
  }
  cout<<ans+1<<"\n";
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