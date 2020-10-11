#include <iostream>
#include <vector>
using namespace std;

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

void cal(Point p1, Point p2){
    if(p1.x > p2.x)
        for(int x = p1.x; x > p2.x; x--)
            Road.push_back(Point(x,p1.y));      
    else if(p1.x < p2.x)
        for(int x = p1.x; x < p2.x; x++)
            Road.push_back(Point(x,p1.y));   
    else if(p1.y > p2.y)
        for(int y = p1.y; y > p2.y; y--)
            Road.push_back(Point(p1.x,y));   
    else
        for(int y = p1.y; y < p2.y; y++)
            Road.push_back(Point(p1.x,y));   
}

int main(){
	cin.tie(NULL);
    ios::sync_with_stdio(false);
    int K;
    int c1Place = 0;
    int c2Place;
    int time;
    bool meet = true;
    cin>>K;
    Point p1;
    int t = K;
    while(t--){
        cin>>p1.x>>p1.y;
        Points.push_back(p1);
    }
    Point c1 = Points[0];
    Point c2 = Points[K/2-1];
    cout<<c1.x<<" "<<c1.y<<"\n"<<c2.x<<" "<<c2.y<<"\n";

    for(int i = 0; i < Points.size();i++){
        if(Points[i].x == c2.x && Points[i].y == c2.y)
            c2Place = Road.size();
        cal(Points[ i % Points.size()],Points[(i+1) % Points.size()]);
    }

   // cout<<c2Place<<"\n";
   // cout<<Road[c2Place].x<<" "<<Road[c2Place].y<<"\n";
    cin>>time;
    for(int i = 1; i <= time; i++){
        if(meet){
            c1Place = (c1Place+1) % Road.size();
            c2Place = (c2Place-1) % Road.size();
        }else{
            c1Place = (c1Place-1) % Road.size();
            c2Place = (c2Place+1) % Road.size();
        }                
        if(c1Place >= c2Place){
            meet = !meet;
            i--;
        }
        cout<<Road[c1Place].x<<","<<Road[c1Place].y<<"\n";
        cout<<Road[c2Place].x<<","<<Road[c2Place].y<<"\n\n";
    }

}