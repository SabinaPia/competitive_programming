#include <bits/stdc++.h>
#include <iostream>
#include <sstream>

class FenwickTree{
	
    private:
        std::vector<long long> ft;
        
    public:
    	
        void build(const std::vector<long long> &f){
            int m= (int)f.size() -1;
            ft.assign(m+1, 0);
            for (int i=1;i<=m;i++){
                ft[i] += f[i];
                if (i+(i & -i) <= m)
                    ft[i+(i & -i)] += ft[i];
            }
        }

        FenwickTree(const std::vector<long long> &f){
			build(f); 
		}

        long long rsq(int j){
            long long sum =0;
            for (; j; j -= (j & -j))
                sum += ft[j];
            return sum;
        }

        long long rsq(int i, int j){
			return rsq(j) - rsq(i-1);
		}

        void update(int i, long long v){
            for(int j = i; j < (int)ft.size(); j += (j & -i))
                ft[j] += v;
        }
};

int T, m, temp, r;

int main(){
	
	std::ios::sync_with_stdio(false);
    std::stringstream output;
    
    //cin.tie(NULL);

    std::cin>>T;
    
    for (int tc = 0; tc < T; tc++){
        std::cin>>m>>r;

        std::vector<long long> board;
        board.push_back(0);
        
        for(int i = 0; i < m; i++)
			board.push_back(1);
        for(int i = 0;i < r+1; i++)
			board.push_back(0);

        FenwickTree ft(board);
        std::vector<int> pos; 
		pos.push_back(0); 
		
        for(int i = 1; i <= m; i++){
            pos.push_back(m-i+1);
        }

        for(int r_no = 0; r_no < r; r_no++){
        	
            std::cin>>temp;
            
            long long no_below = ft.rsq(pos[temp]);
            long long no_above = m - no_below;

            ft.update(pos[temp], -1); 
            pos[temp] = m+r_no+1; 
            ft.update(pos[temp], 1); 

            output<<no_above;
            
            if(r_no != r-1)
				output<<" ";
            else 
				output<<std::endl;
        }

    }
	
	std::cout<<output.str();
	
    return 0;
}
