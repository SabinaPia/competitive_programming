#include<iostream>
#include <cstdio>

using namespace std;

int main(){
	
    int P, presu, H , W, p, men, c, x;
    
    while(cin>>P>>presu>>H>>W){
        men = P+1;
        
        for(int i = 0; i < H; i++){
            cin>>presu;
            c = 0;
            for(int j = 0;j < W; j++){
                cin>>x;
                c = max(c, x);
            }
            if(c >= P) 
				men = min(men, P * presu);
        }
        
        if(men == presu + 1) 
			cout<<"stay home";
        else 
			cout<<men;
    }
    
    return 0;
}
