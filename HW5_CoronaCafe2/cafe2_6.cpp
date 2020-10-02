#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    vector<pair<int,int> > v;
    int N,M;
    cin>>N>>M;
    while(M--){
        int temp;
        cin>>temp;
        if(v.empty()){
            v.push_back(make_pair(1,temp));
            cout<<temp<<" 1\n";
            continue;
        }else{
            bool over = false;
            for(int i =0; i <v.size();i++){
                if(v[i].second == temp){
                    v.erase(v.begin()+i);
                    over = true;
                }
            }
            if(over)
                continue;
        }
        if(v.size()==N)
            continue;
        
        sort(v.begin(),v.end());
        v.push_back(make_pair(v[0].first + N,v[0].second));

        int minIndex = 99999;
        int max = -99;
        for(int i = 0; i < v.size()-1;i++){
            int interval = v[i+1].first - v[i].first;
            int tempResult = interval/2 + v[i].first;
            if(tempResult > N) tempResult = tempResult % N;
            
            if(max < interval){
                max = interval;
                minIndex = tempResult;
            }else if(max == interval){
                if(minIndex > tempResult)
                    minIndex = tempResult;
            }
        }

        v.erase(v.begin()+v.size()-1);

        v.push_back(make_pair(minIndex,temp));
        cout<<temp<<" "<<minIndex<<"\n";
    }
}