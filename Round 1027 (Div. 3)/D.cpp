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
 
static ll box_cost(ll mnx,ll mxx,ll mny,ll mxy,int n) {
  ll w=mxx-mnx+1;
  ll h=mxy-mny+1;
  ll area0=w*h;
  if(area0>n-1) {
    return area0;
  } else {
    return min((w+1)*h,w*(h+1));
  }
}

void solve() {
  int n;
  cin>>n;
  vector<ll> x(n);
  vector<ll> y(n);
  pair<ll,ll> maxx={0,0};
  pair<ll,ll> minn={MOD,MOD};
  vector<pair<ll,ll>> v(n);
  for(int i=0;i<n;i++) {
    ll a,b;
    cin>>a>>b;
    x[i]=a;
    y[i]=b;
    maxx=max(maxx,{a,b});
    minn=min(minn,{a,b});
    v[i].first=a;
    v[i].second=b;
  }
  if(n==1) {cout<<1<<"\n";return;}
  else if(n==2) {cout<<2<<"\n";return;}
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  vector<ll> poss={
    box_cost(x[0],x[n-1],y[0],y[n-1],n)
  };
  if(x[0]!=x[1]) poss.push_back(box_cost(x[1],x[n-1],y[0],y[n-1],n));
  if(x[n-1]!=x[n-2]) poss.push_back(box_cost(x[0],x[n-2],y[0],y[n-1],n));
  if(y[0]!=y[1]) poss.push_back(box_cost(x[0],x[n-1],y[1],y[n-1],n));
  if(y[n-1]!=y[n-2]) poss.push_back(box_cost(x[0],x[n-1],y[0],y[n-2],n));
  if(maxx.first==x[n-1]&&maxx.second==y[n-1]) {
    ll first=(x[n-1]!=x[n-2])?x[n-2]:x[n-1];
    ll second=(y[n-1]!=y[n-2])?y[n-2]:y[n-1];
    poss.push_back(box_cost(x[0],first,y[0],second,n));
  }
  if(minn.first==x[0]&&minn.second==y[0]) {
    ll first=(x[0]!=x[1])?x[1]:x[0];
    ll second=(y[0]!=y[1])?y[1]:y[0];
    poss.push_back(box_cost(first,x[n-1],second,y[n-1],n));
  }
  if(count(v.begin(),v.end(),make_pair(x[0],y[n-1]))) {
    ll first=(x[0]!=x[1])?x[1]:x[0];
    ll second=(y[n-1]!=y[n-2])?y[n-2]:y[n-1];
    poss.push_back(box_cost(first,x[n-1],y[0],second,n));
  }
  if(count(v.begin(),v.end(),make_pair(x[n-1],y[0]))) {
    ll first=(x[n-1]!=x[n-2])?x[n-2]:x[n-1];
    ll second=(y[0]!=y[1])?y[1]:y[0];
    poss.push_back(box_cost(x[0],first,second,y[n-1],n));
  }
  sort(poss.begin(),poss.end());
  cout<<poss[0]<<"\n";
 
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