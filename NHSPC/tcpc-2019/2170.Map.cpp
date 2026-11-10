// Author : Zhenzhe
// Time : 2024 / 11 / 19
// Info : 2019 北市賽 pB
// Tags : 高斯消去法（模擬,矩陣列運算）
// Problem : https://tioj.ck.tp.edu.tw/problems/2170
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1005;
int n,mod,mat[MAXN][MAXN];
int fp(int a,int b) {
    if(b == 0) return 1;
    if(b & 1) return a*fp(a,b-1)%mod;
    int h = fp(a,b>>1)%mod;
    return h*h%mod;
}
#define inv(x) (fp(x,mod-2)%mod)
void row_operation() {
    int mainly = 0;
    for(int col = 0;col<n;col++) {
        /*
            1. 選擇主元(pivot)，為值最大者
            2. 主元歸一化(把主元變成 1)
            3. 消去其他列的那一行
        */
        // step 1 -> select pivot
        int pivot = mainly;
        for(int row = mainly+1; row<n;row++) {
            if(abs(mat[row][col]) > abs(mat[pivot][col]))
                pivot = row;
        }
        if(mat[pivot][col] == 0) continue;
        swap(mat[mainly], mat[pivot]);
        // step 2 -> allow mainly element to 1
        int iv = inv(mat[mainly][col]);
        for(int j=col;j<=n;j++) {
            mat[mainly][j] = mat[mainly][j] * iv % mod;
        }
        // step 3 -> do the row operation
        for(int i=0;i<n;i++) {
            int factor = mat[i][col];
            for(int j=col;j<=n;j++) {
                if(i == mainly) continue;
                mat[i][j] = mat[i][j] - mat[mainly][j] * factor % mod + mod;
                mat[i][j] %= mod; 
            }
        }
        mainly += 1;
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> mod;
    for(int i=0;i<n;i++) {
        cin >> mat[i][n];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> mat[j][i];
        }
    }
    row_operation();
    for(int i=0;i<n;i++) {
        cout << mat[i][n] << " \n"[i==n-1];
    }
}