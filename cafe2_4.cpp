#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> sit(1000003);
    vector<int> visit;
    int N;
    int numOfvisit;
    int inCafe = 0;
    cin>>N>>numOfvisit;
    
    while(numOfvisit--){
        int temp; //방문하는 고객의 ID 
        cin>>temp;
        bool over = false;
        int firstIndex;
        if(inCafe == 0){ //아무도 없을 때 
            sit[1] = temp;
            inCafe++;
            cout<<temp<<" 1\n";
            continue;
        }else if(inCafe==N){
            continue;
        }else{ //중복 확인 
            int t = 0;
            for(int i = 1; i <= sit.size(); i ++){
                if(t >= inCafe) break;
                if(sit[i]!=0){
                    if(t==0) firstIndex = i;
                    visit.push_back(i);
                    t++;
                    if(sit[i] == temp){
                        over = true;
                        sit[i] = 0;
                        inCafe--;
                        break;
                    }
                }
            }
        }
        visit.push_back(firstIndex+N);

        if(over){
            visit.clear();
            continue;
        }
        cout<<"vector :";
        for(int i = 0; i < visit.size(); i++){
            cout<<visit[i]<<" ";
        }
        cout<<"\n";
        
        int max = -999;
        int maxIndex;
        int tempResult;
        int result = 99999;
        for(int i = 0 ; i < visit.size()-1; i++){
            int interval = visit[i+1] - visit[i];
            tempResult = interval/2 + visit[i];
            if(tempResult > N) tempResult = tempResult % N;
            if(tempResult == N)
            cout<<"interval : "<<interval<<" maxIndex : "<<visit[i]<<" result : "<<tempResult<< "\n";

            if(max <= interval &&tempResult < result){
                max = interval;
                maxIndex = visit[i];
                result = tempResult;
            }
        }

        sit[result] = temp;  
        cout<<temp<<" "<<result<<"\n";
        visit.clear();
        inCafe++;
    }
}