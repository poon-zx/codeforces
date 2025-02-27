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
  int n,k;
  cin>>n>>k;
  string s;
  getline(cin,s);
  vector<ll> v(n);
  priority_queue<vector<ll>,vector<vector<ll>>> q;
  for (int i=0;i<n;i++) {
    cin>>v[i];
    if (s[i]=='R') {
      q.push({v[i],0,i});
    } else {
      q.push({v[i],1,i});
    }
  }
  int res=0;
  vector<int> reds;
  vector<int> blues;
  FenwickTree ft(n);
  while (k>0) {
    ll top_num=q.top()[0];
    char top_ind=q.top()[2];
    if (q.top()[1]==0) {
      ft.update(top_ind,1);
    } else {
      if (blues.empty()) {k--;}
      for (auto b:blues) {
        if (ft.query(b,top_ind)!=0) {
          k--;
          break;
        }
      }
      blues.push_back(top_ind);
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