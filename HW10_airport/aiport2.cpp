#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<queue<int> > v;
int main(){
    int N;
    cin>>N;
    int time = N;
    while(time--){
        queue<int> tempQ;
        int temp;
        do{
            cin>>temp;
            tempQ.push(temp);
        }while(temp!=0);
        v.push_back(tempQ);
    }
    while(true){
        int min = 1000000;
        int minIndex = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i].front() == 0)
                continue;
            if(v[i].front() < min){
                min = v[i].front();
                minIndex = i;
            }
        }
        if(v[minIndex].front() == 0) return 0;
        cout<<v[minIndex].front()<<"\n";
        v[minIndex].pop();
    }
}