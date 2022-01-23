/**
 *    author:    hungt1
 *    created:   14-10-2021   14:59:29
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

int main()
{
    fastio;
    int n; cin >> n;
    vector<int> cur(n);
    for (int i = 0; i < n; i++){
        cur[i] = i + 1;
    }
    int start = 0;
    int cnt = 0;
    while (cur.size()){
        vector<int> nxt;
        int check = 0;
        for (int i = start; i < cur.size(); i += 2){
            nxt.push_back(cur[i]);
            if ((i + 1) == (int)cur.size()){
                check = 1;
            }
            else {
                cout << cur[i + 1] << ' ';
            }
        }
        swap(nxt, cur);
        start = check;
        if (start && cur.size()) cout << cur[0] << ' ';
    }
    return 0;
}