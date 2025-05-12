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
  vector<vector<int>> res(n,vector<int>(n));
  int curr=0;
  if(n==1) {cout<<0<<"\n";return;}
  int middle=(n-1)/2;
  for(int i=middle;i<middle+2;i++) {
    for(int j=middle;j<middle+2;j++) {
      res[i][j]=curr;
      curr++;
    }
  }
  if(n==2) {
    for(int i=0;i<2;i++) {
      for(int j=0;j<2;j++) {
        cout<<res[i][j]<<" ";
      }
      cout<<"\n";
    }
    return;
  }
  int left=middle,right=middle+1;
  int top=middle,bottom=middle+1;
  int cnt=2;
  while(cnt!=n) {
    if(cnt%2==0) {
      int l=middle,r=middle+1;
      for(int j=0;j<cnt;j++) {
        if(j%2==0) {res[top-1][l]=curr;l--;}
        else {res[top-1][r]=curr;r++;}
        curr++;
      }
      l=middle,r=middle+1;
      for(int i=0;i<cnt+1;i++) {
        if(i%2==0) {res[l][left-1]=curr;l--;}
        else {res[r][left-1]=curr;r++;}
        curr++;
      }
      left--;
      top--;
    } else {
      int l=middle,r=middle+1;
      for(int i=0;i<cnt;i++) {
        if(i%2==0) {res[l][right+1]=curr;l--;}
        else {res[r][right+1]=curr;r++;}
        curr++;
      }
      l=middle,r=middle+1;
      for(int j=0;j<cnt+1;j++) {
        if(j%2==0) {res[bottom+1][l]=curr;l--;}
        else {res[bottom+1][r]=curr;r++;}
        curr++;
      }
      bottom++;
      right++;
    }
    cnt++;
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout<<res[i][j]<<" ";
    }
    cout<<"\n";
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