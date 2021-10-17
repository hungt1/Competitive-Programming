# Lời giải bài NKINV

## Thuật toán
- Duyệt (sử dụng cấu trúc dữ liệu BIT)

## Ý tưởng
- Với mỗi phần tử $a_i$ ta cần đếm xem có bao nhiều phần từ $a_j$ $(j < i)$ mà $a_j > a_i$. Ý tưởng đơn giản nhất là ta sẽ sử dụng một mảng `cnt` có ý nghĩa là `cnt[x]` đếm số lần xuất hiện của phần tử mang giá trị `x`.
- Bài toán khi đó có thể minh họa như sau:
    + `ans += tổng của mảng cnt[a[i] + 1 ... MAX]`
    + `cnt[a[i]] += 1`
- Mọi thác tác trên mảng `cnt` có thể update và tính tổng nhanh bằng cách sử dụng `BIT` (với thao tác `update` và `get` ngược).
- Ngoài ra ban trên có thể sử dụng thuật toán chia để trị để giải

## Code mẫu
```cpp
/**
 *    author:    hungt1
 *    created:   06-09-2021   17:36:05
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

struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(int n = 0) : n(n) {
        bit.resize(n + 1, 0);
    }

    void update(int p, int val){
        for (; p > 0; p -= p&-p){
            bit[p] += val;
        }
    }

    int get(int p){
        int ans = 0;
        for (; p <= n; p += p&-p){
            ans += bit[p];
        }
        return ans;
    }
};

int main()
{
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    FenwickTree tree(60000);
    long ans = 0;
    for (int x : a){
        ans += tree.get(x + 1);
        tree.update(x, 1);
    }    
    cout << ans;
    return 0;
}
```