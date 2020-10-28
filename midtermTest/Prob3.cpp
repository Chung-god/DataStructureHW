#include <bits/stdc++.h>
using namespace std ;

int N ;
vector <stack<int>> YARD ; //  N���� �����̳� ��ġ�� �����

void read_yard( ) ;
void show_yard( vector <stack<int>> ) ;

int main() {

    read_yard( ) ;
    //show_yard( YARD ) ;
    /* ----------------
       ���⿡�� �����̳ʸ� �����Ͻÿ�.
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
        stemp = stack<int>()  ;  //  �� ������ �ϳ��� ����.
        cout <<  ++i << " > " ; // ����� ����
        while( !w.empty()) { //body
           val = w.top( ) ;
           stemp.push( val ) ;
           w.pop();
        } // end of while( )
        // �ٽ� ������ �����, �ؿ������� �����ֱ� ���Ͽ�

        while( !stemp.empty()) { //body
           val = stemp.top( ) ;
           cout << " " << val ;
           stemp.pop();
        } // end of while( )
        cout <<"\n" ;

    } // end of for( w )

 } // end of print_yard( )




