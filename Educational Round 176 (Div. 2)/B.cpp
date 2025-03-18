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
  int n,k;
  cin>>n>>k;
  vector<ll> v(n);
  for (int i=0;i<n;i++) cin>>v[i];
  if (k==1) {
    ll res=0;
    for (int i=0;i<n;i++) {
      if (i==0) res=max(res,v[i]+v[v.size()-1]);
      else if (i==n-1) res=max(res,v[i]+v[0]);
      else res=max(res,v[i]+max(v[0],v[v.size()-1]));
    }
    cout<<res<<"\n";
    return;
  }
  sort(v.begin(),v.end(),greater<ll>());
  ll res=0;
  for (int i=0;i<k+1;i++) {
    res+=v[i];
  }
  cout<<res<<"\n";
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