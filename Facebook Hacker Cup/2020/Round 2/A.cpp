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

const int N = 1e6+1;
int n, k;
long s[N], x[N], y[N];
long sA, sB, sC, sD, xA, xB, xC, xD, yA, yB, yC, yD;

int main()
{
  fastio;
  int T; cin >> T;
  for (int t = 1; t <= T; t++){
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> s[i];
    cin >> sA >> sB >> sC >> sD;
    for (int i = 1; i <= k; i++) cin >> x[i];
    cin >> xA >> xB >> xC >> xD;
    for (int i = 1; i <= k; i++) cin >> y[i];
    cin >> yA >> yB >> yC >> yD;
    for (int i = k + 1; i <= n; i++){
      s[i] = (sA * s[i - 2] + sB * s[i - 1] + sC) % sD;
      x[i] = (xA * x[i - 2] + xB * x[i - 1] + xC) % xD;
      y[i] = (yA * y[i - 2] + yB * y[i - 1] + yC) % yD;
    }
    long a = 0; long b = 0;
    long need = 0; long red = 0;
    for (int i = 1; i <= n; i++){
      if (s[i] < x[i]) {
        need += x[i] - s[i];
        a += y[i];
      }
      else if (s[i] > x[i] + y[i]) {
        red += s[i] - x[i] - y[i];
        b += y[i];
      }
      else {
        a += x[i] + y[i] - s[i];
        b += s[i] - x[i];
      }
    }
    bool check = false;
    if (need == red) check = true;
    else if (need < red && need + a >= red) check = true;
    else if (need > red && red + b >= need) check = true;
    cout << "Case #"  << t << ": ";
    if (check) cout << max(need, red) << '\n';
    else cout << -1 << '\n';
  }
  return 0;
}