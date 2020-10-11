#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N; 
int K; 
vector<int> v;
int main(){
    cin>>N>>K;
    while(K--){
        int temp;
        cin>>temp;
        int findIndex = find(v.begin(),v.end(),temp) -v.begin();
        cout<<"findIndex "<<findIndex<<" size : "<<v.size() - 1<<"\n";
        if(findIndex != v.size() -1){
            v.erase(v.begin() + findIndex);
        }else if(v[findIndex] != temp){
            v.erase(v.begin() + findIndex);
        }

        v.push_back(temp);
        sort(v.begin(),v.end());
        for(int i = 0; i < v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        int index = find(v.begin(),v.end(),temp) - v.begin();
        cout<<(index-1) % v.size()<<" "<<index<<" "<<(index+1) % v.size()<<"\n";  
    }
}