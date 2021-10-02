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
int n, m, k, s, pA, pB, pC, pD, qA, qB, qC, qD;
int p[N], q[N];

int main()
{
  fastio;
  int T; cin >> T;
  for (int t = 1; t <= T; t++){
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= k; i++) cin >> p[i];
    cin >> pA >> pB >> pC >> pD;
    for (int i = 1; i <= k; i++) cin >> q[i];
    cin >> qA >> qB >> qC >> qD;
    for (int i = k + 1; i <= n; i++){
      p[i] = ((1ll * pA * p[i - 2] + 1ll * pB * p[i - 1] + pC) % pD) + 1;
    }
    for (int i = k + 1; i <= m; i++){
      q[i] = ((1ll * qA * q[i - 2] + 1ll * qB * q[i - 1] + qC) % qD) + 1;
    }
    sort(p + 1, p + 1 + n); sort(q + 1, q + 1 + m);
    auto Check = [&](int val){
      int ptr = 1;
      vector <bool> mark(m + 1, false);
      for (int i = 1; i <= m; i++){
        if (mark[i]) continue;
        while (ptr <= n && p[ptr] + val < q[i]) ptr++;        
        if (ptr > n) continue;
        if (p[ptr] - val > q[i]) return false;
        if (p[ptr] <= q[i]) {
          int x = p[ptr] + val;
          int j = i;
          while (j <= m && q[j] <= x){
            mark[j] = true;
            j++;
          }   
          //cout << i << ' ' << j - 1 << ' ' << ptr << '\n';
          //if (i == 5) cout << p[ptr]  << ' ' << val << ' ' << q[i] << '\n';
        }
        else {
          int l = i; int r = m;
          int pos = i;
          while (l <= r){
            int k = (l + r) / 2;
            if (q[k] - q[i] + min(abs(p[ptr] - q[k]), abs(p[ptr] - q[i])) <= val){
              pos = k;
              l = k + 1;
            }
            else r = k - 1;
          }
          //cout << i << ' ' << pos << ' ' << ptr << '\n';
          for (int j = i; j <= pos; j++) mark[j] = true;  
        }
        if (ptr <= n) ptr++;
      }
      for (int i = 1; i <= m; i++) if (!mark[i]) return false;
      return true;
    };
    //for (int i = 1; i <= n; i++) cout << p[i] << ' '; cout << '\n';
    //for (int i = 1; i <= m; i++) cout << q[i] << ' '; cout << '\n';
    int l = 0; int r = INF;
    int ans = INF;
    while (l <= r){
      int k = (l + r) / 2;
      if (Check(k)){
        r = k - 1;
        ans = k;
      }
      else {
        l = k + 1;
      }
    }
    cout << "Case #"  << t << ": ";
    cout << ans << '\n';
  }
  return 0;
}