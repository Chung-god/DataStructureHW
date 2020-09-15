/* (C) COPYRIGHT 2020 
*FileName : twocop.cpp
*Author : HyunChung, Park
*Version : 1
*Date : 09/15/2020
*/
#include <iostream>
#include <vector>
using namespace std;

//����Ʈ  ����ü ���� 
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

vector<Point> Points; //�������� ���� ���� 
vector<Point> Road; //��ü ��θ� ���� ���� 

 
//�� �������� ���̸� ���ؼ� ��ü ��� ����(Road) 
void cal(Point p1, Point p2) {
    /*
    ���� p1 = (3,3)  p2 = (3,7) �̸�  ������ else�� ���� ��. 
    �׷� (3,3) (3,4) (3,5) (3,6) �� ���ʴ�� PUSH ��. 
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
    
    int N; //��ü  ������ ���� 
    int Place[2] = { 0 }; // C1, C2 �� ��Ƶα� ���� �迭  
    int time; //�׷����� ��ȸ�ϴ� �ð� 
    bool toggle = false; // UP DOWN �� �����ϱ� ���� BOOLEAN �� 
    int toggleNum = 0; // �� �� �̻� TOGGLE �� �߻��ϴ����� ����� ����  
    
	cin >> N; //������ ���� �Է� 
    
	Point tempPoint; //���� �޾ƿ��� ���� �ӽ� ���� 
     
    //N ��ŭ �޾ƿ���  
    for(int i = 0; i < N; i++){
    	cin >> tempPoint.x >> tempPoint.y;
        Points.push_back(tempPoint);
	}
    
    //C1,C2 ������ ���� 
    Point c1 = Points[0];
    Point c2 = Points[N / 2 - 1];
    
	//Road �� �����ϸ鼭 c2�� ��ü ��� �ε��� ���� 
    for (int i = 0; i < Points.size(); i++) {
        if(i == (N/2 - 1))  
		    Place[1] = Road.size();  
		//��ü ��� ��� 
        cal(Points[i % Points.size()], Points[(i + 1) % Points.size()]);
    }
	 
    cin >> time;
    
	//��� Ž ��  
    for (int i = 0; i < time; i++) {
    	//������ ���� �ʱ� ���� ��ⷯ ����
        int tempPlace1 = (Place[toggle] + 1) % Road.size();
        
    	//������ ����� ���� �ʱ� ������ ���� ó�� 
	    int tempPlace2;
		if ((Place[!toggle] - 1) < 0) tempPlace2 = Road.size() - 1;
        else tempPlace2 = (Place[!toggle] - 1) % Road.size();
    	
    	//toggle �� false �� UP / true �� Down  
		//������ �� ��쿡�� �̵� ������ �ٲ��������� toggle ���� �ٲ�
		//������ ������ ������ �׷����� Ư���� ���� �ű⸦ �̵��ϴ� �κ��� ���� ������ �׻� ����
		//�׷��Ƿ� toggle Number �� 2���� Ŀ���� ���ʿ��� ����� ���̱� ���� i ��� 
		 
    	//�� ������ ������ ���  
	    if (tempPlace1 == tempPlace2) {   
            Place[toggle] = tempPlace1;
            Place[!toggle] = tempPlace2;
            toggle = !toggle;
            toggleNum++;
        }
        //���� �� ���̿��� ������ ���  
        else if (tempPlace1 == (Place[!toggle])) { 
            toggle = !toggle;
            toggleNum++;
        }
        //�Ϲ����� �̵��� �ϴ� ���  
        else {
            Place[toggle] = tempPlace1;
            Place[!toggle] = tempPlace2;
        }
      	
      	//�׻� ������ �� ������ �˾Ƴ� ���� ��� 
		if(toggleNum >= 2){
			while(i < time){
				i = i + Road.size();
			}
			i -= Road.size();
			toggleNum = 0;
		}
    }
    //��ġ ���  
    cout<< Road[Place[0]].x << " " << Road[Place[0]].y <<"\n"<< Road[Place[1]].x << " " << Road[Place[1]].y ;
}
