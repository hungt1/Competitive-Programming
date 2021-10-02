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
int W[N], wA, wB, wC, wD;

int main()
{
  fastio;
  int T; cin >> T;
  for (int t = 1; t <= T; t++){
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> L[i];
    cin >> lA >> lB >> lC >> lD;
    for (int i = 1; i <= k; i++) cin >> W[i];
    cin >> wA >> wB >> wC >> wD;
    for (int i = 1; i <= k; i++) cin >> H[i];
    cin >> hA >> hB >> hC >> hD;
    for (int i = k + 1; i <= n; i++){
      L[i] = ((1ll * lA * L[i - 2] + 1ll * lB * L[i - 1] + lC) % lD) + 1;
      H[i] = ((1ll * hA * H[i - 2] + 1ll * hB * H[i - 1] + hC) % hD) + 1;
      W[i] = ((1ll * wA * W[i - 2] + 1ll * wB * W[i - 1] + wC) % wD) + 1;      
    }
    set <pii> S; long cur = 0;
    long ans = 1;
    for (int i = 1; i <= n; i++){
      if (i == 1){
        cur += 2 * (W[i] + H[i]);
        S.insert(pii(L[i] + W[i], L[i]));
      }    
      else {
        auto it = S.lower_bound(pii(L[i], 0));
        vector <pii> memo;
        int l = L[i]; int r = L[i] + W[i];
        for (; it != S.end(); it++){
          if (it->second > L[i] + W[i]) break;
          memo.push_back(*it);
          chmin(l, it->second);
          chmax(r, it->first);
        }
        if (memo.size() && L[i] < memo[0].second) cur += 2 * (memo[0].second - L[i]);
        if (memo.size() && L[i] + W[i] > memo.back().first) cur += 2 * (L[i] + W[i] - memo.back().first);      
        for (int p = 1; p < memo.size(); p++){
          cur += 2 * (memo[p].second - memo[p - 1].first);
          cur -= 2 * H[i]; 
        }
        for (pii x : memo) S.erase(x);
        S.insert(pii(r, l));
        if (memo.size() == 0) cur += 2 * (W[i] + H[i]);
      }
      cur %= MOD; (cur += MOD) %= MOD;
      ans *= cur; ans %= MOD;
    }
    cout << "Case #"  << t << ": ";
    cout << ans << '\n';
  }
  return 0;
}