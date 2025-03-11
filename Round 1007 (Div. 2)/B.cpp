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

bool perfect(ll num) {
  ll n=sqrt(num);
  if (n*n==num) {return true;}
  else {return false;}
};

void solve() {
  ll n;
  cin>>n;
  ll total_sum=n*(n+1)/2;
  if (perfect(total_sum)) {
    cout<<-1<<"\n";
    return;
  }
  vector<int> perm;
  ll curr_sum=0;
  ll i=1;
  while (i<=n) {
    if (!perfect(curr_sum+i)) {
      perm.push_back(i);
      curr_sum+=i;
      i++;
    } else {
      perm.push_back(i+1);
      perm.push_back(i);
      curr_sum+=i;
      curr_sum+=i+1;
      i+=2;
    }
  }
  for (auto item:perm) {
    cout<<item<<" ";
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