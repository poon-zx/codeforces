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
  ll n;
  cin>>n;
  vector<ll> tot(2*n);
  unordered_set<ll> set;
  for (ll i=0;i<2*n;i++) {
    cin>>tot[i];
    set.insert(tot[i]);
  }
  sort(tot.begin(),tot.end());
  ll odd=0;
  ll even=0;
  vector<ll> odd_a;
  vector<ll> even_a;
  for (ll i=1;i<=2*n;i++) {
    ll num=tot[i-1];
    if (i<n) {
      odd+=num;
      odd_a.push_back(num);
    } else {
      even+=num;
      even_a.push_back(num);
    }
  }
  ll diff=even-odd;
  odd_a.push_back(diff);
  for (int i=0;i<odd_a.size();i++) {
    cout<<even_a[i]<<" ";
    cout<<odd_a[i]<<" ";
  }
  cout<<even_a[even_a.size()-1]<<"\n";
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