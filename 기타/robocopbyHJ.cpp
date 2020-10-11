#include <iostream>
using namespace std;
int K, turn=0;
int X[50], Y[50], T[5];
int a[50]={0, };
int main() {
    cin >> K;
    for(int i=0; i<K; i++) {
        cin >> X[i] >> Y[i];
        if(i!=0) {
            turn += abs(X[i-1]-X[i]);
            turn += abs(Y[i-1]-Y[i]);
        }
        a[i] = turn;
    }
    turn += abs(X[0]-X[K-1]);
    turn += abs(Y[0]-Y[K-1]);
    cin >> T[0] >> T[1] >> T[2] >> T[3] >> T[4];
    for(int i=0; i<5; i++) {
        int k, diff;
        int t = T[i]%turn;
        for(k=0; k<K; k++) {
            if(a[k]>t) break;
        }
        diff = t-a[--k];
        if (!(X[k+1]-X[k])) cout << X[k] << " " << Y[k]+diff;
        else cout << X[k]+diff << " " << Y[k];
        cout << "\n";
    }
    return 0;
}