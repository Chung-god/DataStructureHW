#include <iostream>
#include <utility>
#include <unordered_set>
#include <list>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int num1, num2;
    int answer = 0;
    vector<pair<int, int>> inputdata;
    list<unordered_set<int>> data;
    inputdata.reserve(m);
    for (int i = 0; i < m; i++) {
        cin >> num1 >> num2;
        inputdata.push_back(make_pair(num1, num2));
    }

    for (int i = 0; i < m; i++) {
        bool included = false;
        for (unordered_set<int>& iter : data) {
            if (iter.find(inputdata[i].first) != iter.end() && iter.find(inputdata[i].second) != iter.end()) {
                cout << i + 1 << "\n";
                return 0;
            }
            else if (iter.find(inputdata[i].first) == iter.end() && iter.find(inputdata[i].second) == iter.end()){            }
            else if (iter.find(inputdata[i].first) == iter.end()) {
                for (unordered_set<int>& iter2 : data) {
                    if (iter != iter2 && !iter2.empty()) {
                        if (iter2.find(inputdata[i].first) != iter2.end()) {
                            iter.insert(iter2.begin(), iter2.end());
                            iter2.clear();
                            break;
                        }
                    }
                }
                iter.insert(inputdata[i].first);
                included = true;

            }
            else if (iter.find(inputdata[i].second) == iter.end()) {
                for (unordered_set<int>& iter2 : data) {
                    if (iter != iter2 && !iter2.empty()) {
                        if (iter2.find(inputdata[i].second) != iter2.end()) {
                            iter.insert(iter2.begin(), iter2.end());
                            iter2.clear();
                            break;

                        }
                    }
                }
                iter.insert(inputdata[i].second);
                included = true;
            }
        }
        if (!included) {
            unordered_set<int> intSet = { inputdata[i].first,inputdata[i].second };
            data.push_back(intSet);
        }
    }

    cout << 0 << "\n";
    return 0;

}