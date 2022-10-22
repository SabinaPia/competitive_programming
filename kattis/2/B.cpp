#include <bits/stdc++.h>
#include <iostream>
#include <sstream>

class FenwickTree {     
                    
	private:
	  	std::vector<long long> ft;                                       
	  
	public:
		FenwickTree(int m) { ft.assign(m+1, 0); }      
		
		void build(const std::vector<long long> &f) {
		    int m = (int)f.size()-1;                    
		    ft.assign(m+1, 0);
		    for (int i = 1; i <= m; ++i) {              
		      	ft[i] += f[i];                             
		      	if (i+(i & -i) <= m)                     
		        	ft[i+(i & -i)] += ft[i];                
		    }
	  	}

	  	FenwickTree(const std::vector<long long> &f){
		    build(f); 
		}        
	
		FenwickTree(int m, const std::vector<int> &s) {             
		    std::vector<long long> f(m+1, 0);
		    for (int i = 0; i < (int)s.size(); ++i)      
		      	++f[s[i]];                                
		    build(f);                                   
		}
	
		long long rsq(int j) {                             
		
		    long long sum = 0;
		    
		    for (; j; j -= j & -j) 
		      	sum += ft[j];
		      	
		    return sum;
		}
	
	  	long long rsq(int i, int j){
	  	 	return rsq(j) - rsq(i-1);
		} 
	

		void update(int i, long long v) {
		    for (; i < (int)ft.size(); i += i & -i)
		      	ft[i] += v;
		}
	
		int select(long long k) {                             
		    int p = 1, i = 0;
		    
		    while(p*2 < (int)ft.size())
				p *= 2;
				
		    while(p){
			    if (k > ft[i+p]) {
			        k -= ft[i+p];
			        i += p;
			    }
			    p /= 2;
		    }
		    return i+1;
		}
};

int n, q;
int values[6]; 
char char_arr[200009];
int int_arr[200009];

std::vector<FenwickTree> trees;

int main(){
	
    std::ios::sync_with_stdio(false);
    std::stringstream output;
    //cin.tie(NULL);
    std::cin>>n>>q;

    for(int i=0; i<6; i++){
        std::cin>>values[i];
    }
    
    std::cin>>char_arr;

    for(int i = 0; i < n; i++){ 
        int_arr[i+1] = char_arr[i] - '0' - 1;
    }

    for(int p=0; p<6; p++){ 
        std::vector<long long> temp_v;
		temp_v.push_back(0);
		
        for(int i=1; i<=n; i++){
            if(int_arr[i] == p)
				temp_v.push_back(1);
            else 
				temp_v.push_back(0);
        }
        
        trees.push_back(FenwickTree(temp_v));
    }

    int op, arg1, arg2;
    
    for(int q_no=0; q_no<q; q_no++){
    	
        std::cin>>op>>arg1>>arg2;
        
        if(op == 1){
            arg2--; 
            trees[int_arr[arg1]].update(arg1, -1); 
            int_arr[arg1] = arg2;
            trees[int_arr[arg1]].update(arg1, 1);
        }
        else if (op == 2){
            arg1--;
            values[arg1] = arg2; 
        }
        else{
        	
            long long ans=0;
            for (int p=0; p<6; p++){
                ans += trees[p].rsq(arg1, arg2) * values[p];
            }

            output<<ans<< "\n";
        }
        
    }
    
	std::cout << output.str();
	
    return 0;

}
