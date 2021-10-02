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

const int N = 51;
bool res[N][N], mark[N];
int n;
char I[N], O[N];

void dfs(int u, int cur){
  mark[u] = true; res[cur][u] = true;
  if (O[u] == 'N') return;
  if (u - 1 > 0 && !mark[u - 1] && (I[u - 1] == 'Y')) dfs(u - 1, cur);
  if (u + 1 <= n && !mark[u + 1] && (I[u + 1] == 'Y')) dfs(u + 1, cur);
}

int main()
{
  fastio;
  int T; cin >> T;
  for (int t = 1; t <= T; t++){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> I[i];
    for (int i = 1; i <= n; i++) cin >> O[i];
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        res[i][j] = false;
      }
      res[i][i] = true;
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++) mark[j] = false;
      dfs(i, i);
    }
    cout << "Case #" << t << ":\n";
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        cout << (res[i][j] ? 'Y' : 'N');
      }
      cout << '\n';
    }
  }
  return 0;
}