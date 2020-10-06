#include<bits/stdc++.h>
using namespace std;


int check(char c){
	if(c=='+' || c=='-') return 1;
	else if (c == '*' || c=='/') return 2;
	else if (c=='^') return 3;
	else return -1;
}

int main(){
	stack<char> st;
	st.push('L');
	string s; cin>>s;
	string ans;
	for(unsigned int i=0; i<s.size();i++){
		if(int(s[i])>=97 && int(s[i]<=122)) ans+=s[i];

		else if(s[i]=='(') st.push(s[i]);

		else if(s[i]==')'){
			while(st.top() != 'L' && st.top() !='('){
				ans+=st.top();
				st.pop();
			}
			if (st.top()=='(') st.pop();
		}

		else{
			while(st.top() != 'L' && check(s[i])<=check(st.top())){
				ans+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(st.top()!='L'){
		ans+=st.top();
		st.pop();
	}
	cout<<(ans);
  return 0;
}
