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
  int n; cin >> n;
  if (n == 1) return cout << 1, 0;
  if (n <= 3) return cout << "NO SOLUTION", 0;
  deque <int> d = {2, 4, 1, 3};
  for (int i = 5; i <= n; i++){
    if (i % 2) d.push_back(i);
    else d.push_front(i);
  }
  for (int x : d) cout << x << ' ';
  return 0;
}