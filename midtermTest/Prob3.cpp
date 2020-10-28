#include <bits/stdc++.h>
using namespace std ;

int N ;
vector <stack<int>> YARD ; //  N개의 컨테이너 적치장 저장소

void read_yard( ) ;
void show_yard( vector <stack<int>> ) ;

int main() {

    read_yard( ) ;
    //show_yard( YARD ) ;
    /* ----------------
       여기에서 컨테이너를 정리하시오.
    -----------------*/
    while(true){
        int max = 0;
        int maxIndex = 0;
        int min = 10000000;
        int minIndex =0;
        for(int i = 0 ;i < YARD.size(); i++){
            if(max <= YARD[i].size()){
                if(max == YARD[i].size()){
                    if(v[maxIndex].top() > v[i].top()){
                        continue;
                    }
                }
                max = YARD.size();
                maxIndex = i;
            }
        }
        for(int i = 0; i < YARD.size();i++){
            if(min <= YARD[i].size()){
                if(min == YARD[i].size()){
                    if(v[minIndex].top() > v[i].top()){
                        continue;
                    }
                }
                min = YARD.size();
                minIndex = i;
            }
        }
        if(YARD[maxIndex].size() - YARD[minIndex] <= 1) return 0;
        int top = YARD[maxIndex].top();
        YARD[maxIndex].pop();
        YARD[minIndex].push(top);
    }
   show_yard(YARD); 
    return(0) ;

} // end of main( )


void read_yard( ) {
    int index, elems, value ;
    cin >> N ;
    stack<int> mystk ;

    for(int i=1 ; i <= N; i++){
        mystk = stack<int>() ;
        cin >> elems ;
        for(int j = 1; j <= elems ; j++) {
            cin >> value ;
            mystk.push( value ) ;
        }
        YARD.push_back( mystk ) ;
    }

} // end of read_yard( )

void show_yard( vector<stack<int>> OUT ){
    int i, val ;
    stack <int> stemp ;
    i=0 ;

    for(auto w : OUT ) {
        stemp = stack<int>()  ;  //  빈 스택을 하나더 만듬.
        cout <<  ++i << " > " ; // 제출시 제거
        while( !w.empty()) { //body
           val = w.top( ) ;
           stemp.push( val ) ;
           w.pop();
        } // end of while( )
        // 다시 꺼내서 출력함, 밑에서부터 보여주기 위하여

        while( !stemp.empty()) { //body
           val = stemp.top( ) ;
           cout << " " << val ;
           stemp.pop();
        } // end of while( )
        cout <<"\n" ;

    } // end of for( w )

 } // end of print_yard( )




