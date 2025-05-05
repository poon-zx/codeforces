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
  string a,b;
  cin>>a>>b;
  int a_pt=0,b_pt=0;
  while(a_pt<a.size()) {
    char curr=a[a_pt];
    int cnt=0;
    while (a_pt<a.size()&&a[a_pt]==curr) {cnt++;a_pt++;}
    if(b_pt==b.size()) {cout<<"NO"<<"\n";return;}
    if(b[b_pt]!=curr) {cout<<"NO"<<"\n";return;}
    int cnt_b=0;
    while(b_pt<b.size()&&b[b_pt]==curr) {cnt_b++;b_pt++;}
    if(cnt_b<cnt||cnt_b>cnt*2) {cout<<"NO"<<"\n";return;}
  }
  if(b_pt!=b.size()) {cout<<"NO"<<"\n";return;}
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