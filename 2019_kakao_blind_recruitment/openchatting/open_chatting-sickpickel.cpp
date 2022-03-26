#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> mp;
	string cmd;
	string nick_name;
	string user_id;
	
	for(string input: record){
		stringstream ss(input);
		ss >> cmd;
		ss >> user_id;
		if(cmd == "Enter" || cmd == "Change"){
			ss >> nick_name;
			mp[user_id]	= nick_name;
		}
	}
	
	for(string input : record){
		stringstream ss(input);
		ss >> cmd;
		ss >> user_id;
		
		if(cmd == "Enter"){
			answer.push_back(mp[user_id] + "님이 들어왔습니다.");
		}
		else if(cmd == "Leave"){
			answer.push_back(mp[user_id] + "님이 나갔습니다.");
		}
	}
	return answer;	
}