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
  string base="LIT";
  int n;
  string s;
  cin>>n>>s;
  if (count(s.begin(),s.end(),s[0])==n) cout<<-1<<"\n";
  else {
    vector<int> ans;
    while(true) {
      vector<pair<int,char>> cnt;
      for (auto i:base) {
        cnt.push_back(make_pair(count(s.begin(),s.end(),i),i));
      }
      sort(cnt.begin(),cnt.end());
      if (cnt[0].first==cnt[1].first&&cnt[1].first==cnt[2].first) break;

      auto op=[&] (int i)-> void {
        string z=base;
        z.erase(find(z.begin(),z.end(),s[i]));
        z.erase(find(z.begin(),z.end(),s[i+1]));
        ans.push_back(i);
        s=s.substr(0,i+1)+z[0]+s.substr(i+1);
      };

      bool done=false;
      for (int i=0;i<s.size()-1;i++) {
        if (s[i]==s[i+1]) continue;
        if (s[i]!=cnt[0].second&&s[i+1]!=cnt[0].second) {
          op(i);
          done=true;
          break;
        }
      }
      if (done) continue;
      for (int i=0;i<s.size()-1;i++) {
        if (s[i]==s[i+1]) continue;
        if (s[i]==cnt[2].second) {
          op(i);
          op(i+1);
          op(i);
          op(i+2);
          break;
        } else if (s[i+1]==cnt[2].second) {
          op(i);
          op(i);
          op(i+1);
          op(i+3);
          break;
        }
      }
    }
    cout<<ans.size()<<'\n';
    for (auto i:ans) cout<<i+1<<'\n';
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