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
 
const int N = 17;
 
char c[N][N];
int res = 0;
bool A[N], B[N], C[N];
 
void Try(int u){
  for (int i = 1; i <= 8; i++){
    if (!A[i] && !B[i + u] && !C[i - u + 8] && c[u][i] == '.'){
      A[i] = B[i + u] = C[i - u + 8] = true;
      if (u < 8) Try(u + 1);
      else res++;
      A[i] = B[i + u] = C[i - u + 8] = false;
    }
  }
}
 
int main()
{
  fastio;
  for (int i = 1; i <= 8; i++){
    for (int j = 1; j <= 8; j++){
      cin >> c[i][j];
    }
  }
  Try(1);   
  cout << res;
  return 0;
}