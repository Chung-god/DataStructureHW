#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int M;
    vector<int> numArr;
    cin>>N>>M;
    while(N--){
        int temp;
        cin>>temp;
        numArr.push_back(temp);
    }
    sort(numArr.begin(),numArr.end());

    int total = 0;
    for(int i = 0; i < numArr.size()-2;i++){
        int tempTotal = 0;
        for(int j = 0; j < 3; j++){
            tempTotal += numArr[i+j];
        }
        cout<<tempTotal<<" ";
        if(M >= tempTotal && total < tempTotal){
            total = tempTotal;
        }
    }
    cout<<total;
}