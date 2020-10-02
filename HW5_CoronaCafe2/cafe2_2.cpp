#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> sit(1000001);
    int N;
    int numOfvisit;
    int inCafe = 0;
    cin>>N>>numOfvisit;
    
    while(numOfvisit--){
        int temp; //방문하는 고객의 ID 
        cin>>temp;
        bool over = false;
        if(inCafe == 0){ //아무도 없을 때 
            sit[1] = temp;
            inCafe++;
            cout<<temp<<" 1\n";
            continue;
        }else if(inCafe ==N){
            continue;
        }else{ //중복 확인 
            int t = 0;
            for(int i = 1; i <= sit.size(); i ++){
                if(t >= inCafe) break;
                if(sit[i]!=0){
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
        if(over) continue;

        int max = -1;
        int maxIndex;
        int n = 0;
        int lastIndex;
        int before;
        inCafe++;
        for(int i = 1; i <= sit.size(); i++){
            if(sit[i]!=0){
                if(n == 0){
                    before = i;
                    lastIndex = i + N;
                    sit[i+N] = sit[i];
                    n++;
                    continue;
                }else if(n == inCafe){
                    if(max < lastIndex - before){
                        max = lastIndex - before;
                        maxIndex = lastIndex - N;
                    }
                    break;
                }else{
                    if(max < i - before){
                        max = i - before;
                        maxIndex = before;
                    }
                    before = i;
                    n++;
                }
            }
        }
        sit[lastIndex] = 0;
        int result = maxIndex + max/2;
        if(result > N) result = result % N;
        cout<<temp<<" "<<result <<"\n";
        sit[result] = temp;
    }
}