#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word, vector<string> pages) {
    int answer = 0, pageidx = 0;
   	
    vector<int> outsideLink, linkPoint, defaultPoint;
    map<string, int> pageIdx;
    for(string page : pages){
        // 페이지 전체 tolower
        
        
       	// 페이지 이름 인덱싱
        int pageNameBegin = page.find("https") - page.begin();
        int pageNameEnd = page.find("\"", pageNameBegin) - page.begin();
       	
       	string pageName = page.substr(pageNameBegin, pageNameEnd - pageNameBegin);
        pageIdx[pageName] = pageidx++;
        
        // 기본점수 구하기
        int idx = 0, defPoint = 0;
        while(1){
            auto it = page.find(word, idx);
            if(it == string::npos) break;
            idx = it - page.begin();
            if((idx == 0 || !isalpha(page[idx - 1])) 
&& (idx + word.length() + 1 == page.length() || !isalpha(page[idx + word.length()]))) defPoint++;
        }
        defaultPoint.push_back(defPoint);
        
        // 외부 페이지 링크 확인(외부 링크 수, 참조된 횟수 저장)
        
        
    }
    
    return answer;
}