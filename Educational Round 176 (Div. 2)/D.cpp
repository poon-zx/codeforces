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
const int B = 60;
const ll INF = 1e18;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<vector<ll>> dp(B,vector<ll>(B,INF));
  dp[0][0]=0;
  for (int x=0;x<B;x++) {
    for (int i=B-1;i>=0;i--) {
      for (int j=B-1;j>=0;j--) {
        if (dp[i][j]==INF) continue;
        if (i+x<B) dp[i+x][j]=min(dp[i+x][j],dp[i][j]+(1LL<<x));
        if (j+x<B) dp[i][j+x]=min(dp[i][j+x],dp[i][j]+(1LL<<x));
      }
    }
  }

  int tc;
  cin>>tc;
  while (tc--) {
    ll x,y;
    cin>>x>>y;
    ll ans=INF;
    for (int i=0;i<B;i++) {
      for (int j=0;j<B;j++) {
        if ((x>>i)==(y>>j)) ans=min(ans, dp[i][j]);
      }
    }
    cout<<ans<<"\n";
  }

  return 0;
}