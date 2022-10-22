#include<bits/stdc++.h>
using namespace std;

int main(){
	
	std::string line;
	
	while(getline(std::cin, line)){
		
		std::stringstream input(line);
		string x;
		int aux = 0;
		input>>x;
		
		for(int i = 0; i < x.length(); i++){
			if((x[i] == 'B' || x[i] == 'F' || x[i] == 'P' || x[i] == 'V') && aux != 1){
				cout<<1;
				aux = 1;
			}
			else if((x[i] == 'C' || x[i] == 'G' || x[i] == 'J' || x[i] == 'K' 
			|| x[i] == 'Q' || x[i] == 'S' || x[i] == 'X' || x[i] == 'Z') && aux != 2){
				cout<<2;
				aux = 2;
			}
			else if((x[i] == 'D' || x[i] == 'T') && aux != 3){
				cout<<3;
				aux = 3;
			}
			else if(x[i] == 'L' && aux != 4){
				cout<<4;
				aux = 4;
			}
			else if((x[i] == 'M' || x[i] == 'N') && aux != 5){
				cout<<5;
				aux = 5;
			}
			else if(x[i] == 'R'&& aux != 6){
				cout<<6;
				aux = 6;
			}
			else{
				if(x[i] == 'A' || x[i] == 'E' || x[i] == 'I' || x[i] == 'O' || x[i] == 'U' || x[i] == 'H' || x[i] == 'W' || x[i] == 'Y'){
					aux = 0;
				} 	
			}
		}
		
		cout<<endl;
		
	}
	
	return 0;
}
