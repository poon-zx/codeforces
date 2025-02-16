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
  vector<ll> v(n);
  for (int i=0;i<n;i++) {
    cin>>v[i];
  }
  vector<ll> prefix(n);
  vector<ll> suffix(n);
  ll sum=0;
  for (int i=0;i<n;i++) {
    if (v[i]>0) {
      sum+=v[i];
    }
    prefix[i]=sum;
  }
  sum=0;
  for (int i=n-1;i>=0;i--) {
    if (v[i]<0) {
      sum+=abs(v[i]);
    }
    suffix[i]=sum;
  }
  ll res=0;
  for (int i=0;i<n;i++) {
    res=max(res,prefix[i]+suffix[i]);
  }
  cout<<res<<"\n";


  /*
  int l=0,r=n-1;
  int res=0;
  while (l<n&&r>=0) {
    while (l<=n&&(v[l]==0||v[l]<0)) {
      l++;
    }
    while (r>=-1&&(v[r]==0||v[r]>0)) {
      r--;
    }
    
    if (l==n) {
      res+=abs(v[r]);
      v[r]=0;
      r--;
    } else if (r==-1) {
      res+=abs(v[l]);
      v[l]=0;
      l++;
    } else {
      if (abs(v[r])>abs(v[l])) {
        res+=abs(v[r]);
        v[r]=0;
        r--;
      } else {
        res+=abs(v[l]);
        v[l]=0;
        l++;
      }
    }
  }
  cout<<res<<"\n";
  */
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