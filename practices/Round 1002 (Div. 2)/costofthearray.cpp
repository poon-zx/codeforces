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

using i64 = long long;

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
  vector<int> v;
  for (int i=0;i<n;i++) {
    int a;
    cin>>a;
    v.push_back(a);
  }
  int count=1;
  if (n==k) {
    for (int i=1;i<n;i+=2) {
      if (v[i]!=count) {
        cout<<count<<"\n";
        return;
      }
      count++;
    }
    cout<<count<<"\n";
  } else {
    int diff=n-k+1;
    for (int i=1;i<=diff;i++) {
      if (v[i]!=1) {
        cout<<1<<"\n";
        return;
      }
    }
    cout<<2<<"\n";
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