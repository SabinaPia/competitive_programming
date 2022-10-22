#include<bits/stdc++.h>
using namespace std;

long int A[1000000 + 5];
long int tam[1000000 + 5];

int buscar(int x){
    if(x == A[x]) 
		return x;
    else 
		return A[x] = buscar(A[x]);
}

void unir(int p, int q){
    int a = buscar(p);
    int b = buscar(q);
    if(tam[a] > tam[b]){
        A[b] = a;
    }else{
        A[a] = b;
        if(tam[a] == tam[b])
			tam[a]++;
    }
}
int main(){
    ios::sync_with_stdio(false);

    int n, m, p, q, a, b;
    char x;
    
    while(cin>>n>>m){
    	
        for(int i = 0; i < n; i++){
            A[i] = i;
            tam[i] = 1;
        }
        
        for(int i = 0; i < m; i++){
            cin>>x;
            if(x == '='){
                cin>>p>>q;
                unir(p,q);
                break;
            }
            else if(x == '?'){
                cin>>p>>q;
                a = buscar(p);
                b = buscar(q);
                if(a == b)
					cout << "yes\n";
                else 
					cout << "no\n";
                break;
            }
        }   
    }

    
}
