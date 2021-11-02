/**
 *    author:    hungt1
 *    created:   02-11-2021   10:07:38
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

multiset<int> s1, s2;
int mid;

void add(int val){
    s2.insert(val);
    while (s2.size() && (s1.size() < mid)){
        auto it = s2.begin();
        s1.insert(*it);
        s2.erase(it);
    }
    while (s2.size() && s1.size() && (*s2.begin() < *s1.rbegin())){
        auto it1 = s1.end(); it1--;
        auto it2 = s2.begin();
        int val1 = *it1, val2 = *it2;
        s1.erase(it1); s2.erase(*it2);
        s1.insert(val2); s2.insert(val1);
    }
}

void remove(int val){
    if (s1.find(val) != s1.end()){
        s1.erase(s1.find(val));
        auto it = s2.begin();
        s1.insert(*it);
        s2.erase(it);
    }
    else {
        s2.erase(s2.find(val));
    }
}

int main()
{
    fastio;
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;     
    mid = (k + 1) / 2;
    for (int i = 0; i < k; i++){
        add(a[i]);
    }
    cout << *s1.rbegin();
    for (int i = k; i < n; i++){
        add(a[i]);
        remove(a[i - k]);
        cout << ' ' << *s1.rbegin();
    }
    return 0;
}