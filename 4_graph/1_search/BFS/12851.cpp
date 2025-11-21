#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int visited[100001],d[100001];
//d 배열은 해당 노드까지 최단시간 내 방문하는 경우의 수이다
queue<int> q;

bool check(int x){
    if(x<0 || x>100000) return false;
    return true;
}

void visit(int u, int v) {

    if(visited[v]>visited[u]+1){
        visited[v]=visited[u]+1;
        q.push(v);
    }
    //최단 시간 내에 방문 시
    if(visited[v]==visited[u]+1)
        d[v]+=d[u];
}

void bfs(int u){
    
    d[u]=1;
    visited[u]=0;
    q.push(u);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==m) break;
        if(check(u-1)) visit(u,u-1);
        if(check(u+1)) visit(u,u+1);
        if(check(2*u)) visit(u,2*u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<=100000;i++) visited[i]=100000;
    bfs(n);
    cout<<visited[m]<<'\n'<<d[m];
}