// Author : Zhenzhe
// Time : 2024 / 11 / 01
// Problem : https://zerojudge.tw/ShowProblem?problemid=f435
#include <bits/stdc++.h>
using namespace std;
static constexpr int MAXN = 255;
#define check(i,j) (i>=1&&i<=SIZE.first&&j>=1&&j<=SIZE.second)
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    char graph[MAXN][MAXN];
    pair<int,int> SIZE = {0,0};
    char command,input,color;
    string name;
    int x,y,x1,x2,y1,y2;
    memset(graph, 'O', sizeof(graph));
    function<void(int,int,char,char)>dfs=[&](int i,int j,char c,char conv) {
        graph[i][j] = conv;
        if(check(i-1,j) && graph[i-1][j] == c)
            dfs(i-1,j,c,conv);
        if(check(i+1,j) && graph[i+1][j] == c)
            dfs(i+1,j,c,conv);
        if(check(i,j-1) && graph[i][j-1] == c)
            dfs(i,j-1,c,conv);
        if(check(i,j+1) && graph[i][j+1] == c)
            dfs(i,j+1,c,conv);
    };
    while(cin >> input) {
        switch(input) {
            case 'X':
                return 0;
            case 'I':
                cin >> x >> y;
                SIZE = {y,x};
                for(int i=1;i<=SIZE.first;i++) {
                    for(int j=1;j<=SIZE.second;j++) {
                        graph[i][j] = 'O';
                    }
                }
                break;
            case 'C':
                for(int i=1;i<=SIZE.first;i++) {
                    for(int j=1;j<=SIZE.second;j++) {
                        graph[i][j] = 'O';
                    }
                }
                break;
            case 'L':
                cin >> x >> y >> color;
                graph[y][x] = color;
                break;
            case 'V':
                cin >> x >> y1 >> y2 >> color;
                if(y1 > y2) swap(y1,y2);
                for(int i=y1;i<=y2;i++) {
                    graph[i][x] = color;
                }
                break;
            case 'H':
                cin >> x1 >> x2 >> y >> color;
                if(x1 > x2) swap(x1,x2);
                for(int j=x1;j<=x2;j++) {
                    graph[y][j] = color;
                }
                break;
            case 'K':
                cin >> x1 >> y1 >> x2 >> y2 >> color;
                if(x1 > x2) swap(x1,x2);
                if(y1 > y2) swap(y1,y2);
                for(int i=y1;i<=y2;i++) {
                    for(int j=x1;j<=x2;j++) {
                        graph[i][j] = color;
                    }
                }
                break;
            case 'F':
                cin >> x >> y >> color;
                if(graph[y][x] != color) dfs(y,x,graph[y][x],color);
                // graph[y][x] = color;
                break;
            case 'S':
                cin >> name;
                cout << name << '\n';
                for(int i=1;i<=SIZE.first;i++) {
                    for(int j=1;j<=SIZE.second;j++) {
                        cout << graph[i][j];
                    }
                    cout << '\n';
                }
                //cout << '\n';
                break;
            default:
                break;
        }
    }
}