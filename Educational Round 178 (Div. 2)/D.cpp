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

int MAX_PRIME=6000000;

vector<int> sieve(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> res;
    for (int i=2;i<=n;i++) {
      if (is_prime[i]) res.push_back(i);
    }
    return res;
}

vector<int> si;
vector<ll> prime_ps;

void initialize() {
    si = sieve(MAX_PRIME);
    
    prime_ps.resize(si.size() + 1, 0);
    for (int i = 0; i < si.size(); i++) {
        prime_ps[i + 1] = prime_ps[i] + si[i];
    }
}

void solve() {
  int n;
  cin>>n;
  vector<ll> v(n);
  for (int i=0;i<n;i++) cin>>v[i];
  if(n==1) {
    if(v[0]==1) cout<<1<<"\n";
    else cout<<0<<"\n";
    return;
  }
  sort(v.begin(),v.end(),greater<ll>());
  ll sum=0;
  int kept=0;
  for (int i=0;i<n;i++) {
    sum+=v[i];
    if (sum>= prime_ps[i+1]) kept=i+1; 
    else break;
  }
  cout<<n-kept<<"\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin>>tc;
  initialize();
  while (tc--) {
    solve();
  }

  return 0;
}