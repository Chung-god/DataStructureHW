#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > v;
int N;

int main(){
    int N;
    cin>>N;
    while(N--){
        int temp;
        cin>>temp;
        vector<int> tempV;
        while(temp--){
            int t;
            cin>> t;
            tempV.push_back(t);
        }
        v.push_back(tempV);
    }

    for(int i = 0; i < v.size();i++){
        for(int j = 0; j < v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}