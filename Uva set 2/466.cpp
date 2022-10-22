#include <iostream>
using namespace std;

char* rotar(char* M, int n){
	
    int len = n - 1;
    
    for (int i = 0; i <= len/2 ; i++) {
        for (int j = i; j < len-i; j++) {
            M[(j*n)+len-i] = M[(i*n)+j];
            M[(len-i)*n+len-j] = M[(j*n)+len-i];
            M[(len-j)*n+i] = M[(len-i)*n+len-j];
            M[(i*n)+j] = M[(len-j)*n+i];
        }
    }
    return M;
}

char* vertical(char* M, int n){
    int len = n-1, aux;
    for (int i = 0; i <= len/2; i++) {
        for (int j = 0; j < n; j++) {
        	aux = M[(i*n)+j];
        	M[(i*n)+j] = M[(len-i)*n+j];
        	M[(len-i)*n+j] = aux;
        }
    }
    return M;
}

bool preservar(const char* M1, const char* M2, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(M1[(i*n)+j] != M2[(i*n)+j])
                return false;
        }
    }
    return true;
}
void ingresar(char *M1, char *M2, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>M1[(i*n)+j];
        }
        for (int j = 0; j < n; j++) {
            cin>>M2[(i*n)+j];
        }
    }
}

int main() {
    int n , cont = 1;
    while(cin>>n){
    	
        char* original = new char[n*n];
        char* transformed = new char[n*n];
        
        ingresar(original, transformed, n);
        
        if(preservar(original,transformed,n)){
            cout<<"Pattern "<<cont++<<" was preserved.";
        }
        else if(preservar(rotar(original,n),transformed,n)){
            cout<<"Pattern "<<cont++<<" was rotated 90 degrees.";
        }
        else if(preservar(rotar(original,n),transformed,n)){
            cout<<"Pattern "<<cont++<<" was rotated 180 degrees.";
        }
        else if(preservar(rotar(original,n),transformed,n)){
            cout<<"Pattern "<<cont++<<" was rotated 270 degrees.";
        }
        else{
            original = rotar(original,n);
            
            if(preservar(vertical(original,n),transformed,n)){
                cout<<"Pattern "<<cont++<<" was reflected vertically.";
            }
            else if(preservar(rotar(original,n),transformed,n)){
                cout<<"Pattern "<<cont++<<" was reflected vertically and rotated 90 degrees.";
            }
            else if(preservar(rotar(original,n),transformed,n)){
                cout<<"Pattern "<<cont++<<" was reflected vertically and rotated 180 degrees.";
            }
            else if(preservar(rotar(original,n),transformed,n)){
                cout<<"Pattern "<<cont++<<" was reflected vertically and rotated 270 degrees.";
            }
            else{
                cout<<"Pattern "<<cont++<<" was improperly transformed.";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
