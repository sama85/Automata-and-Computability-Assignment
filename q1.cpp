#include <iostream>
using namespace std;

//4 states of DFA
const int even0even1 = 0, even0odd1 = 1, odd0odd1 = 2, odd0even1 = 3;

//initial state is state 0 -> even 0's, even 1's
int currState = 0;
string input;

int main() {
	cin>>input;
	
	for(int i = 0; i < input.size(); ++i){
		char ch = input[i];
		if(ch != '0' && ch != '1'){
			cout<<"invalid input"<<endl;
			return 0;
		}
		switch(currState){
			case even0even1:
				currState = (ch == '0')? odd0even1 : even0odd1; 
			break;
			
			case even0odd1:
				currState = (ch == '0')? odd0odd1 : even0even1; 
			break;
			
			case odd0odd1:
				currState = (ch == '0')? even0odd1 : odd0even1; 
			break;
			
			case odd0even1:
				currState = (ch == '0')? even0even1 : odd0odd1; 
			break;
		}
	}
 
 if(currState == even0even1) cout<<"String is accepted"<<endl;
	else cout<<"string is rejected"<<endl;
	
	
	return 0;
}

