#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
    int x;
    int y;
    Point() {};
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

vector<Point> Points;
vector<Point> Road;

void cal(Point p1, Point p2) {
    if (p1.x > p2.x)
        for (int x = p1.x; x > p2.x; x--)
            Road.push_back(Point(x, p1.y));
    else if (p1.x < p2.x)
        for (int x = p1.x; x < p2.x; x++)
            Road.push_back(Point(x, p1.y));
    else if (p1.y > p2.y)
        for (int y = p1.y; y > p2.y; y--)
            Road.push_back(Point(p1.x, y));
    else
        for (int y = p1.y; y < p2.y; y++)
            Road.push_back(Point(p1.x, y));
}



int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int K;
    int Place[2] = { 0 };
    int time;
    bool toggle = false;
    int toggleNum = 0;
    cin >> K;
    Point p1;
    int t = K;
    while (t--) {
        cin >> p1.x >> p1.y;
        Points.push_back(p1);
    }
    Point c1 = Points[0];
    Point c2 = Points[K / 2 - 1];
    cout << "c1 : " << c1.x << " " << c1.y << "\nc2: " << c2.x << " " << c2.y << "\n";

    for (int i = 0; i < Points.size(); i++) {
        if (Points[i].x == c2.x && Points[i].y == c2.y)
            Place[1] = Road.size();
        cal(Points[i % Points.size()], Points[(i + 1) % Points.size()]);
    }

    cout << "전체 경로" << "\n";
    for (int i = 0; i < Road.size(); i++) {
        cout << i << " : " << Road[i].x << " " << Road[i].y << "\n";
    }
    cout << "\n";
    //cout<<c2Place<<"\n";
    //cout<<Road[c2Place].x<<" "<<Road[c2Place].y<<"\n";
    cin >> time;
    //toggle 이 false = 0 이면 UP, true = 1이면 DOWN 
    for (int i = 0; i < time; i++) {
        int tempPlace1 = (Place[toggle] + 1) % Road.size();
        int tempPlace2;
        if ((Place[!toggle] - 1) < 0) tempPlace2 = Road.size() - 1;
        else tempPlace2 = (Place[!toggle] - 1) % Road.size();
       // cout << "tp1: " << tempPlace1 << " tp2: " << tempPlace2 << "\n";
        if (tempPlace1 == tempPlace2) { //한 점에서 만났을 때  
            Place[toggle] = tempPlace1;
            Place[!toggle] = tempPlace2;
            toggle = !toggle;
            toggleNum++;
            cout <<"t"<<i+1<<": "<<"One Point :// C1 : " << Road[Place[0]].x << ", " << Road[Place[0]].y << "\nC2 : " << Road[Place[1]].x << ", " << Road[Place[1]].y << "\n";
        }
        else if (tempPlace1 == (Place[!toggle])) { //가로 질렀을때 
            toggle = !toggle;
            toggleNum++;
            cout << "t"<<i<<": "<<"Cross ://C1 : " << Road[Place[0]].x << ", " << Road[Place[0]].y << "\nC2 : " << Road[Place[1]].x << ", " << Road[Place[1]].y << "\n";
        }
        else {
            Place[toggle] = tempPlace1;
            Place[!toggle] = tempPlace2;
        }
        //cout<< "t"<<i<<": "<<Place[0]<<" "<<Place[1]<<"\n";
       // cout << "t" << i << "\n" << "C1: " << Road[Place[0]].x << ", " << Road[Place[0]].y << "\nC2 : " << Road[Place[1]].x << ", " << Road[Place[1]].y << "\n\n";
		
		/*
		if(toggleNum >= 2){
			cout<<"We need to stop\n";
			while(i < time){
				i = i + Road.size();
			}
			i -= Road.size();
			cout<<"i = "<<i<<"\n";
			toggleNum = 0;
		}*/
		
    }

    cout << "Ans :// C1 : " << Road[Place[0]].x << ", " << Road[Place[0]].y << "\nC2 : " << Road[Place[1]].x << ", " << Road[Place[1]].y << "\n";
}
