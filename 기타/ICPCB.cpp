#include <iostream>
using namespace std;

int main(){
    int N;
    int limit;
    long long int result = 1;
    cin>>N;

    if(N%2==0)
        limit = N/2;
    else
        limit = N/2 +1;
    
    for(int i = 1; i <= limit; i++)
            result = (result * 2)  % 16769023;
    cout<<result;
}