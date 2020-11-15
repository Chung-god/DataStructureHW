#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<char> InVec;
vector<char> PVec;

vector<char> ansVec;

int p;
void findPost(int begin, int end) {
    if (begin > end) return;
    if (p == InVec.size()) return;
    p++;
    char word = PVec[p];
    for (int i = begin; i <= end; i++) {
        if (InVec[i] == word) {
            findPost(begin, i - 1);
            findPost(i + 1, end);
            ansVec.push_back(word);
        }
    }
}

void findPre(int begin, int end) {
    if (begin > end) return;
    if (ansVec.size() == InVec.size()) return;

    
    char word;
    int j;
    bool b = false;
    for (int i = 0; i < PVec.size(); i++) {
        for (j = begin; j <= end; j++) {
            if (PVec[i] == InVec[j]) {
                word = PVec[i + end - begin];
                b = true;
                break;
            }
        }
        if (b) break;
    }
    for (int i = begin; i <= end; i++) {
        if (InVec[i] == word) {
            ansVec.push_back(word);
            findPre(begin, i - 1);
            findPre(i + 1, end);
        }
    }
}
int main() {
    string temp;
    string sec;
    string first;
    for(int i = 0; i < 2; i++){
        cin >> first >> temp;
        if(first != "Inorder" ) sec = first;
        if(first == "Inorder"){
            for (int i = 0; i < temp.length(); i++) {
                InVec.push_back(temp[i]);
            }
        }else{
            for (int i = 0; i < temp.length(); i++) {
                PVec.push_back(temp[i]);
            }
        }
    }
    if (sec == "Preorder") {
        p = -1;
        findPost(0, InVec.size() - 1);
        cout<<"Postorder ";
    }
    else {
        p = InVec.size();
        findPre(0,p-1);
        cout<<"Preorder ";
    }
    
    for (auto i : ansVec)
        cout << i;
}