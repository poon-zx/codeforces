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
  vector<ll> v(n);
  ll minn=numeric_limits<ll>::max();
  int counter=1;
  for (int i=0;i<n;i++) {
    cin>>v[i];
    if (v[i]<minn) {
      minn=v[i];
      counter=1;
    } else if (v[i]==minn) counter++;
  }
  if (counter>=2) {
    cout<<"Yes"<<"\n";
    return;
  }
  unordered_set<ll> set;
  for (int i=0;i<n;i++) {
    if (v[i]!=minn&&v[i]%minn==0) set.insert(v[i]);
  }
  if (set.size()<=1) {
    cout<<"No"<<"\n";
    return;
  }
  ll res;
  for (const auto& elem:set) {
    res=elem;
    break;
  }
  for (const auto& elem:set) {
    res=gcd(res,elem);
  }
  if (res==minn) cout<<"Yes"<<"\n";
  else cout<<"No"<<"\n";
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