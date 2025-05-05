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
  ll k;
  cin>>n>>k;
  vector<ll> a(n);
  vector<ll> b(n);
  ll maxx=0;
  ll minn=numeric_limits<ll>::max();
  for (int i=0;i<n;i++) {
    cin>>a[i];
    maxx=max(a[i],maxx);
    minn=min(a[i],minn);
  }
  for (int i=0;i<n;i++) cin>>b[i];
  int sum=-1;
  for (int i=0;i<n;i++) {
    if (a[i]>=0&&b[i]>=0) {
      if (sum!=-1&&a[i]+b[i]!=sum) {
        cout<<0<<"\n";
        return;
      }
      sum=a[i]+b[i];
    }
  }
  if (sum==-1) {
    cout<<(minn+k)-maxx+1<<"\n";
    return;
  }
  for (int i=0;i<n;i++) {
    if (b[i]==-1) {
      if (a[i]>sum||a[i]+k<sum) {
        cout<<0<<"\n";
        return;
      }
    }
  }
  cout<<1<<"\n";
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