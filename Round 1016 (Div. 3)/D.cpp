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

ll number_cell(ll x, ll y, int n) {
  if (n==0) return 1;
  ll half=pow(2,n-1);
  ll quarter=pow(4,n-1);
  if (x<=half&&y<=half) {
    return number_cell(x,y,n-1);
  } else if (x>half&&y<=half) {
    return quarter*2+number_cell(x-half,y,n-1);
  } else if (x<=half&&y>half) {
    return quarter*3+number_cell(x,y-half,n-1);
  } else return quarter+number_cell(x-half,y-half,n-1);
};

pair<ll,ll> pos(ll z,int n) {
  if (n==0) return {1,1};
  ll half=pow(2,n-1);
  ll quarter=pow(4,n-1);
  ll quadrant=(z-1)/quarter;
  pair<ll,ll> position=pos((z-1)%quarter+1,n-1);
  if (quadrant==0) return position;
  else if (quadrant==1) return {position.first+half,position.second+half};
  else if (quadrant==2) return {position.first+half,position.second};
  else return {position.first,position.second+half};
}

void solve() {
  int n,q;
  cin>>n>>q;
  ll curr=1;
  ll end=pow(2,n);
  for (int i=0;i<q;i++) {
    string s;
    cin>>s;
    if (s=="->") {
      ll x,y;
      cin>>x>>y;
      cout<<number_cell(x,y,n)<<"\n";
    } else {
      ll z;
      cin>>z;
      pair<ll,ll> ans=pos(z,n);
      cout<<ans.first<<" "<<ans.second<<"\n";
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