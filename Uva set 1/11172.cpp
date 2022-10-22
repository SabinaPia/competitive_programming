#include <iostream>
using namespace std;



int main(){
	
	long a, b, x;
	
	cin>>x;
	
	char v[x];
	
	for(int i = 0; i < x; i++){
		cin>>a>>b;
		
		if(a > b){
			v[i] = '>';
		}
		else if(a < b){
			v[i] = '<';
		}
		else{
			v[i] = '=';
		}
	}
	
	for(int i = 0; i < x; i++)
		cout<<v[i]<<endl;
	
	return 0;
}
