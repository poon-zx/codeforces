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
  map<int,vector<int>> m;
  for (int i=0;i<n;i++) {
    int a;
    cin>>a;
    m[a].push_back(i);
  }
  vector<bool> pressed(n+2,false);
  ll res=0;
  for (auto iter=m.rbegin();iter!=m.rend();iter++) {
    int k=iter->first;
    vector<int> v=iter->second;
    ll forward=0,backward=0;
    int i=0;
    while (i<v.size()) {
      int j=i;
      while (j<v.size()-1&&v[j+1]==v[j]+1) j++;
      if (!pressed[v[i]]&&!pressed[v[j]+2]) res++;
      i=j+1;
    }
    //cout<<k<<" "<<res<<" ";
    for (auto &num:v) pressed[num+1]=true;
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