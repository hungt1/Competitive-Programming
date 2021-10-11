/**
 *    author:    hungt1
 *    created:   11-10-2021   01:05:57
**/
#include <bits/stdc++.h>
using namespace std;

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
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct Point {
    long x, y;
    
    Point(long x = 0, long y = 0) : x(x), y(y) {}
    
    bool operator < (const Point &other) const {
        return (x == other.x ? y < other.y : x < other.x);
    }

    long cross(const Point &p, const Point &q){
        return (p.x - x) * (q.y - y) - (p.y - y) * (q.x - x); 
    }
};

vector<Point> convexHull(vector<Point> cur){
    vector<Point> res; sort(all(cur));
    int n = cur.size(), k = 0;
    for (int i = 0; i < n; i++){
        while (k >= 2 && res[k - 2].cross(res[k - 1], cur[i]) <= 0){
            res.pop_back(); k--;
        }
        res.push_back(cur[i]); k++;
    }
    for (int i = n - 2, t = k + 1;  i >= 0; i--){
        while (k >= t && res[k - 2].cross(res[k - 1], cur[i]) <= 0){
            res.pop_back(); k--;
        }
        res.push_back(cur[i]); k++;
    }
    res.pop_back();
    return res;
}

bool solve(){
    int n; cin >> n;
    if (n == -1) return false;
    vector<Point> cur(n);
    for (auto &p : cur){
        cin >> p.x >> p.y;
    }
    cur = convexHull(cur);
    n = cur.size();
    long ans = 0;
    for (int i = 0; i < n; i++){
        int k = (i + 1) % n;
        for (int j = (i + 2) % n; j != i; j = (j + 1) % n){
            int nxt = (k + 1) % n;
            while (nxt != j && cur[i].cross(cur[k], cur[j]) <= cur[i].cross(cur[nxt], cur[j])){
                k = nxt;
                nxt = (k + 1) % n;
            }
            chmax(ans, cur[i].cross(cur[k], cur[j]));
        }
    }
    cout << fixed << setprecision(2) << 1.0 * ans / 2 << '\n';
    return true;
}

int main()
{
    fastio;
    while (true){
        if (!solve()) break;
    }
    return 0;
}