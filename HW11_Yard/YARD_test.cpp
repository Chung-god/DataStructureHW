#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int N; 
    vector<stack<int> > sv;  
    cin >> N;
    while (N--) {
        int tempSize;
        cin >> tempSize;
        stack<int> tempStack;
        while (tempSize--) {
            int temp;
            cin >> temp;
            tempStack.push(temp);
        }
        sv.push_back(tempStack);
    }
    while (true) {
		int max = 0, maxIndex = 0,minIndex = 0;
        for (int i = 0; i < sv.size(); i++) {
            if(sv[i].empty()){}
            else if (sv[i].size() > sv[maxIndex].size()) {
                maxIndex = i;
                max = sv[i].top();
            }
            else if (sv[i].size() == sv[maxIndex].size()) {
                if (sv[maxIndex].top() < sv[i].top()) {
                    maxIndex = i;
                    max = sv[i].top();
                }
            }
            if (sv[i].size() < sv[minIndex].size()) {
                minIndex = i;
            }
        }
        if (sv[maxIndex].size() - sv[minIndex].size() <= 1) break;
        int move = sv[maxIndex].top();
        sv[maxIndex].pop();
        sv[minIndex].push(move);
    }

    for (int i = 0; i < sv.size(); i++) {
        cout << i+1 << " > ";
        if (sv[i].empty()) {
            cout << "0\n";
            continue;
        }
        vector<int> tempV;
        while (!sv[i].empty()) {
            tempV.push_back(sv[i].top());
            sv[i].pop();
        }
        for(int j = tempV.size()-1; j >= 0;j--)
            cout<<tempV[j]<<" ";
        cout << "\n";
    }
}