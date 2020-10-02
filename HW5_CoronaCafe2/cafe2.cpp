#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int N;
int numOfvisit;
int inCafe = 0;
int sit[1000002];
set<int> customerSet;
set<int>::iterator iter;
vector<int> v;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N>>numOfvisit;
    int temp;
    cin>>temp;
    sit[1] = temp;
    inCafe++;

    while(--numOfvisit){
        cin>>temp;
        
        iter = customerSet.find(temp);
        
        if(iter != customerSet.end()){
            for(int i = 1; i < N+1; i++){
                sit[i] = 0;
            }
            customerSet.erase(iter);
            inCafe--;
            continue;
        }else{
            if(inCafe == N) continue;  
            customerSet.insert(temp);
            inCafe++;
        }

        for(int i = 1;i <= N+1 ;i++){
            if(sit[i]!=0) v.push_back(i);
        }
       // if(!v.empty()) v.push_back(v[0]+N);

        for(int i = 0; i <v.size();i++){
            cout<<v[i]<<" ";
        }

        cout<<"\n";
        int max = -999;
        int maxIndex;
        for(int i = 0; i < v.size() - 1; i++){
            int interval = v[i+1] - v[i];
            if(interval > max){
                max = interval;
                maxIndex = i;
            }
        }
        //sit[maxIndex + max/2] = temp;
        cout<<"maxIndex "<<maxIndex<<" max "<<max<<"\n";
        v.clear();
    }

}