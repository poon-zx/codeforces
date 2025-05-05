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
  vector<int> v1(n+1);
  vector<int> v2(n+1);
  for (int i=1;i<=n;i++) {
    cin>>v1[i];
  }
  for (int i=1;i<=n;i++) {
    cin>>v2[i];
  }
  vector<bool> visit(n+1,false);
  vector<int> len(n+1,0);
  for (int i=1;i<=n;i++) {
    if (visit[i]) continue;
    int a=i;
    int length=0;
    while (!visit[a]) {
      visit[a]=true;
      a=v1[a];
      length++;
      if (a==i) {
        int j=i;
        do {
          len[j]=length;
          j=v1[j];
        } while (j!=i);
        break;
      }
    }
  }
  visit=vector<bool>(n+1,false);
  int res=0;
  for (int i=1;i<=n;i++) {
    res+=len[v2[i]];
    int j=v2[i];
    while (!visit[j]) {
      visit[j]=true;
      len[j]=0;
      j=v1[j];
    }
    cout<<res<<" ";
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