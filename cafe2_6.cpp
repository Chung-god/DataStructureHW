#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
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
            if(over){
                //cout<<"overlapped\n";
                continue;
            }
        }
        if(v.size()==N){
            //cout<<"full\n";
            continue;
        }
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
        // cout<<"vector :\n";
        // for(int i = 0; i < v.size(); i++){
        //     cout<<v[i].first<<" "<<v[i].second<<"\n";
        // }

        v.erase(v.begin()+v.size()-1);
        // cout<<"\nsecond vector :\n";
        // for(int i = 0; i < v.size(); i++){
        //     cout<<v[i].first<<" "<<v[i].second<<"\n";
        // }

        v.push_back(make_pair(minIndex,temp));
        cout<<temp<<" "<<minIndex<<"\n";
    }
}