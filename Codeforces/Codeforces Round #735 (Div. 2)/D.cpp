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
template <class T, class U> istream& operator >> (istream &f, pair <T, U> &x){
  f >> x.first >> x.second; return f;
}
template <class T, class U> ostream& operator << (ostream &g, pair <T, U> &x){
  g << x.first << ' ' << x.second; return g;
}
template <class T> istream& operator >> (istream &f, vector <T> &a){
  for (auto &x : a) f >> x; return f;
}
template <class T> ostream& operator << (ostream &g, vector <T> &a){
  for (auto x : a) g << x << ' '; return g;
}
template <class T> void compress(T &a){
  sort(all(a)); a.resize(unique(all(a)) - a.begin());
}

const db pi = acos(-1.00);
const db eps = 1e-6;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main()
{
  fastio;
  int T; cin >> T;
  while (T--){
    int n; cin >> n;
    string ans = "";
    if (n <= 26){
      for (int i = 0; i < n; i++){
        ans += char(i + 'a');
      }
    }
    else {
      if (n % 2){
        ans += 'c'; n--;
      }
      for (int i = 0; i < (n / 2); i++){
        ans += 'a';
      }
      ans += 'b'; n /= 2; n--;
      for (int i = 0; i < n; i++){
        ans += 'a';
      }
    }
    cout << ans << '\n';
  }
  return 0;
}