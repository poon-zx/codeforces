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
  int n,x;
  ll k;
  cin>>n>>x>>k;
  cin.ignore();
  string s;
  getline(cin,s);
  int moves_to_zero=0;
  int x_copy=x;
  int zero_res=0,back_to_zero=0;
  int saved_zero=numeric_limits<int>::max();
  for (char c:s) {
    if (c=='L') {
      x_copy--;
    }
    else {
      x_copy++;
    }
    moves_to_zero++;
    k--;
    if (x_copy==0||k==0) {break;}
  }
  for (char c:s) {
    if (c=='L') {
      zero_res--;
    }
    else {
      zero_res++;
    }
    back_to_zero++;
    if (zero_res==0) {
      saved_zero=back_to_zero;
      break;
    }
  }
  //cout<<k<<" "<<saved_zero<<" ";
  if (x_copy!=0) {
    cout<<0<<"\n";
    return;
  }
  if (saved_zero==numeric_limits<int>::max()) {
    cout<<1<<"\n";
  } else {
    cout<<1+k/saved_zero<<"\n";
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