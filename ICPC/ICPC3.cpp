#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int MIN = 1000000;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;
    int range = 2*N;
    while(range--){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int size = v.size();
    for(int i =0; i < v.size()/2; i++){
        int temp = v[i] + v[size-1-i];
        if(temp < MIN) MIN = temp;
    }
    cout<<MIN;
}