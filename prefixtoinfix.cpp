#include<iostream>
#include<stack>
using namespace std;

int main() {
    string exp;
    cout<<"Enter prefix: ";
    cin>>exp;

    stack<string> st;

    for(int i=exp.length()-1;i>=0;i--) {
        if(isalnum(exp[i]))
            st.push(string(1,exp[i]));
        else {
            string a=st.top(); st.pop();
            string b=st.top(); st.pop();
            st.push("("+a+exp[i]+b+")");
        }
    }

    cout<<st.top();
}