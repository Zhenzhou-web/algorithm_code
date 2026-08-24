#include<iostream>;
using namespace std;
int main(){
	int n;
	int a=1;
	int m=0; 
    cin>>n;
    for(int i=1;i<=n;i++){
    	a=a*i;
    	m+=a;
    }
    cout<<m;
	return 0;
}
