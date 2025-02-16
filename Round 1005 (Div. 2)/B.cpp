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
  vector<int> v(n);
  unordered_map<int,int> m;
  for (int i=0;i<n;i++) {
    cin>>v[i];
    if (m.find(v[i])==m.end()) {
      m[v[i]]=0;
    }
    m[v[i]]++;
  }
  int f=0,s=0;
  int starting=-1;
  bool prev=false;
  int length=0;
  for (int i=0;i<n;i++) {
    if (m[v[i]]==1) {
      if (!prev) {
        starting=i;
        prev=true;
      }
    } else {
      if (prev) {
        if (i-starting>length) {
          f=starting;
          s=i-1;
          length=i-starting;
        }
        prev=false;
      }
    }
  }
  if (prev) {
    if (n-1-starting+1>length) {
        f=starting;
        s=n-1;
        length=n-1-starting+1;
    }
  }
  if (length==0) {
    cout<<0<<"\n";
  } else {cout<<f+1<<" "<<s+1<<"\n";}
  /*
  vector<int> uniques;
  for (auto &ve:m) {
    if (ve.second[0]==1) {
      uniques.push_back(ve.second[1]);
    }
  }
  sort(uniques.begin(),uniques.end());
  int f=0,s=0;
  int l=0,r=0;
  int length=0;
  while (l<uniques.size()) {
    while (r<uniques.size()-1&&uniques[r]+1==uniques[r+1]) {
      r++;
    }
    if (uniques[r]+1==uniques[r+1]) {
      if (r-l+2>length) {
        length=r-l+2;
        f=uniques[l];
        s=uniques[r+1];
      }
    } else {
      if (r-l+1>length) {
        length=r-l+1;
        f=uniques[l];
        s=uniques[r];
      }
    }
    l=r+1;
    r++;
  }
  if (length==0) {
    cout<<0<<"\n";
  } else {cout<<f+1<<" "<<s+1<<"\n";}

*/
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