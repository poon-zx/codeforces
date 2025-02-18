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
  // save strangers in same set
  int r,c;
  cin>>r>>c;
  vector<vector<int>> v(r,vector<int>(c));
  unordered_map<int,pair<unordered_set<int>,unordered_set<int>>> counter;
  for (int i=0;i<r;i++) {
    for (int j=0;j<c;j++) {
      cin>>v[i][j];
    }
  }
  for (int i=0;i<r;i++) {
    for (int j=0;j<c;j++) {
      int num=i*c+j+1;
      if (counter.find(v[i][j])==counter.end()) {
        unordered_set<int> temp;
        unordered_set<int> temp1;
        counter[v[i][j]]={temp,temp1};
      }
      if ((num%c==1||counter[v[i][j]].first.find(num-1)==counter[v[i][j]].first.end())&&((num-1)/c==0||counter[v[i][j]].first.find(num-c)==counter[v[i][j]].first.end())) {
        counter[v[i][j]].first.insert(num);
      } else {
        counter[v[i][j]].second.insert(num);
    }
    }
  }
  bool doub=false;
  int res=-1;
  for (auto& it:counter) {
    pair<unordered_set<int>,unordered_set<int>> te=it.second;
    if (!te.first.empty()&&!te.second.empty()&&!doub) {
      res++;
      doub=true;
    } else {
      if (!te.first.empty()) {res++;}
      if (!te.second.empty()) {res++;}
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