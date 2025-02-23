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
  int j=0;
  for (int i=0;i<n;i++) {
    cin>>v[i];
  }
  for (int i=0;i<n-1;i++) {
    if (v[i]>v[i+1]) {
      j=i+1;
    }
  }
  if (j==0) {
    cout<<"YES"<<"\n";
    return;
  }
  for (int i=0;i<j;i++) {
    ll minn=min(v[i],v[i+1]);
    v[i]-=minn;
    v[i+1]-=minn;
  }
  if (is_sorted(v.begin(),v.end())) {
    cout<<"YES"<<"\n";
  } else {
    cout<<"NO"<<"\n";
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