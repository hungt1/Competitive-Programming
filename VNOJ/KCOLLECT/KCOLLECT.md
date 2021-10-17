# Lời giải bài KCOLLECT

## Thuật toán
- Thành phần liên thông mạnh (Tarjan)
- Topo sort + dp

## Ý tưởng
- Với mỗi ô trên trên bảng $N \cdot M$ ta có thể coi như là một đỉnh của đồ thị, khi đó các ô qua lại được với nhau ta coi là cạnh nối giữa các đỉnh.
- Sau khi xây dựng được đồ thị như thế rồi, ta có thể thấy với mỗi thành phần liên thông mạnh tương đương với việc là tồn tại một cách nhặt hết trái cây ở các đỉnh trong thành phần liên thông đó. Khi đó ta chỉ cần gom các thành phần liên thông mạnh lại thành một "đỉnh" và được một đồ thị mới.
- Trên đồ thị mới, bài toán trở thành tìm một đường đi đơn có tổng trọng số lớn nhất. Bài toán này có thể giải quyết bằng cách sử dụng topo sort và dp (vì đề bài yêu cầu là con robot này xuất phát tại góc trái trên của bảng nên là trên đồ thị mới ta có thể đảo chiều lại đồ thị để dễ dàng tính toán hơn).

## Code mẫu
```cpp
/**
 *    author:    hungt1
 *    created:   06-10-2021   14:22:15
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
const int dx[2] = {0, 1};
const int dy[2] = {1, 0};

const int N = 1e4 + 1;
int num[N], low[N], cost[N], val[N], cur = 0;
int group[N];
stack<int> st;
vector<int> a[N], b[N];
bool visited[N];

void dfs(int u){
    low[u] = num[u] = ++num[0];
    st.push(u);
    for (int v : a[u]){
        if (visited[v]) continue;
        if (num[v]) chmin(low[u], num[v]);
        else {
            dfs(v);
            chmin(low[u], low[v]);
        }
    }
    if (low[u] == num[u]){
        cur++;
        while (true){
            int k = st.top();
            cost[cur] += val[k];
            group[k] = cur;
            st.pop();
            visited[k] = true;
            if (u == k) break;
        }
    }
}

int main()
{
    fastio;
    int n, m; cin >> n >> m;
    vector<vector<char>> c(n, vector<char> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c[i][j];
        }
    }    

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (c[i][j] == '#') continue;
            int u = i * m + j + 1;
            for (int k = 0; k < 2; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if (x == n || y == m || c[x][y] == '#') continue;
                int v = x * m + y + 1;
                a[u].push_back(v);
            }
            if (c[i][j] == 'W'){
                int x = i;
                int y = j - 1;
                if (y < 0 || c[x][y] == '#') continue;
                int v = x * m + y + 1;
                a[u].push_back(v);
            }
            else if (c[i][j] == 'N'){
                int x = i - 1;
                int y = j;
                if (x < 0 || c[x][y] == '#') continue;
                int v = x * m + y + 1;
                a[u].push_back(v);
            }
            else{
                val[u] = c[i][j] - '0';
            }
        }
    }

    for (int i = 1; i <= n * m; i++){
        if (!visited[i]){
            dfs(i);
        }
    }

    for (int i = 1; i <= n * m; i++){
        for (int j : a[i]){
            if (group[i] == group[j]) continue;
            b[group[j]].push_back(group[i]);
        }
    }

    for (int i = 1; i <= cur; i++){
        compress(b[i]);
    }

    vector<int> deg(cur + 1, 0);
    for (int i = 1; i <= cur; i++){
        for (int j : b[i]){
            deg[j]++;
        }
    }
    queue<int> que;
    vector<int> dp(cur + 1, 0);
    for (int i = 1; i <= cur; i++){
        if (deg[i] == 0){
            que.push(i);
            dp[i] = cost[i];
        }
    }
    
    while (!que.empty()){
        int u = que.front();
        que.pop();
        for (int v : b[u]){
            deg[v]--;
            chmax(dp[v], dp[u] + cost[v]);
            if (deg[v] == 0){
                que.push(v);
            }
        }
    }

    cout << dp[group[1]];
    return 0;
}
```