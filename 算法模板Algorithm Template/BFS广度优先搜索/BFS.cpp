#include<iostream>
#include<queue>
using namespace std;
int n,m,dx[5]={1,0,-1,0},dy[5]={0,1,0,-1},v[1005][1005];
char map[1005][1005];
struct node{
	int x,y;
};

void dfs(int aa,int bb){
	queue<node> q;
	node nd;
	nd.x=aa;nd.y=bb;
	q.push(nd);
	v[aa][bb]=1;
	while(!q.empty()){
		node t=q.front();q.pop();
		for(int i=0;i<4;i++){
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if(tx>=1&&ty>=1&&tx<=n&&ty<=m){
				if(v[tx][ty]!=1&&map[tx][ty]!='0'){
					v[tx][ty]=1;
					nd.x=tx;nd.y=ty;
					q.push(nd);
					
				}
			}
		}
	}
}
int main(){
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j]; 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]!='0'&&v[i][j]!=1){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
}
