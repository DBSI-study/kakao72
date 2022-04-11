#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool isBalanced(string str){
    int value=0;
    for(int i=0;i<str.size();i++){
        str[i]=='(' ? value++ : value--;
    }
    return value==0 ? true : false;
}

bool isCorrect(string str){
    stack<char> st;
    st.push(str[0]);
    for(int i=0;i<str.size();i++){       
        if(st.top()=='('){
            if(str[i]==')') st.pop();
            else st.push(str[i]);
        }
        else return false;
    }
    return true;
}

string makeCorrect(string str){
    if(str.size()==0) return "";
    string ans="";
    string u="";
    string v="";
    string tmp="";
    
    for(int i=0;i<str.size();i++){
        tmp+=str[i];
        if(i%2==1 && isBalanced(tmp)){
            u=str.substr(0,i+1);
            v=str.substr(i+1);
            break;
        }
    }
    if(isCorrect(u)){
        ans+=u;
        ans+=makeCorrect(v);
    }
    else{
        ans="("+makeCorrect(v)+")";
        for(int i=1;i<u.size()-1;i++){
            ans+=(u[i]=='(' ? ')':'(');
        }
    }
    return ans;
}

string solution(string p) {
    string answer = "";
    answer=makeCorrect(p);    
    return answer;
}
