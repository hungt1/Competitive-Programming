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
int n, k, w;
int L[N], H[N], lA, lB, lC, lD, hA, hB, hC, hD;

int main()
{
  fastio;
  int T; cin >> T;
  for (int t = 1; t <= T; t++){
    cin >> n >> k >> w;
    for (int i = 1; i <= k; i++) cin >> L[i];
    cin >> lA >> lB >> lC >> lD;
    for (int i = 1; i <= k; i++) cin >> H[i];
    cin >> hA >> hB >> hC >> hD;
    for (int i = k + 1; i <= n; i++){
      L[i] = ((1ll * lA * L[i - 2] + 1ll * lB * L[i - 1] + lC) % lD) + 1;
      H[i] = ((1ll * hA * H[i - 2] + 1ll * hB * H[i - 1] + hC) % hD) + 1;
    }
    long ans = 1; long cur = 0;
    deque <int> d;
    for (int i = 1; i <= n; i++){
      while (d.size() && L[d.front()] + w < L[i]) d.pop_front();
      if (d.empty()){
        cur += 2 * (w + H[i]); 
      }
      else {
        cur += 2 * max(0, H[i] - H[d.front()]);
        cur += 2 * (L[i] - L[i - 1]);
      }
      while (d.size() && H[d.back()] < H[i]) d.pop_back();
      d.push_back(i);
      cur %= MOD; ans *= cur; 
      ans %= MOD;
    }
    cout << "Case #"  << t << ": ";
    cout << ans << '\n';
  }
  return 0;
}