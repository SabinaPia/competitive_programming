#include <iostream>
#include <algorithm>
using namespace std;
int A[10000];
int tam = 0;
int med = 0;

int main() {
    string s;
    
    while(cin>>s){
        s.erase(remove(s.begin(), s.end(),' '),s.end());
        A[tam] = stoi(s);
        sort(A, A + tam);
        if((tam & 1) == 0){
            int x = A[(tam / 2) - 1];
			int y = A[tam / 2];
            med = (x + y) / 2;
        }else{
            med = A[tam / 2];
        }
        tam++;
        
        cout<<med<<endl;
    }
    
    return 0;
}
