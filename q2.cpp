#include <iostream>
using namespace std;

/*
6 states of DFA:
q0 -> q3 represent number of current consecutive 0's (0, 1, 2, 3)
q4 -> represents 3 consecutive 0's followed by any number of 1's
q5 - > dead state
*/

const int q0 = 0, q1 = 1, q2 = 2, q3 = 3, q4 = 4, dead = 5;
//initial state is state 0 -> zero consecutive 0's
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
			case q0:
				currState = (ch == '1')? q0 : q1;
			break;
			
			case q1:
				currState = (ch == '1')? q0 : q2;
			break;
			
			case q2:
				currState = (ch == '1')? q0 : q3;
			break;
			
			case q3:
				currState = (ch == '1')? q4 : q3;
			break;
			
			case q4:
				currState = (ch == '1')? q4 : dead;
			break;
			
			
		}

	}
	
	if(currState == q3 || currState == q4) cout<<"string is accepted"<<endl;
	else cout<<"string is rejected"<<endl;
	
	
	
	return 0;
}



