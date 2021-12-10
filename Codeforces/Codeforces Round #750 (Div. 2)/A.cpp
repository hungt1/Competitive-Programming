/**
 *    author:    hungt1
 *    created:   24-10-2021   22:36:13
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

const int N = 1e3 + 1;
char test[N];

int main()
{
    fastio;
    for (int i = 0; i < N; i++){
        test[i] = 'a';
        if (i == N - 1) test[i] = '\0';
    }    
    long long ans = 0;
    for (int i = 0; i < N; i++){
        ans += strlen(test);
    }
    return 0;
}