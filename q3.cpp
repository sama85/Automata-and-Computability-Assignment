#include <iostream>
#include <stack>
using namespace std;

/*
4 states of the PDA
q0 -> represents processing the first half of the input and pushing it to the stack
q1 -> represents processing the second half of the string and popping from stack
q2 -> represents accepted state where stack is empty and all input consumed
q3 -> dead state
*/
const int q0= 0, q1 = 1, q2 = 2, dead = 3;
//initial state is state 0 -> zero consecutive 0's
int currState = 0;
string input;
stack<char> PDAStack;

int main() {
	
	cin>>input;
	for(int idx = 0; idx < input.size(); ++idx){
		int ch = input[idx];
		if(ch != '0' && ch != '1'){
			cout<<"invalid input"<<endl;
			return 0;
		}
		
		switch(currState){
			case q0:
				if(idx == input.size() / 2 && input.size() % 2 == 1)
					currState = q1;	
				else if(idx == input.size() / 2 - 1 && input.size() % 2 == 0){
					PDAStack.push(ch);
					currState = q1;	
				}
				
				else PDAStack.push(ch);
			break;
			
			case q1:
				if(!PDAStack.empty()){
					char top = PDAStack.top();
					if(top == ch && idx == input.size() - 1){
						currState = q2;
						PDAStack.pop();
					}
					else if(top == ch) PDAStack.pop();
					
					else currState = dead;
				}
				else currState = dead;
			break;
			
			case q2:
				if(!PDAStack.empty())
					currState = dead;
			break;
		}
	}
	
	if(currState == q2) cout<<"string is accepted"<<endl;
	else cout<<"string is rejected"<<endl;
	

	return 0;
}

