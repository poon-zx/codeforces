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
  // 3 apart = 7
  // 2 apart = 5
  // 1 apart = 3
  vector<int> v(1001,0);
  int n;
  cin>>n;
  for (int i=0;i<n;i++) {
    int t;
    cin>>t;
    v[t]++;
  }
  for (int i=0;i<v.size();i++) {
    if (v[i]==1) {
      cout<<"No\n";
      return;
    } else if (i==v.size()-1&&v[i]%2==0) {
      break;
    } else if (v[i]>2) {
      int diff=v[i]-2;
      v[i]=2;
      v[i+1]+=diff;
    }
  }
  cout<<"Yes\n";
}
// lowest to highest
// 1 bail
// 2 keep
// 3 add 1 to next
// 4 add 2 to next

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