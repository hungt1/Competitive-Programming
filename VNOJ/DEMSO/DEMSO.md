# Lời giải bài DEMSO

## Thuật toán
- Quy hoạch động

## Ý tưởng
- Vói giới hạn đề cho bài toán hoàn toán có thể giải quyết bằng cách sử dụng digit dp.
- Để hiểu rõ hơn có thể đọc tại [đây](https://www.geeksforgeeks.org/digit-dp-introduction/) (trong đó biến `tight = true/false` trong bài viết sẽ ngược lại với biến `lss = false/true` ngay bên dưới đây).
- Y tưởng chính:
  - Nếu `F(X)` là kết quả bài toán trên đoạn `[0, X]` khi đó kết quả bài này chính là `F(B) - F(A - 1)`
  - Để tính toán `F(X)` nêu trên ta xây dựng hàm $dp(i, lss, last, k)$ là:
    - Đã xây dựng được $i$ kí tự đầu
    - $lss = true/false$ tức là các kí tự đang xét có nhỏ hơn các kí tự tương ứng trong $X$ hoặc bằng
    - $last$ là kí tự cuối cùng khi xây dựng được $i$ kí tự
    - $k$ là số vị trí xấu
  - Khi đó đến đây bài toán chỉ cần xây dựng đơn giản bằng hàm dp top-down
- Lưu ý để hiểu được solution trước tiên cần phải đọc qua về digit dp với link đã để trên.

## Code mẫu
```cpp
/**
 *    author:    hungt1
 *    created:   06-10-2021   00:05:42
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

const int N = 21;
long memo[N][2][N][11];
vector<int> digits;
long D, K;

long dp(int i, bool lss, int last, int k){
    if (i == (int)digits.size()) return 1;
    if (memo[i][lss][k][last] != -1) return memo[i][lss][k][last];
    long ans = 0;
    for (int d = 0; d < 10; d++){
        if (!lss && (d > digits[i])) continue;
        int cost = (last == 10 ? 0 : (abs(last - d) <= D));
        if (k + cost > K) continue;
        ans += dp(i + 1, lss | (d < digits[i]), ((last == 10 && d == 0) ? last : d), k + cost);
    }
    return memo[i][lss][k][last] = ans;
}

long F(long x){
    memset(memo, -1, sizeof(memo));
    digits.clear();
    for (; x > 0; x /= 10) digits.push_back(x % 10);
    reverse(all(digits));
    if (digits.size() == 0) digits.push_back(0);
    return dp(0, 0, 10, 0);
}

int main()
{
    fastio;
    long A, B; cin >> A >> B >> D >> K;
    cout << F(B) - F(A - 1) << '\n';
    return 0;
}
```