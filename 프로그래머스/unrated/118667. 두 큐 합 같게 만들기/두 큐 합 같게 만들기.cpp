#include <string>
#include <vector>

using namespace std;


int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int ct=0;
    int max_sz=3*queue1.size();
    
    long long sum1=0;
    for(int i=0;i<queue1.size();i++){
        sum1=sum1+queue1[i];
    }
    long long sum2=0;
    for(int i=0;i<queue2.size();i++){
        sum2=sum2+queue2[i];
    }
    int q1idx=0;
    int q2idx=0;
    while(!queue1.empty()&&!queue2.empty()){
        
        if(sum1>sum2){
            long long temp=queue1[q1idx];
            sum1=sum1-temp;
            sum2=sum2+temp;
            q1idx++;
            queue2.push_back(temp);
            ct++;
            if(ct>max_sz||queue1.empty()||queue2.empty()){
                answer=-1;
                break;
            }
        }else if(sum1<sum2){
            long long temp=queue2[q2idx];
            sum1=sum1+temp;
            sum2=sum2-temp;
            q2idx++;
            queue1.push_back(temp);
            ct++;
            if(ct>max_sz||queue1.empty()||queue2.empty()){
                answer=-1;
                break;
            }
        }
        else if(sum1==sum2){
            answer=ct;
            break;
        }      
    } 
    return answer;
}