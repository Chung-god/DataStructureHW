#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);

    list<int>::iterator iter;
    advance(iter,2);
    cout<<*iter;
    cout<<"Hello";
}