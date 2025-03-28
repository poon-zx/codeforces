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
  int64_t l,r;
  cin>>n>>l>>r;
  vector<int> a(n+1);
  for (int i=1;i<=n;i++) {
    cin>>a[i];
  }
  vector<int> pref(n+1);
  for (int i=1;i<=n;i++) {
    pref[i]=pref[i-1]+a[i];
  }
  if (n%2==0) {
    n++;
    int cur=pref[n/2]&1;
    a.push_back(cur);
    pref.push_back(pref.back()+cur);
  }
  for (int i=n+1;i<=n*2;i++) {
    a.push_back(pref[i/2]&1);
    pref.push_back(pref[i-1]+a[i]);
  }
  int p=pref[n]&1;
  auto get=[&](int64_t x) {
    int ret=0;
    while (true) {
      if (x<=n*2) {
        ret^=a[x];
        break;
      }
      ret^=p;
      if ((x/2-n)%2==0) break;
      x/=2;
    }
    return ret;
  };
  cout<<get(l)<<"\n";
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