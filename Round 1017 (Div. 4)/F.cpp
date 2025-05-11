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
  int n,m,k;
  cin>>n>>m>>k;
  if(m%k==0) {
    for(int i=1;i<=n;i++) {
      int curr;
      if(i%2==1) curr=1;
      else curr=2;
      for(int j=1;j<=m;j++) {
        cout<<curr<<" ";
        curr++;
        if(curr>k) curr=1;
      }
      cout<<"\n";
    }
  } else {
    int curr=1;
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=m;j++) {
        cout<<curr<<" ";
        curr++;
        if(curr>k) curr=1;
      }
      cout<<"\n";
    }
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