#include<iostream>
using namespace std;

int dx[15]={1,-1,0,0,1,1,-1,-1};
int dy[15]={0,0,1,-1,-1,1,1,-1};
int n,m,v[150][150];
char map[150][150];

void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int tx=x+dx[i],ty=y+dy[i];//������һ��λ�� 
		if(tx>0&&ty>0&&tx<=n&&ty<=m){
			if(map[tx][ty]=='W'&&v[tx][ty]==0){
				v[tx][ty]=1;
				dfs(tx,ty);//�ݹ� 
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
			if(map[i][j]=='W'&&v[i][j]==0){
				v[i][j]=1;//������� 
				dfs(i,j);//���� 
				ans++;
			} 
		}
	}
	cout<<ans;
	return 0;
}
