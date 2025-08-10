#include<iostream>
using namespace std;

int n,k;
int a[1005],b[1005],v[1005],ans[1005];
bool outed=false;
void dfs(int lable){
	//cout<<lable<<' ';
	if(lable==k+1){
		if(!outed){
			for(int i=1;i<=k;i++){
				cout<<ans[i]<<' ';
			}
			outed=true;
		}
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]>=b[lable]&&v[i]==0){
			v[i]=1;ans[lable]=i;
			dfs(lable+1);
			ans[lable]=0;
			v[i]=0;
		}
	}
}

int main(){
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
	}
	dfs(1);
	if(!outed){
		cout<<"-1";
	}
	return 0;
}

