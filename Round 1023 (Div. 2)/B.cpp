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
  ll k;
  cin>>n>>k;
  vector<ll> v(n);
  ll minn=numeric_limits<ll>::max();
  ll maxx=0;
  ll maxx_cnt=0;
  ll summ=0;
  for(int i=0;i<n;i++) {
    cin>>v[i];
    minn=min(minn,v[i]);
    if(v[i]>maxx) {maxx=v[i];maxx_cnt=1;}
    else if(v[i]==maxx) maxx_cnt++;
    summ+=v[i];
  }
  if(maxx-minn-1>k||(maxx-minn-1==k&&maxx_cnt>1)) cout<<"Jerry"<<"\n";
  else {
    if(summ%2==1) cout<<"Tom"<<"\n";
    else cout<<"Jerry"<<"\n";
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