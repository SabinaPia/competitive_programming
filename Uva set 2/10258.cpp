#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class PT {
	public:
		int sol = 0;
		int pun = 0;
		int pb[10][2];
		bool aux = false;
		int id;
		
		bool operator<(const P& a)const {
			if (sol != a.sol) return sol > a.sol;
			else if(pun!=a.pun) return pun < a.pun;
			else return id < a.id;
		}
};

int main() {
	
	int n; 
	
	cin>>n;
	
	while(n--) {
		PT p[105];
		
		for (int i = 0; i < 100; i++)
			memset(p[i].pb, 0, sizeof(p[i].pb));
			
		string s;
		
		while (cin>>s && isdigit(s[0])) {
			int pid, pbid, t;
			char tr,c;
			cin>>pid>>pbid>>t;
			cin>>c;
		
			pid--;
			p[pid].id = pid+1;
			
			if (!p[pid].aux)
				p[pid].aux = true;
			if (p[pid].pb[pbid][1] == 1)
				continue;
			if (c == 'C') {
				p[pid].pb[pbid][1] = 1;
				p[pid].sol++;
				p[pid].pun += p[pid].pb[pbid][0] * 20 + t;
			}
			else if (c == 'I'){
				p[pid].pb[pbid][0]++; 
			}
		}
		
		sort(p, &p[104]);
		
		for(int i = 0; i < 105; i++)
			if (p[i].aux)
				cout<<p[i].id<<p[i].sol<<p[i].pun);
		if(n > 0) 
			cout<<endl;
	}


	return 0;
}
