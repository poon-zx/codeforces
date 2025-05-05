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
  ll n,k,x;
  cin>>n>>k>>x;
  vector<ll> v;
  ll summ=0;
    for (int j=0;j<n;j++) {
      ll t;
      cin>>t;
      summ+=t;
      v.push_back(t);
    }
  ll l=0;
  ll r=n*k;
  ll res=0;
  if (k*summ<x) {
    cout<<0<<"\n";
    return;
  }
  while (l<=r) {
    ll mid=l+(r-l)/2;
    ll diff=n*k-mid;
    ll total=diff/n*summ;
    for (int i=0;i<diff%n;i++) {
      total+=v[n-i-1];
    }
    if (total<x) {
      r=mid-1;
    } else {
      res=max(res,mid);
      l=mid+1;
    }
  }
  cout<<res+1<<"\n";
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