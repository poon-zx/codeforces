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
  vector<ll> a(n);
  for (int i=0;i<n;i++) {
    cin>>a[i];
  }
  ll l1=0,r1=0; // current block
  ll l2=2000000000,r2=-2000000000; // prev block if have
  ll pr=0;
  ll mnl=0,mxl=0;
  ll mnr=2000000000,mxr=-2000000000;
  for (int i=0;i<n;i++) {
    pr+=a[i];
    if (a[i]!=1&&a[i]!=-1) {
      mnr=mnl;
      mxr=mxl;
      mnl=pr;
      mxl=pr;
    }
    l1=min(l1,pr-mxl);
    r1=max(r1,pr-mnl);
    l2=min(l2,pr-mxr);
    r2=max(r2,pr-mnr);
    mnl=min(mnl,pr);
    mxl=max(mxl,pr);
  }
  vector<ll> res;
  if (l2>r1) {
    for (ll x=l1;x<=r1;x++) {
      res.push_back(x);
    }
    for (ll x=l2;x<=r2;x++) {
      res.push_back(x);
    }
  } else if (r2<l1) {
    for (ll x=l2;x<=r2;x++) {
      res.push_back(x);
    }
    for (ll x=l1;x<=r1;x++) {
      res.push_back(x);
    }
  } else {
    ll L=min(l1,l2);
    ll R=max(r1,r2);
    for (ll x=L;x<=R;x++) {
      res.push_back(x);
    }
  }
  cout<<res.size()<<"\n";
  for (auto x:res) {
    cout<<x<<" ";
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