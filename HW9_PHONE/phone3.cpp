#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> maxPhone;
pair<int, int> minPhone;
stack<pair<int, int> > test;
vector<pair<int, int> > phoneV;
bool arr[1000001];
int N;
int main() {
    cin >> N;
    int MAX = 0;
    int MIN = 10000000;
    int time = 0;
    while (N > time) {
        int fit, price;
        cin >> fit >> price;
        phoneV.push_back(make_pair(fit, price));
        if (MIN > price) {
            MIN = price;
            minPhone.first = fit;
            minPhone.second = price;
         }
        if (MAX < fit) {
            MAX = fit;
            maxPhone.first = fit;
            maxPhone.second = price;
         }
        arr[time++] = 1;
    }

    test.push(minPhone);
    test.push(maxPhone);
    while (!test.empty()) {
        pair<int, int> tmp = test.top();
        pair<int, int> maxtmp(0,0);
        bool maxtmpchange = false;
        test.pop();

        for (int i = 0; i < phoneV.size(); i++) {
            if (!arr[i]) { continue; }//이미 아웃된 건 넘어감
            if (phoneV[i] == tmp) continue;
            if (phoneV[i] == minPhone || phoneV[i] == maxPhone) continue;
            
            if (phoneV[i].first <= tmp.first) {
                if (phoneV[i].second >= tmp.second) {
                    arr[i] = false;
                }
                else if(phoneV[i].first > maxtmp.first){
                    maxtmp = phoneV[i];
                    maxtmpchange = true;
                }
            }
        }
        if(maxtmpchange)
            test.push(maxtmp);
    }

    for (int i = 0; i < phoneV.size(); i++) 
        if (arr[i]) cout << i+1 << "\n";
    
}