#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int N, M;

void Cambiar(int x, int y, vector<long int>&V){
	
	for(int i = 0; i < N + 1; i++){
		if(V[i] == y){
			V[i] = x;
		}
	}
}

void Union(int x, int y, vector<long int>&V){
	
	int idx, idx2;
	
	if(V[x] != V[y] || (V[x] == 0 && V[y] == 0) ){
		if(V[x] == 0 && V[y] == 0){// ambos estan solos
		idx = x < y ? x : y;
		} 
		else if(V[x] != 0 && V[y] != 0){ // tienen grupo
			idx = V[x] < V[y] ? V[x] : V[y];//cambiar los valores de el anterior grupo
			idx2 = V[x] > V[y] ? V[x] : V[y];
			Cambiar(idx, idx2, V);
		}
		else{ // uno de ellos no tiene grupo
			idx = V[x] > V[y] ? V[x] : V[y];
		}
		V[x] = idx;
		V[y] = idx;
	}
}

void Mover(int x, int y, vector<long int>&V){
	
	if(V[x] != 0 && V[y] != 0 && V[x] != V[y]){ //tiene grupo
		V[x] = V[y];
	}
	else{
		V[x] = y;
		V[y] = y;
	} 

}

void Suma(int x, vector<long int>&V){
	int cont = 0;
	int sum = 0;
	
	for(int i = 1; i < N + 1; i++){
		if(V[x] == 0){
			cont++;
			sum = x;
			break;
		}
		else if(V[i] == V[x]){
			cont++;
			sum += i;
		}
	}
	
	cout<<cont<<" "<<sum<<endl;
}

int main(){
	
	int op, x, y;
	
	cin>>N>>M;
	
	vector<long int>V(N + 1, 0);
	
	for(int i = 0; i < M; i++){
		cin>>op;
	
		if(op == 1){
			cin>>x>>y;
			Union(x, y, V);
		}
		else if(op == 2){
			cin>>x>>y;
			Mover(x, y, V);
		}
		else{
			cin>>x;
			Suma(x, V);
		}
	
	}
	
	return 0;
}
