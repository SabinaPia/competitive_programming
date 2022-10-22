#include<bits/stdc++.h>
#include <iostream>
#include <sstream>

long int N, Q;

void add(long int i, long int valor, std::vector<long int>& vector1) {
    
	if(i == 0){
    	vector1[0] += valor;
	}
	else{
		for(; i <= N; i += i  & - i)
        	vector1[i] += valor;
	}
	
}

long int sum(long int id, std::vector<long int>& vector1) {
    --id;
    if(id == -1)
    	return 0;
    	
	long int ret = vector1[0];
    
    for(id; id > 0; id -= id & -id)
        ret += vector1[id];
        
    return ret;
}

int main(){
	
	std::ios::sync_with_stdio(false);
	//std::cin.tie(NULL);
	std::cin>>N>>Q;
	//scanf("%d %d", &N, &Q);
	
	std::vector<long int> vector1(N+1, 0);
	
	long int a, valor;
	std::string caracter;
	
	std::stringstream output;
	
	for(int i = 0; i < Q; i++){
	
		std::cin>>caracter;
		
		if(caracter == "+"){
			//scanf("%d %lld", &a, &valor);
			std::cin>>a>>valor;
			add(a, valor, vector1);
		}
		else{
			std::cin>>a;
			//scanf("%d", &a);
			//long int x= sum(a, vector1);
			output<<sum(a, vector1)<< "\n";
		}
	}
	/*
	for(int i = 0; i < ind; i++){
		printf("%lld\n", res[i]);
		//cout<<res[i]<<endl;
	}
	*/
	std::cout << output.str();
	
	return 0;
}
