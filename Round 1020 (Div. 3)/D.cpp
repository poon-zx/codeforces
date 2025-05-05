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
  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  vector<int> b(m);
  for (int i=0;i<n;i++) cin>>a[i];
  for (int i=0;i<m;i++) {
    cin>>b[i];
  }
  vector<int> backwards(m);
  int j=n-1;
  for (int i=m-1;i>=0;i--) {
    while(j>=0&&a[j]<b[i]) j--;
    backwards[i]=j--;
  }
  vector<int> forwards(m);
  j=0;
  for (int i=0;i<m;i++) {
    while(j<n&&a[j]<b[i]) j++;
    forwards[i]=j++;
  }
  if(forwards.back()<n) {
    cout<<0<<endl;
    return;
  }
  int ans=MOD;
  for(int i=0;i<m;i++) {
    int match_prev=i==0?-1:forwards[i-1];
    int match_next=i+1==m?n:backwards[i+1];
    if(match_next>match_prev) ans=min(ans,b[i]);
  }
  cout<<(ans==MOD?-1:ans)<<"\n";
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