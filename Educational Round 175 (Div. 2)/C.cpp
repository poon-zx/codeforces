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

int possible(vector<ll> v, ll minn, string s) {
  char last='R';
  int count=0;
  for (int i=0;i<s.size();i++) {
    if (v[i]>minn) {
      if (s[i]=='B'&&last!='B') {
        count++;
      }
      last=s[i];
    }
  }
  return count;
};

void solve() {
  int n,k;
  cin>>n>>k;
  cin.ignore();
  string s;
  getline(cin,s);
  vector<ll> v(n);
  ll minn=0;
  ll maxx=1000000000;
  for (int i=0;i<n;i++) {
    cin>>v[i];
  }
  ll res=numeric_limits<ll>::max();
  while (minn<=maxx) {
    ll m=minn+(maxx-minn)/2;
    if (possible(v,m,s)>k) {
      minn=m+1;
    } else {
      maxx=m-1;
      res=min(res,m);
    }
  }
  cout<<res<<"\n";

  
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