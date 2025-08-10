#include<iostream>
using namespace std;

int f[100005];
int x,y,cnt;

int getf(int x) {
	if(f[x]==x) return x;//���x�ĸ��ڵ����Լ���˵��x���Ǹ��ڵ㣬ֱ�ӷ���
	return f[x]=getf(f[x]);//����ݹ����x�ĸ��ڵ�ĸ��ڵ㣬������·��ѹ��(��xֱ��ָ����ڵ�)
}

void merge(int x,int y) {
	f[getf(y)]=getf(x);//�ҵ�y�ĸ��ڵ㣬���丸�ڵ�����Ϊx�ĸ��ڵ�
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
		//��������Ԫ�أ����ĳ��Ԫ�صĸ��ڵ����Լ���˵������һ�����ϵĸ��ڵ�
		//ͳ�������ĸ��ڵ��������Ƕ������ϵ�����
	}
	
	cout<<cnt;
	return 0;
}

