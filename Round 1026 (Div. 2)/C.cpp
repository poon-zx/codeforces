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
  vector<int> d(n);
  for(auto &x:d) cin>>x;
  vector<int> l(n),r(n);
  for(int i=0;i<n;i++) cin>>l[i]>>r[i];
  int left=0;
  vector<int> last;
  for(int i=0;i<n;i++) {
    if(d[i]==-1) last.push_back(i);
    else left+=d[i];
    while(left<l[i]) {
      if(last.empty()) {cout<<-1<<endl;return;}
      d[last.back()]=1;
      left++;
      last.pop_back();
    }
    while(left+last.size()>r[i]) {
      if(last.empty()) {cout<<-1<<endl;return;}
      d[last.back()]=0;
      last.pop_back();
    }
  }
  for(auto &x:d) cout<<max(0,x)<<" ";
  cout<<endl;
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