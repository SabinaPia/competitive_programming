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
	
	  	FenwickTree(const std::vector<long long> &f) { build(f); }        
	
	  	FenwickTree(int m, const std::vector<int> &s) {             
		    std::vector<long long> f(m+1, 0);
		    
		    for(int i = 0; i < (int)s.size(); ++i)     
		      	++f[s[i]];                                
		    build(f);                                    
		    
	  	}
	
		long long rsq(int j) {                                
		    long long sum = 0;
		    for (; j; j -= (j & -j))
		      sum += ft[j];
		    return sum;
		}
	
	  	long long rsq(int i, int j){
		    return rsq(j) - rsq(i-1);
		} 
	
	
		void update(int i, long long v) {
		    for (; i < (int)ft.size(); i += (i & -i))
		      	ft[i] += v;
		}
	
		int select(long long k) {                          
		    int p = 1;
		    while(p*2 < (int)ft.size())
				p *= 2;
				
		    int i = 0;
		    while(p){
			    if(k > ft[i+p]) {
			    	k -= ft[i+p];
			        i += p;
			    }
			    p /= 2;
		    }
		    return i+1;
		}
};

int n, k, l, r;
char op;

int main(){
    std::ios::sync_with_stdio(false);
    std::stringstream output;
    //cin.tie(NULL);
    
    std::cin>>n>>k;

    FenwickTree ft(n);

    for(int i = 0; i < k; i++){
        std::cin>>op>>l;
        
        if(op == 'F'){
            int old_val = ft.rsq(l,l);
            int new_val = (old_val+ 1)%2;
            ft.update(l, new_val-old_val);
        }
        else if(op == 'C'){
            std::cin>>r;
            output<<ft.rsq(l,r)<<std::endl;
        }
    }
    
    std::cout<<output.str();
    
	return 0;
}
