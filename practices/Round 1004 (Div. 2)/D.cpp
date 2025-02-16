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
  vector<int> x(n+1), isx(n+1);
  for (int i=1;i<=n;i++) {
    cin>>x[i];
    isx[x[i]]=1;
  }
  if (accumulate(isx.begin(),isx.end(),0)==n) {
    int i1=0,in=0;
    for (int i=1;i<=n;i++) {
      if (x[i]==1) {i1=i;}
      if (x[i]==n) {in=i;}
    }
    cout<<"? "<<i1<<' '<<in<<endl;
    int ans;
    cin>>ans;
    if (ans<n-1) {
      cout<<"! A"<<endl;
    } else if (ans > n - 1) {
      cout<<"! B"<<endl;
    } else {
      cout<<"? "<<in<<' '<<i1<<endl;
      cin>>ans;
      if (ans==n-1) {
        cout<<"! B"<<endl;
      } else {
        cout<<"! A"<<endl;
      }
    }
  } else {
    for (int i=1;i<=n;i++) {
      if (!isx[i]) {
        cout<<"? "<<i<<' '<<1 + (i==1)<<endl;
        int ans;
        cin>>ans;
        if (ans==0) {
          cout<<"! A"<<endl;
        } else {
          cout<<"! B"<<endl;
        }
        return;
      }
    }
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