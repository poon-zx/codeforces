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

ll ask(ll v) {
  cout<<"? "<<v+1<<endl;
  ll t;
  cin>>t;
  return t;
}

void solve() {
  int n,k;
  cin>>n>>k;
  vector<ll> a(55),b(55),ui(55);
  // a is the first k characters, b is last k chars, ui is pos that dont match
  for(int i=0;i<k;i++) a[i]=ask((ll)i);
  for(int i=n-k;i<n;i++) b[i%k]=ask((ll)i);
  ll uc=0;
  for(int i=0;i<k;i++) {
    if(a[i]!=b[i]) {ui[uc++]=i;}
  }
  if(uc==0) {
    if(n!=k*2) cout<<"! -1"<<endl;
    else cout<<"! "<<k<<" "<<k<<endl;
    return;
  }
  ll left=ui[0],ri=ui[0]+(n-1)/k*k;
  while(left+k!=ri) {
    ll mid=left+(ri-left)/k/2*k;
    if(ask(mid)==a[ui[0]]) left=mid;
    else ri=mid;
  }
  ll lee=0,rii=uc;
  while(lee+1!=rii) {
    ll mid=(lee+rii)/2;
    if(ask(left-ui[0]+ui[mid])==a[ui[mid]]) lee=mid;
    else rii=mid;
  }
  ll pos1=max(left-ui[0]+ui[lee],(ll)k-1LL);
  ll pos2=min(left-ui[0]+((rii==uc)?(ui[0]+k):ui[rii]),(ll)(n-k));
  if(pos1+1!=pos2) {
    cout<<"! -1"<<endl;
  } else {
    cout<<"! "<<pos2<<" "<<n-pos2<<endl;
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