/**
 *    author:    hungt1
 *    created:   03-10-2021   13:04:56
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
const long INF = 1e18;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main()
{
    fastio;
    vector<long> pre = {0, 9};
    vector<long> num = {0, 9};
    long tot = 9;
    for (int i = 2; ; i++){
        pre.push_back(pre.back() * 10);
        num.push_back(num.back() * 10 + 9);
        tot += pre.back() * i;
        if (tot > INF) break;
    }
    for (int i = 1; i < pre.size(); i++) pre[i] = pre[i - 1] + pre[i] * i;
    int Q; cin >> Q;
    while (Q--){
        long k; cin >> k;
        int pos = upper_bound(all(pre), k) - pre.begin() - 1;
        k -= pre[pos];
        int r = k % (pos + 1);
        long number = num[pos] + k / (pos + 1);
        if (r == 0){
            cout << number % 10 << '\n';
        }
        else {
            number++;
            int discard = pos + 1 - r;
            for (; discard; discard--) number /= 10;
            cout << number % 10 << '\n';
        }
    }
    return 0;
}