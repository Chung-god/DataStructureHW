#include <iostream>
#include <vector>
using namespace std;

/*
Point �� x,y ���� ��� Ŭ������. 
�̸� ��� ���Ͱ� Points �̴�.
���������� �Է¹��� �� �� ���� ���ؼ� ��θ� �����ϰ� �ȴ�. 
�ε忡�� ��� ����� ���� �� �ִ�. 
*/

int k;
class Point{
public:
    int x;
    int y;

    Point(){};
    Point(int _x,int _y){
        x = _x;
        y = _y;
    }
};

vector<Point> Points;
vector<Point> Road;
int N;

void cal(Point p1, Point p2){
    if(p1.x > p2.x){
        int x;
        for(x = p1.x; x > p2.x; x--){
            Road.push_back(Point(x,p1.y));   
           // cout<<x<<","<<p1.y<<"\n";
        }
        for(int i =0; i < k;i++)
            Road.push_back(Point(x,p1.y));   
    }else if(p1.x < p2.x){
        int x;
        for(x = p1.x; x < p2.x; x++){
            Road.push_back(Point(x,p1.y));   
           // cout<<x<<","<<p1.y<<"\n";
        }
        for(int i =0; i < k;i++)
            Road.push_back(Point(x,p1.y));   
    }else if(p1.y > p2.y){
        int y;
        for(y = p1.y; y > p2.y; y--){
            Road.push_back(Point(p1.x,y));   
            //cout<<p1.x<<","<<y<<"\n";
        }
        for(int i =0; i < k;i++)
            Road.push_back(Point(p1.x,y));   
    }else{
        int y;
        for(y = p1.y; y < p2.y; y++){
            Road.push_back(Point(p1.x,y));   
            //cout<<p1.x<<","<<y<<"\n";
        }
        for(int i =0; i < k;i++)
            Road.push_back(Point(p1.x,y));   
    }

}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N>>k;
    Point p1;
    while(N--){
        cin>>p1.x>>p1.y;
        Points.push_back(p1);
    }
    int end;
    cin>>end;

    for(int i = 0; i < Points.size();i++){
        int seq = i % Points.size();
        int nextSeq = (i+1) % Points.size();
        //cout<<seq<<" "<<nextSeq<<"\n";
        cal(Points[seq],Points[nextSeq]);
    }
    
    // cout<<"end"<<end<<"\n";
    // for(int i = 0; i < Road.size();i++){
    //     cout<<Road[i].x<<" "<<Road[i].y<<"\n";
    // }
    cout<<Road[end%Road.size()].x<<" "<<Road[end%Road.size()].y;


    // for(int i = 0; i <5; i++){
    //     int temp;
    //     cin>>temp;
    //     cout << Road[temp % Road.size()].x <<" "<< Road[temp % Road.size()].y<<"\n";
    // }
}