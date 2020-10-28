#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<queue<int> > qV;
int N;
int main(){
    cin >> N;
    while(N--){
        queue<int> tempQ;
        int temp;
        do{
            cin>>temp;
            tempQ.push(temp);
        }while(temp!=0);
        qV.push_back(tempQ);
    }

    while(!qV.empty()){
        int min = 1000000;
        int minIndex = 0;
        int index = qV.size();
        //cout<<index<<"\n";
        vector<int> remove;
        for(int i = 0; i < index; i++){
            if(qV[i].front() == 0){
                remove.push_back(i);
            }
            else if(qV[i].front() < min){
                min = qV[i].front();
                minIndex = i;
            }
        }
        for(int j = 0; j < remove.size(); j++){
            qV.erase(qV.begin()+remove[j]);
        }
        if(qV[minIndex].front() != 0)
            cout<<qV[minIndex].front()<<"\n";
        qV[minIndex].pop();
    }
}