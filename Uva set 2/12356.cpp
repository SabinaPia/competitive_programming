#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int S, R, izq, der;

    while(cin>>S>>R && !(S == 0 && R == 0)){
    	
        vector< pair<int, int> > B(S + 2);

        for(int i = 1; i <= S; i++){
            B[i].first  = i - 1;
            B[i].second = i + 1;
        }

        for(int i = 0; i < R; i++){
            cin>>izq>>der;

            B[B[izq].first].second  = B[der].second;
            B[B[der].second].first = B[izq].first;

            if (B[B[der].second].first == 0)
                cout<<'*';
            else
                cout<<B[B[der].second].first;

            cout<<' ';

            if (B[B[izq].first].second == S + 1)
                cout<<'*';
            else
                cout<<B[B[izq].first].second;

            cout<<endl;
        }

        cout<< "-"<<endl;
    }

    return 0;
}
