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

const int maxn=200100;

int n,a[maxn],b[maxn],m,p[maxn],ans[maxn][2];

void work(int x,int y) {
  if (x==y) return;
  ans[++m][0]=x;
	ans[m][1]=y;
	swap(a[x],a[y]);
	swap(p[a[x]],p[a[y]]);
	swap(b[x],b[y]);
}

void solve() {
  int n;
  cin>>n;
  for (int i=1;i<=n;i++) {
    cin>>a[i];
    p[a[i]]=i;
  }
  for (int i=1;i<=n;i++) cin>>b[i];
  m=0;
  int x=0;
  for (int i=1;i<=n;i++) {
    if (a[i]==b[i]) {
      if (n%2==0||x) {
        cout<<"-1\n";
        return;
      }
      x=i;
    } else if (b[p[b[i]]]!=a[i]) {
      cout<<"-1\n";
      return;
    }
  }
  if (n&1) work(x,(n+1)/2);
  for (int i=1;i<=n/2;i++) {
    work(p[b[i]],n-i+1);
  }
  cout<<m<<"\n";
  for (int i=1;i<=m;i++) cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
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