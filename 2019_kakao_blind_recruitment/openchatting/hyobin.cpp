#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<vector<string>> command;
	map<string, string> user;

	for (int i=0;i<record.size();i++) {
		vector<string> temp;
		int l=0,r=0;
		for (int j=0;j<=record[i].size();j++) {
			if (record[i][j]==' '||j==record[i].size()) {
				r=j;
				temp.push_back(record[i].substr(l,r-l));
				l=j+1;
			}
		}
		command.push_back(temp);
	}

	for (int i=0;i<command.size();i++) {
		if (command[i][0]=="Enter"||command[i][0]=="Change") {
			user[command[i][1]]=command[i][2];
		}
	}

	for (int i=0;i<command.size();i++) {
		string temp=user[command[i][1]];
		if (command[i][0]=="Enter") {
			temp+="님이 들어왔습니다.";
		}
		else if(command[i][0]=="Leave") {
			temp+="님이 나갔습니다.";
		}
		else{
			continue;
		}
		answer.push_back(temp);
	}
	return answer;
}
