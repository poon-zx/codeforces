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
  vector<char> v1(n);
  vector<char> v2(n);
  for (int i=0;i<n;i++) cin>>v1[i];
  for (int i=0;i<n;i++) cin>>v2[i];
  int odds=0,evens=0;
    for (int i=0;i<n;i+=2) {
        if (v1[i]=='0') odds++;
        if (v2[i]=='0') evens++;
    }
    for (int i=1;i<n;i+=2) {
        if (v2[i]=='0') odds++;
        if (v1[i]=='0') evens++;
    }
  if (n%2==0) {
    cout<<((odds>=n/2&&evens>=n/2)?"YES":"NO")<<"\n";
  } else cout<<((odds>=(n/2+1)&&evens>=n/2)?"YES":"NO")<<"\n";
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