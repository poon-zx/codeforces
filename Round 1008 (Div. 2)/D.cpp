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
  vector<string> op0(n+1),op1(n+1);
  vector<int> val0(n+1),val1(n+1);
  for (int i=1;i<=n;i++) {
    cin>>op0[i]>>val0[i]>>op1[i]>>val1[i];
  }
  vector<int> latest_multiply(n+2,0);
  for (int i=n;i>0;i--) {
    if (op0[i]=="+"&&op1[i]=="+") latest_multiply[i]=latest_multiply[i+1];
    else if (op0[i]=="x"&&op1[i]=="+") latest_multiply[i]=0;
    else if (op0[i]=="+"&&op1[i]=="x") latest_multiply[i]=1;
    else if (val0[i]>val1[i]) latest_multiply[i]=0;
    else if (val0[i]<val1[i]) latest_multiply[i]=1;
    else latest_multiply[i]=latest_multiply[i+1];
  }
  vector<ll> a(2,1);
  for (int i=1;i<=n;i++) {
    ll gained=0;
    if (op0[i]=="+") gained+=val0[i];
    else gained+=(val0[i]-1LL)*a[0];
    if (op1[i]=="+") gained+=val1[i];
    else gained+=(val1[i]-1LL)*a[1];
    a[latest_multiply[i+1]]+=gained;
  }
  cout<<a[0]+a[1]<<"\n";
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