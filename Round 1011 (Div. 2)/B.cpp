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
  //vector<int> v(n);
  vector<int> zeros;
  for (int i=0;i<n;i++) {
    int t;
    cin>>t;
    if (t==0) zeros.push_back(i+1);
  }
  if (zeros.empty()) cout<<1<<"\n"<<1<<" "<<n<<"\n";
  else {
    if (zeros[0]==1&&zeros[zeros.size()-1]==n) {
      cout<<3<<"\n";
      cout<<1<<" "<<2<<"\n";
      cout<<2<<" "<<n-1<<"\n";
      cout<<1<<" "<<2<<"\n";
    } else if (zeros[0]==1) {
      cout<<2<<"\n";
      cout<<1<<" "<<n-1<<"\n";
      cout<<1<<" "<<2<<"\n";
    }
    else {
      cout<<2<<"\n";
      cout<<2<<" "<<n<<"\n";
      cout<<1<<" "<<2<<"\n";
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