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

class FenwickTree {
 public:
  FenwickTree(int n) : n(n), tree(n + 1, 0) {}

  FenwickTree(std::vector<int>& data): FenwickTree(data.size()) {
    for (int i = 1; i <= n; ++i) {
        tree[i] = data[i-1];
        int parent = i + (i & -i);
        if (parent <= n) {
            tree[parent] += tree[i];
        }
    }
  }


  int query(int l, int r) const { return prefix(r) - prefix(l-1); }

  void update(int i, int diff) {
    for (; i <= n; i += i & -i) {
      tree[i] += diff;
    }
  }

  int prefix(int i) const {
    int sum = 0;
    for (; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }

 private:
  const int n;
  std::vector<int> tree;
};


void solve() {
  int n;
  cin>>n;
  vector<int> v(n);
  bool sort=true;
  for (int i=0;i<n;i++) {
    cin>>v[i];
    if (i>0&&v[i]<v[i-1]) {
      sort=false;
    }
  }
  if (sort) {
    cout<<1<<" "<<1<<"\n";
    return;
  }
  vector<pair<int,int>> bigger(n);
  int inv=-MOD;
  int resl=0,resr=0;
  for (int l=0;l<n;l++) {
    vector<int> smaller(n);
    vector<int> greater(n);
    smaller[l]=0;
    greater[l]=0;
    for (int i=l+1;i<n;i++) {
      smaller[i]=smaller[i-1];
      greater[i]=greater[i-1];
      if (v[l]<v[i]) {
        smaller[i]++;
      } else if (v[l]>v[i]) {
        greater[i]++;
      }
    }
    for (int r=l+1;r<n;r++) {
      int score=greater[r]-smaller[r];
      if (score>inv) {
        inv=score;
        resl=l;
        resr=r;
      }
    }
  }
  cout<<resl+1<<" "<<resr+1<<"\n";
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