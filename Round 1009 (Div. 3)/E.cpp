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
#include<bits/stdc++.h>

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
  mt19937 mt(727);
  uniform_int_distribution uni(1,3);
  int n; cin>>n;
  if (n<0) return;
  vector<int> vec(n);
  for (int i=0;i<n;i++) vec[i]=i+1;
  shuffle(begin(vec),end(vec),mt);
  int ii=vec[0],jj=vec[1],kk=vec[2];
  while(true) {
    cout<<"? "<<ii<<" "<<jj<<" "<<kk<<endl;
    int id;cin>>id;
    if (id<0) return;
    if (id==0) break;
    int sw=uni(mt);
    if (sw==1) ii=id;
    else if (sw==2)jj=id;
    else kk=id;
  }
  cout<<"! "<<ii<<" "<<jj<<" "<<kk<<endl;
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