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

ll MAX=1'000'000'000'000'000'000;

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
  string s;
  cin>>s;
  vector<ll> v(n);
  vector<int> zeros;
  for(int i=0;i<n;i++) cin>>v[i];
  ll max_sum=0;
  ll curr=0;
  ll cnt_forget=0;
  vector<pair<ll,ll>> pairs;
  for(int i=0;i<n;i++) {
    if(s[i]=='0') {zeros.push_back(i);cnt_forget++;curr=0;continue;}
    curr=max(0LL,curr);
    curr+=v[i];
    max_sum=max(curr,max_sum);
  }
  if(max_sum>k||(max_sum!=k&&cnt_forget==0)) cout<<"No"<<"\n";
  else if(cnt_forget==0) {
    cout<<"Yes"<<"\n";
    for(auto &num:v) cout<<num<<" ";
    cout<<"\n";
  } else if(cnt_forget==n) {
    cout<<"Yes"<<"\n";
    cout<<k<<" ";
    for(int i=0;i<n-1;i++) cout<<-1LL*MAX<<" ";
    cout<<"\n";
  } else {
    for(int i=0;i<zeros.size();i++) {
      if(zeros[i]==0&&s[1]=='0') continue;
      else if (s[zeros[i]-1]=='0'&&s[zeros[i]+1]=='0') continue;
      int curr=zeros[i];
      ll best_left=0,sum=0;
      for(int p=curr-1;p>=0&&s[p]=='1';p--) {
        sum+=v[p];
        best_left=max(best_left,sum);
      }
      ll best_right=0;
      sum=0;
      for(int p=curr+1;p<n&&s[p]=='1';p++) {
        sum+=v[p];
        best_right=max(best_right,sum);
      }
      v[curr]=k-best_left-best_right;
      for(auto &num:zeros) {
          if(num!=curr) v[num]=-MAX;
      }
      break;
    }
    cout<<"Yes"<<"\n";
    for(auto& num:v) cout<<num<<" ";
    cout<<"\n";
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