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
  // cannot have 1 2 spaces apart
  int n;
  cin>>n;
  vector<int> v(n-2);
  for (int i=0;i<n-2;i++) {
    cin>>v[i];
  }
  for (int i=0;i<n-2;i++) {
    if (i+2<n-2) {
      if (v[i]==1&&v[i+2]==v[i]&&v[i+1]==0) {
        cout<<"NO"<<"\n";
        return;
      }
    } 
    if (i-2>=0) {
      if (v[i]==1&&v[i-2]==v[i]&&v[i-1]==0) {
        cout<<"NO"<<"\n";
        return;
      }
    } 
  }
  cout<<"YES"<<"\n";
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