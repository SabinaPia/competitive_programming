#include<bits/stdc++.h>

int main(){
    
	std::string line;
	
	while(getline(std::cin, line)){
		
		std::stringstream input(line);
		
		int n, tam = 0, aux = 0, x = 0;
		
		input>>tam;
		std::vector<int>vector1(tam, 0);
		input>>aux;
		
		for(int i = 0; i < tam - 1; i++){
			input>>n;
			unsigned int res = abs(n - aux);
			aux = n;
			
			if(res < tam && vector1[res] != 1){
				vector1[res] = 1;
				x++;
			}
			
		}
	
		if(x == tam - 1)
			std::cout<<"Jolly"<<std::endl;
		else
			std::cout<<"Not jolly"<<std::endl;
				
	}
	
	return 0;
}
