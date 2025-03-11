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
  vector<ll> v(2*n);
  unordered_set<ll> set;
  for (ll i=0;i<2*n;i++) {
    cin>>v[i];
    set.insert(v[i]);
  }
  sort(v.begin(),v.end());
  vector<ll> odd;
  vector<ll> even;
  bool oddbool=true;
  ll odd_sum=0,even_sum=0;
  ll first_sum=0,second_sum=0;
  for (ll i=1;i<=2*n;i++) {
    ll num=v[i-1];
    if (oddbool) {
      odd.push_back(num);
      odd_sum+=num;
    }
    else {
      even.push_back(num);
      even_sum+=num;
    }
    oddbool=!oddbool;
    if (i<=n) {
      first_sum+=num;
    } else {
      second_sum+=num;
    }
  }
  ll diff=even_sum-odd_sum;
  if (set.find(diff)!=set.end()) {
    diff=second_sum-first_sum;
    cout<<diff<<" ";
    int l=0;
    int r=v.size()-1;
    while (l<r) {
      cout<<v[r]<<" ";
      cout<<v[l]<<" ";
      l++;
      r--;
    }
    return;
  } 
  odd.push_back(diff);
  for (int i=0;i<even.size();i++) {
    cout<<odd[i]<<" ";
    cout<<even[i]<<" ";
  }
  cout<<odd[odd.size()-1]<<"\n";
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