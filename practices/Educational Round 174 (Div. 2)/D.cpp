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
  string s;
  cin>>s;
  int i=0;
  int n=s.size();
  while (i<n/2&&s[i]==s[n-i-1]) {
    i++;
  }
  n-=2*i;
  s=s.substr(i,n);
  int ans=n;
  for (int z=0;z<2;z++) { // check both prefix and suffix
    int l=0,r=n;
    while (l<=r) {
      int m=(l+r)/2;
      vector<int> cnt(26);
      for (int i=0;i<m;i++) {
        cnt[s[i]-'a']++;
      }
      bool ok=true;
      for (int i=0;i<min(n/2,n-m);i++) {
        char c=s[n-i-1];
        if (i<m) {
          ok&=cnt[c-'a']>0;
          cnt[c-'a']--;
        } else {
          ok&=(c==s[i]);
        }
      }
      for (auto x:cnt) {ok&=(x%2==0);}
      if (ok) {r=m-1;}
      else {l=m+1;}
    }
    ans=min(ans,r+1);
    reverse(s.begin(),s.end());
  }
  cout<<ans<<"\n";
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