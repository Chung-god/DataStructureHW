 #include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;

vector<pair<int,int> >v;
pair<int,int> MAX(0,0);
pair<int,int> MIN(0,100001);
vector<int> ansV;
int N;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>N;
    while(N--){
        int fit,price;
        cin>>fit>>price;
        if(fit > MAX.first){
            MAX = make_pair(fit,price);
        }
        if(price < MIN.second){
            MIN = make_pair(fit,price);
        }
        v.push_back(make_pair(fit,price));
    }

    cout<<"Max :"<<MAX.first<<" "<<MAX.second<<"\n";
    cout<<"MIN :"<<MIN.first<<" "<<MIN.second<<"\n";

    for(int i=0; i < v.size();i++){
        if(v[i].first == MAX.first || v[i].second == MIN.second){
            cout<<v[i].first<<" "<<v[i].second<<"\n";
            continue;
        }
        
    }


}