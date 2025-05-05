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
  vector<vector<ll>> city(n,vector<ll>(n,0));
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin>>city[i][j];
    }
  }
  vector<ll> costA(n);
  vector<ll> costB(n);
  for (int i=0;i<n;i++) cin>>costA[i];
  for (int i=0;i<n;i++) cin>>costB[i];
  vector<vector<vector<int>>> cols(n-1,{{0,0},{0,0}});
  vector<vector<vector<int>>> rows(n-1,{{0,0},{0,0}});
  for (int i=0;i<n-1;i++) {
    for (int k=0;k<2;k++) {
      for (int q=0;q<2;q++) {
        bool done=true;
        for (int j=0;j<n;j++) {
          if (city[i][j]+k==city[i+1][j]+q) done=false;
        }
        rows[i][k][q]=done?1:0;
      }
    }
  }
  for (int j=0;j<n-1;j++) {
    for (int k=0;k<2;k++) {
      for (int q=0;q<2;q++) {
        bool done=true;
        for (int i=0;i<n;i++) {
          if (city[i][j]+k==city[i][j+1]+q) done=false;
        }
        cols[j][k][q]=done?1:0;
      }
    }
  }
  vector<vector<ll>> dp_rows(n,vector<ll>(2,numeric_limits<ll>::max()));
  dp_rows[0][0]=0;
  dp_rows[0][1]=costA[0];
  for (int i=1;i<n;i++) {
    if (rows[i-1][0][0]==1&&dp_rows[i-1][0]!=numeric_limits<ll>::max()) dp_rows[i][0]=dp_rows[i-1][0];
    if (rows[i-1][0][1]==1&&dp_rows[i-1][0]!=numeric_limits<ll>::max()) dp_rows[i][1]=min(dp_rows[i][1],dp_rows[i-1][0]+costA[i]);
    if (rows[i-1][1][0]==1&&dp_rows[i-1][1]!=numeric_limits<ll>::max()) dp_rows[i][0]=min(dp_rows[i][0],dp_rows[i-1][1]);
    if (rows[i-1][1][1]==1&&dp_rows[i-1][1]!=numeric_limits<ll>::max()) dp_rows[i][1]=min(dp_rows[i][1],dp_rows[i-1][1]+costA[i]);
  }
  vector<vector<ll>> dp_cols(n,vector<ll>(2,numeric_limits<ll>::max()));
  dp_cols[0][0]=0;
  dp_cols[0][1]=costB[0];
  for (int i=1;i<n;i++) {
    if (cols[i-1][0][0]==1&&dp_cols[i-1][0]!=numeric_limits<ll>::max()) dp_cols[i][0]=dp_cols[i-1][0];
    if (cols[i-1][0][1]==1&&dp_cols[i-1][0]!=numeric_limits<ll>::max()) dp_cols[i][1]=min(dp_cols[i][1],dp_cols[i-1][0]+costB[i]);
    if (cols[i-1][1][0]==1&&dp_cols[i-1][1]!=numeric_limits<ll>::max()) dp_cols[i][0]=min(dp_cols[i][0],dp_cols[i-1][1]);
    if (cols[i-1][1][1]==1&&dp_cols[i-1][1]!=numeric_limits<ll>::max()) dp_cols[i][1]=min(dp_cols[i][1],dp_cols[i-1][1]+costB[i]);
  }
  ll res_r=min(dp_rows[n-1][0],dp_rows[n-1][1]);
  ll res_c=min(dp_cols[n-1][0],dp_cols[n-1][1]);
  if (res_c==numeric_limits<ll>::max()||res_r==numeric_limits<ll>::max()) cout<<-1<<"\n";
  else cout<<res_r+res_c<<"\n";
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