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

struct DSU {
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }
    
    bool union_set(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }
};

void solve() {
  int n,m1,m2;
  cin>>n>>m1>>m2;
  vector<pair<int,int>> edgesF;
  vector<pair<int,int>> edgesG;

  for (int i=0;i<m1;i++) {
    int a,b;
    cin>>a>>b;
    edgesF.push_back({a-1,b-1});
  }

  DSU dsuG=DSU(n);
  for (int i=0;i<m2;i++) {
    int a,b;
    cin>>a>>b;
    edgesG.push_back({a-1,b-1});
    dsuG.union_set(a-1,b-1);
  }
  DSU dsuF=DSU(n);
  int remove=0;
  for (auto edge:edgesF) {
    if (dsuG.find(edge.first)!=dsuG.find(edge.second)) {
      remove++;
    } else {
      dsuF.union_set(edge.first, edge.second);
    }
  }
  vector<set<int>> comp(n);
  for (int i=0;i<n;i++) {
    comp[dsuG.find(i)].insert(dsuF.find(i));
  }
  int add=0;
  for (auto s:comp) {
    if (s.size()>1) {
      add+=s.size()-1;
    }
  }
  cout<<remove+add<<"\n";
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