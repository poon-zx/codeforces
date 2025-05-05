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

string s[2010];
int dp[2010][2010][2];
ll sdp[2010][2010][2];
int n,m,d;

ll getsum(int x,int y1,int y2,int f) {
  ll res=sdp[x][y2][f];
  if (y1) res-=sdp[x][y1-1][f];
  return res;
}

int get(int i,int j,int f) {
  if (s[i][j]!='X') return 0;
  ll res=0;
  if (i==n-1) res++;
  if (!f) {
    res += getsum(i,max(0,j-d),min(m-1,j+d),1);
    res-=dp[i][j][1];
  } 
  if (i<n-1) {
    res+=getsum(i+1,max(0,j-d+1),min(m-1,j+d-1),0);
  }
  return res%MOD;
}

void solve() {
  cin>>n>>m>>d;
  for (int i=0;i<n;i++) cin>>s[i];
  for (int i=n-1;i>=0;i--) {
    for (int f=1;f>=0;f--) {
      for (int j=0;j<m;j++) {
        sdp[i][j][f]=dp[i][j][f]=get(i,j,f);
      }
      for (int j=1;j<m;j++) {
        sdp[i][j][f]+=sdp[i][j-1][f];
      }
    }
  }
  ll ans=0;
  for (int j=0;j<m;j++) {
    ans+=dp[0][j][0];
  }
  cout<<ans%MOD<<"\n";
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