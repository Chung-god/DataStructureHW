/* (C) COPYRIGHT 2020 
*FileName : twocop.cpp
*Author : HyunChung, Park
*Version : 1
*Date : 09/15/2020
*/
#include <iostream>
#include <vector>
using namespace std;

//포인트  구조체 선언 
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

vector<Point> Points; //꼭짓점을 담을 벡터 
vector<Point> Road; //전체 경로를 담을 벡터 

 
//두 꼭짓점의 차이를 통해서 전체 경로 구성(Road) 
void cal(Point p1, Point p2) {
    /*
    만약 p1 = (3,3)  p2 = (3,7) 이면  마지막 else로 들어가게 됨. 
    그럼 (3,3) (3,4) (3,5) (3,6) 이 차례대로 PUSH 됨. 
    */
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
    
    int N; //전체  꼭짓점 갯수 
    int Place[2] = { 0 }; // C1, C2 를 담아두기 위한 배열  
    int time; //그래프를 순회하는 시간 
    bool toggle = false; // UP DOWN 을 결정하기 위해 BOOLEAN 값 
    int toggleNum = 0; // 두 번 이사 TOGGLE 이 발생하는지를 계산할 변수  
    
	cin >> N; //꼭짓점 갯수 입력 
    
	Point tempPoint; //점을 받아오기 위한 임시 변수 
     
    //N 만큼 받아오기  
    for(int i = 0; i < N; i++){
    	cin >> tempPoint.x >> tempPoint.y;
        Points.push_back(tempPoint);
	}
    
    //C1,C2 꼭짓점 선택 
    Point c1 = Points[0];
    Point c2 = Points[N / 2 - 1];
    
	//Road 를 설정하면서 c2의 전체 경로 인덱스 저장 
    for (int i = 0; i < Points.size(); i++) {
        if(i == (N/2 - 1))  
		    Place[1] = Road.size();  
		//전체 경로 계산 
        cal(Points[i % Points.size()], Points[(i + 1) % Points.size()]);
    }
	 
    cin >> time;
    
	//경로 탐 색  
    for (int i = 0; i < time; i++) {
    	//범위를 넘지 않기 위해 모듈러 연산
        int tempPlace1 = (Place[toggle] + 1) % Road.size();
        
    	//음수는 계산이 되지 않기 때문에 따로 처리 
	    int tempPlace2;
		if ((Place[!toggle] - 1) < 0) tempPlace2 = Road.size() - 1;
        else tempPlace2 = (Place[!toggle] - 1) % Road.size();
    	
    	//toggle 이 false 면 UP / true 면 Down  
		//만나는 두 경우에는 이동 방향이 바뀌어야함으로 toggle 값을 바꿈
		//하지만 만나는 지점은 그래프의 특성과 같은 거기를 이동하는 로봇의 성질 때문에 항상 동일
		//그러므로 toggle Number 가 2보다 커지면 불필요한 계산을 줄이기 위해 i 계산 
		 
    	//한 점에서 만나는 경우  
	    if (tempPlace1 == tempPlace2) {   
            Place[toggle] = tempPlace1;
            Place[!toggle] = tempPlace2;
            toggle = !toggle;
            toggleNum++;
        }
        //점과 점 사이에서 만나는 경우  
        else if (tempPlace1 == (Place[!toggle])) { 
            toggle = !toggle;
            toggleNum++;
        }
        //일반적인 이동을 하는 경우  
        else {
            Place[toggle] = tempPlace1;
            Place[!toggle] = tempPlace2;
        }
      	
      	//항상 만나는 두 지점을 알아낸 후의 계산 
		if(toggleNum >= 2){
			while(i < time){
				i = i + Road.size();
			}
			i -= Road.size();
			toggleNum = 0;
		}
    }
    //위치 출력  
    cout<< Road[Place[0]].x << " " << Road[Place[0]].y <<"\n"<< Road[Place[1]].x << " " << Road[Place[1]].y ;
}
