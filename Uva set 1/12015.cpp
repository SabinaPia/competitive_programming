#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ans;

int main()
{
    int test = 1;
	int t, n, v;
    
    string page;
    cin >> t;
    while(t--)
    {
        v = -1;
        ans.clear();
        
        for(int i = 0; i < 10; i++){
            cin>>page>>n;
            if(n > v)
            {
                v = n;
                ans.clear();
                ans.push_back(page);
            }
            else if(n == v)
                ans.push_back(page);
        }
        
        cout<<"Case #"<<test++<<":\n";
        
        int len = (int) ans.size();
        
        for(int i = 0;i < len;++i)
            cout<<ans[i]<<'\n';
    }
    
    return 0;
}
