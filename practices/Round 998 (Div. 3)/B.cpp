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
  vector<vector<int>> v;
  vector<int> cards(n*m);
  for (int i=0;i<n;i++) {
    vector<int> t(m);
    for (int j=0;j<m;j++) {
      cin>>t[j];
      cards[t[j]]=i;
    }
    v.push_back(t);
  }
  vector<int> order(n);
  unordered_set<int> unique;
  for (int i=0;i<n;i++) {
    if (unique.find(cards[i])!=unique.end()){
      cout<<-1<<"\n";
      return;
    }
    unique.insert(cards[i]);
    order[i]=cards[i];
  }
  int pointer=0;
  for (int i=0;i<cards.size();i++) {
    if (pointer==n) {pointer=0;}
    if (order[pointer]!=cards[i]) {
      cout<<-1<<"\n";
      return;
    }
    pointer++;
  }
  for (int i=0;i<order.size();i++) {
    cout<<order[i]+1<<" ";
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