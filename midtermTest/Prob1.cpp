#include <bits/stdc++.h>
#include <stdio.h>
using namespace std ;

// 2차원 vector of vector를 출력하는 함수.
void print_2dvec( vector<vector<int>> T){
   for(auto A : T ) {
        for(auto w : A ) {
            cout << w << " ";
        }
        cout << "\n";
   }
} // end of print_2dvec()

void read_2dvec(  vector<vector<int>> &T){
    int Lines, Elems, w ;
    T.clear();

    cin >> Lines ; //vector의 갯수 읽기
    for(int i=1 ; i <= Lines ; i ++){
        cin >> Elems ;  // 내부벡터의 원소 갯수
            vector<int> One = vector<int> () ;
              for( int j=1 ; j <= Elems ; j ++){
                    cin >> w ; // 각 벡터를 읽어
                    One.push_back( w ) ;  // 쳐 넣자.
              }
        T.push_back( One ) ;  
    }
} // end of read_2dvec( )

void rotate(vector<vector<int>> &v){
    if(v[0][0] != 0){
        v[v.size()-1].push_back(v[0][0]);
    }
    for(int i = 0; i < v.size()-1; i++){
        cout<<v[i][0];
        if(!v[i].empty()){
            v[i].erase(v[i].begin());
            v[i].push_back(v[i+1][0]);
        }
    }  

}

int main() {
    vector < vector<int> > v ;
    read_2dvec(v) ;
    rotate(v);
    print_2dvec(v) ;

   return 0;
}