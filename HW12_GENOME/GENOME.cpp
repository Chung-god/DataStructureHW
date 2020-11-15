#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
using namespace std;
vector<string> mytoken = { "front","cut","double","report","back","flip" };
int get_type(string k) {
    for (int i = 0; i < mytoken.size(); i++) {
        if (mytoken[i] == k) return i;
    }
}
int main() {
    ifstream r;
    r.open("sapiens.txt");
    char str[sizeof(r)] = { '\0' };
    list<char> gl;
    if (r.good()) {
        int l = 0;
        char sT[sizeof(r)] = { '\0' };
        while (!r.eof()) {
            r.getline(str, sizeof(r));
            if(l++==0) continue;
            for (int i = 0; str[i] != '\0'; i++)
                gl.push_back(str[i]);
        }
    }
    int N;
    cin >> N;
    while (N--) {
        string inst;
        int t1, t2;
        cin >> inst >> t1 >> t2;
        int mytype = get_type(inst);
        if (t1 >= gl.size() || t2 >= gl.size()) {
            if (mytype != 3) continue;
            if (t1 > gl.size()) {
                cout << "NONE\n";
                continue;
            }
            if (t2 > gl.size()) 
                t2 = gl.size();
        }
        list<char>::iterator e = gl.begin();
        advance(e, t1 - 1);
        list<char>::iterator t = gl.begin();
        advance(t, t2);
        list<char> tl;
        for (int i = 0; i <= t2 - t1; i++) 
            tl.push_back(*e++);
        if (mytype != 2 &&mytype!=3) {
            e = gl.begin();
            advance(e, t1 - 1);
            gl.erase(e, t);
        }
        if (mytype == 5) tl.reverse();
        switch (mytype) {
        case 0:
            gl.splice(gl.begin(), tl);
            break;
        case 4:
            gl.splice(gl.end(), tl);
            break;
        case 1:
            break;
        case 2: case 5:
            e = gl.begin();
            advance(e, t1 - 1);
            gl.splice(e, tl);
            break;
        case 3:
            for (e = tl.begin(); e != tl.end(); e++)
                cout << *e;
            cout << "\n";
            break;
        }
    }
}