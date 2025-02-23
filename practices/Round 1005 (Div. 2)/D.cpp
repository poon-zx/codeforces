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
  int n,q;
  cin>>n>>q;
  vector<int> a(n);
  for (int i=0;i<n;i++) {
    cin>>a[i];
  }
  vector<int> pre(n+1);
  pre[0]=a[0];
  for (int i=1;i<n;i++) {
    pre[i]=pre[i-1]^a[i];
  }
  vector<array<int,30>> last(n);
  for (int i=0;i<n;i++) {
    fill(last[i].begin(),last[i].end(),0);
    if (i>0) {last[i]=last[i-1];}
    last[i][__lg(a[i])]=i;
    for (int j=30-2;j>=0;j--) {
      last[i][j]=max(last[i][j],last[i][j+1]);
    }
  }
  while (q--) {
    int x;
    cin>>x;
    int idx=n-1;
    while (idx>=0&&x>0) {
      int msb=__lg(x);
      int nxt=last[idx][msb];
      x^=pre[idx]^pre[nxt];
      idx=nxt;
      if (nxt==-1||a[nxt]>x) {break;}
      x^=a[nxt];
      idx--;
    }
    cout<<n-idx-1<<" ";
  }
  cout<<"\n";
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