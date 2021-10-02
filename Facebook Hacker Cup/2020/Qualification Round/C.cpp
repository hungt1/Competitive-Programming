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

const int N = 8e5+1;
pii a[N];

int main()
{
  fastio;
  int T; cin >> T;
  for (int t = 1; t <= T; t++){
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
      cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n);
    int res = a[1].second;
    map <int, int> mx;
    mx[a[1].first] = mx[a[1].first + a[1].second] = a[1].second;
    for (int i = 2; i <= n; i++){
      int x = mx[a[i].first] + a[i].second;
      int y = mx[a[i].first - a[i].second] + a[i].second;
      chmax(res, x); chmax(res, y);
      chmax(mx[a[i].first + a[i].second], x); 
      chmax(mx[a[i].first], y);
    }
    cout << "Case #" << t << ": " << res << '\n';
  }
  return 0;
}