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
  int x;
  cin>>n>>x;
  int curr=0;
  vector<int> v(n,x);
  bool flag=true;
  for (int i=0;i<n-1;i++) {
    if (((curr|i)&x)==(curr|i)) {
      v[i]=i;
      curr|=i;
    } else {
      flag=false;
      break;
    }
  }
  if (flag&&(curr|(n-1))==x) {
    v[n-1]=n-1;
  }
  for (auto j:v) {
    cout<<j<<" ";
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