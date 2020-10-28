#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int,int>,int > > v;
int N;
vector<pair<int,int> > first;

int main(){
    cin>>N;
    first.push_back(make_pair(1,2));
    first.push_back(make_pair(1,1));
    first.push_back(make_pair(2,1));
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < N-1; j++){
            int temp;
            cin>>temp;
            v.push_back(make_pair(make_pair(first[i].first + j,first[i].second+j),temp));
        }
        if(i==1){
        	int temp;
        	cin>>temp;
			v.push_back(make_pair(make_pair(first[i].first + j,first[i].second+j),temp));
		}
    }
    for(int k = 0; k < 6; k++){
        int a,b;
        cin>>a>>b;
        
        if(a < 0 || a > N || b < 0 || b > N ){
        	cout<<"Error\n";
        	continue;
		}
        bool found = false;
        for(int i =0; i < v.size(); i++ ){
            if(v[i].first.first == a && v[i].first.second == b){
                cout<<v[i].second<<" ";
                found = true;
                break;
            }
        }
        if(!found)
        	cout<<"0\n";
    }
}