#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#define NONINF 0
#define INFECT 1
#define ISOLATE 2
#define RECOVER 3


class Person {
	int x, y;     // 사람의 좌표 (x, y각각 0~100사이)
	int state = 0;   // 감염 여부 (00-감염 안됨, 1-감염, 2 - 격리, 3-회복)  
	int time = 0;   //감염 경과 시간, state가 1로 바뀐 시점부터 1시간마다 1번씩 증가 
	/* 필요한 정보 선언하여 사용*/

    //출력을 위해 추가한 변수
    int index;
    
public:
    Person();
	Person(int i);
	void move();
	void updateState();
	bool isContact(Person p,double infDist);
	/* 필요한 정보 선언하여 사용*/

    //출력을 위해 추가한 함수
    int getIndex();
    int getX();
    int getY();
    int getState();
    int getTime();
    void setState(int newState);
    void setTime(int time);

};
Person::Person(){}
Person::Person(int i) {
    index  = i; //랜덤 함수 사용법 (0~10사이의 수) 
	x = rand() % 11;
	y = rand() % 11;
	/* 필요한 정보 선언하여 사용*/
}

void Person::move() {
    if(getState() == INFECT || getState() == NONINF){
        x = rand() % 11;
        y = rand() % 11;
    }
	/* 필요한 정보 선언하여 사용*/
}

bool Person::isContact(Person p, double infDist){
    return infDist >= sqrt((p.getX()-getX())^2 +(p.getY()-getY())^2);
}

void Person::updateState(){
    if(state != 0)
        state = (state + 1) % 4;
    if(time != 0)
        time = (time + 1) % 4;
}


int Person::getIndex(){
    return index;
}
int Person::getX(){
    return x;
}
int Person::getY(){
    return y;
}
int Person::getState(){
    return state;
}
int Person::getTime(){
    return time;
}
void Person::setState(int newState){
    state = newState;
}
void Person::setTime(int newTime){
    time = newTime;
}
/*출력예시에서 사용한 Print() 함수*/
void Print(Person p) { //객체 배열을 사용하였기때문에 배열의 인덱스 출력 함 
	cout << p.getIndex() << '\t' << p.getX() << '\t' << p.getY() << '\t' << p.getState() << '\t' << p.getTime() << endl;
}

int main() {
	/*simulation setting*/
	int people = 10;     // 존재하는 모든 사람
	int infect_num = 1;    // 존재 하는 사람 중 초기 감염자 
	int total_interval = 5;   // 총 5시간동안의 변화 관찰
	int interval = 1;    // 1시간 마다 1한번씩 위치가 바뀌고, 감염자 확인 및 감염 상태 변경
	double inf_Dist = 3;  // infection distance 
	
	srand(1);   //랜덤값을 위해 사용변경하지 말것
	
	/*필요한 코드를 작성 하세요*/

    Person arrOfPerson[20];
    bool arrOfInfectPerson[20];


    for(int i = 0; i < people; i++){
        arrOfPerson[i] = Person(i);
    }

    //초기 감염자
    arrOfPerson[infect_num].setState(INFECT);
    arrOfInfectPerson[0] = true;
    int numOfInfect = 1;

    cout<<"index   X   Y   S  T\n";
    for(int i = 0; i < people; i++){
        Print(arrOfPerson[i]);
    }


	for (int i = 0; i < total_interval; i++) {
		/*최초 감염자와 infection distance 이내에 있는 사람들을 확인하여 
		해당 사람을 감염자로 상태 변경하고  그 외 상태 업데이트  */


		cout << "============" << i + 1 << "h New cases=============" << endl;
		/* 새롭게 감염자된 사람들 좌표/상태/감염 시간 출력 */

        for(int j = 0; j < people; j++){
            bool isChanged = false;
            if(arrOfPerson[j].getState() == NONINF){
                for(int k = 0; k < sizeof(arrOfInfectPerson)/sizeof(bool); k++ ){
                    if(!arrOfInfectPerson[k]) continue;
                    bool isInf = arrOfPerson[j].isContact(arrOfPerson[k],inf_Dist);
                    if(isInf){
                        arrOfPerson[j].setState(INFECT);
                        arrOfPerson[j].setTime(1);
                        Print(arrOfPerson[j]);
                        arrOfInfectPerson[k] = true;
                        isChanged = true;
                        break;
                    }
                }
            }
            if(!isChanged){
                arrOfPerson[j].updateState();
                arrOfInfectPerson[j] = false;
            }
        }

		cout << "============= After " << i + 1 << "hours==========" << endl;
		/*전체 사람에 대한 좌표/상태/감염 시간 출력 */
        int arrOfState[4] = {0,0,0,0};
        for(int j = 0; j < people;j++){
            arrOfState[arrOfPerson[j].getState()]+=1;
        }
        
        for(int j = 0; j < 4; j++){
            cout<<arrOfState[i]<<" ";
        }
        cout<<"\n";

        for(int j = 0; j < people; j++){
            Print(arrOfPerson[j]);
        }


		//
		/*  이동 가능 한 사람들의  위치를 랜덤값을 이용하여 변경,
		격리 및 회복단계는 이동 불가*/

		
		cout << "========= After " << i + 1 << "h movement========" << endl;
		/*이동후 전체 사람들의 좌표 / 상태 / 감염 시간 출력 */
        for(int j = 0; j < people; j++){
            arrOfPerson[j].move();
            Print(arrOfPerson[j]);
        }
	}
	cout << "============ Final result==============" << endl;
	  /*현재 상태의 비감염자, 감염자, 격리, 회복된 사람들 수*/
	  /*누적 감염자, 격리된 숫자, 회복된 숫자 */

}