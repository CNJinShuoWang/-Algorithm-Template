#include<iostream>
using namespace std;

int f[100005];
int x,y,cnt;

int getf(int x) {
	if(f[x]==x) return x;//如果x的父节点是自己，说明x就是根节点，直接返回
	return f[x]=getf(f[x]);//否则递归查找x的父节点的根节点，并进行路径压缩(将x直接指向根节点)
}

void merge(int x,int y) {
	f[getf(y)]=getf(x);//找到y的根节点，将其父节点设置为x的根节点
}

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		f[i]=i; 
	}
	
	for(int i=1;i<=m;i++) {
		cin>>x>>y;
		merge(x,y);
	}
	
	for(int i=1;i<=n;i++){
		if(f[i]==i) cnt++;
		//遍历所有元素，如果某个元素的父节点是自己，说明它是一个集合的根节点
		//统计这样的根节点数量就是独立集合的数量
	}
	
	cout<<cnt;
	return 0;
}

