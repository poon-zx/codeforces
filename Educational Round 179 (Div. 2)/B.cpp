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
  int n,m;
  cin>>n>>m;
  vector<vector<int>> boxes(m,vector<int>(3));
  for(int i=0;i<m;i++) cin>>boxes[i][0]>>boxes[i][1]>>boxes[i][2];
  vector<int> fib={1,2};
  for(int i=2;i<n;i++) {
    fib.push_back(fib[i-2]+fib[i-1]);
  }
  for(auto &v:boxes) {
    sort(v.begin(),v.end());
    if(v[0]>=fib[n-1]&&v[2]>=fib[n-1]+fib[n-2]) cout<<'1';
    else cout<<'0';
  }
  cout<<endl;
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