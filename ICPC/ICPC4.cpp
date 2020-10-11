#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<set<int> > setV;
pair<int,int> twoPoint;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int pointN;
    int inputN;
    int time =0 ;
    cin>>pointN>>inputN;

    while(inputN--){
        time++;
        int p1,p2;
        cin>>p1>>p2;
        twoPoint(make_pair(p1,p2));
        for(int i = 0; i < v.size();i++){
            for(int j = 0; j < v[i].size();j++){
                if(v[i].find(p1) != v[i].end()){//���� ã��
                    if(v[i].find(p2)!=v[i].end()){//���� �� �ȿ� ����
                        cout<<time;
                        exit(0);
                    }else{
                        for(int k = 0; k < v.size(); k++){
                            if(i==k) continue;
                            if(v[k].find(p2) != v[i].end()){//�ٸ� �¿��� �� ã��
                                v[i].union(v[k])
                                v[k].remove()
                            }else{//�ٸ� �¿��� �� �� ã�� 
                                v[i].add(p2);
                            }
                        }
                    }
                }
            }
        }
    }

}