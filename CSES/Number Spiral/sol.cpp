#include <bits/stdc++.h>
using namespace std;
 
#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define long long long
#define db double
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
template <class T> inline void chmin(T &a, const T& val) { if (a > val) a = val; }
template <class T> inline void chmax(T &a, const T& val) { if (a < val) a = val; }
template <class T> long sqr(T a) { return 1ll * a * a; }
template <class T> void compress(T &a){
  sort(all(a)); a.resize(unique(all(a)) - a.begin());  
}
 
const db pi = acos(-1.00);
const db eps = 1e-6;
const int INF = 1e9;
const int MOD = 1e9+7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
 
int main()
{
  fastio;
  int T; cin >> T;
  while (T--){
    long x, y; cin >> x >> y;
    long res;
    if (x < y){
      res = (y - 1) * (y - 1);
      if (y % 2) res += 2 * y - x;
      else res += x;  
    }
    else{
      res = (x - 1) * (x - 1);
      if (x % 2) res += y;
      else res += 2 * x - y;
    }
    cout << res << '\n';
  }
  return 0;
}