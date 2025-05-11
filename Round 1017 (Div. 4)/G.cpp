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
  int q;
  cin>>q;
  deque<int> deq;
  deque<int> deq_back;
  ll rizz=0;
  ll rizz_b=0;
  ll tot=0;
  int size=0;
  int back=1;
  while(q--) {
    int op,num;
    cin>>op;
    if(op==3) {
      cin>>num;
      size++;
      rizz+=(ll)size*(ll)num;
      rizz_b+=tot+(ll)num;
      tot+=num;
      deq.push_back(num);
      deq_back.push_front(num);
    } else if (op==2) {
      swap(deq,deq_back);
      swap(rizz,rizz_b);
    } else {
      int back=deq.back();
      rizz-=(ll)back*(ll)size;
      rizz+=tot;
      deq.pop_back();
      deq.push_front(back);

      int front=deq_back.front();
      rizz_b-=tot;
      rizz_b+=(ll)front*(ll)size;
      deq_back.pop_front();
      deq_back.push_back(front);
    }
    cout<<rizz<<"\n";
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