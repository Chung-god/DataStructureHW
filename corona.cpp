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
    Person(); //이 생성자가 없으면 초기 배열 생성이 되지 않음
    Person(int i);
    void move();
    void updateState();
    bool isContact(Person p, double infDist);
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
Person::Person() {}
Person::Person(int i) {
    //index 를 생성자와 함께 설정해줌
    index = i;
     //랜덤 함수 사용법 는0~10사이의 수) 
    x = rand() % 11;
    y = rand() % 11;
    /* 필요한 정보 선언하여 사용*/
}

void Person::move() {
    if (getState() == INFECT || getState() == NONINF) { //상태가 격가, 회복 이동일때는 불가
        x = rand() % 11;
        y = rand() % 11;
    }
    /* 필요한 정보 선언하여 사용*/
}

//inf_Dist 안에 있으면 접촉 true
bool Person::isContact(Person p, double infDist) {
    return infDist > sqrt(pow((p.getX() - getX()),2) + pow((p.getY() - getY()),2));
}

void Person::updateState() { // 신규 감염자는 updateState를 호출하지 않음
    if (state != time) // 최초 감염자는 state = 1, time = 0 이기때문에
        time = state; // state = time 둘다 1로 설정해주어야함
    else
        if (state != 0) // 이미 격리/회복 중인경우
           state++, time++; 
}


int Person::getIndex() {
    return index;
}
int Person::getX() {
    return x;
}
int Person::getY() {
    return y;
}
int Person::getState() {
    return state;
}
int Person::getTime() {
    return time;
}
void Person::setState(int newState) {
    state = newState;
}
void Person::setTime(int newTime) {
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
 
    int accumulateInfect = 0; //누적 감염자
    int accumulateInsulator = 0; // 누적 격리자
    int accumulateCure = 0; // 누적 완치자

    Person arrOfPerson[20]; // 전체 사람, 문제 조건에 따르면 최대 20명까지 있다고 함.
    bool arrOfInfectPerson[20] = { false }; // 현재 격리되지 않은 감염자 => 주변에 퍼트릴 수 있는 사람


    for (int i = 0; i < people; i++) {
        arrOfPerson[i] = Person(i); // 배열 초기화
    }

    
    arrOfPerson[infect_num].setState(INFECT); //초기 감염자
    arrOfInfectPerson[infect_num] = true;
    accumulateInfect++; // 누적 확진자 +1

    //초기 출력 조건
    cout << "index" << '\t' << "X" << '\t' << "Y" << '\t' << "S" << '\t' << "T" << '\n';
    //초기 클래스 변수 출력
    for (int i = 0; i < people; i++) {
        Print(arrOfPerson[i]);
    }


    for (int i = 0; i < total_interval; i++) {
        /*최초 감염자와 infection distance 이내에 있는 사람들을 확인하여
        해당 사람을 감염자로 상태 변경하고  그 외 상태 업데이트  */
        bool newArrOfInfectPerson[20] = { false }; // 신규 감염자 => 1시간 뒤부터 감염 퍼트림.

        cout << "============" << i + 1 << "h New cases=============" << endl;
        /* 새롭게 감염자된 사람들 좌표/상태/감염 시간 출력 */

        /*j는 전체 사람을 도는 for문이고 
        k는 현재 감염 상태인 사람을 찾아서 도는 for문
        이를 통해 감염자를 확인하고 상태를 업데이트 해준다. 
        */
        for (int j = 0; j < people; j++) {
            //신규 감염자 발생 여부를 확인하기 위한 bool 변수
            bool isChanged = false;
            if (arrOfPerson[j].getState() == NONINF) {
                for (int k = 0; k < sizeof(arrOfInfectPerson) / sizeof(bool); k++) {
                    if (!arrOfInfectPerson[k]) continue; // 감염자가 아닐경우 반복문 진행 
                    if(j == k) continue; //자기 자신과의 접촉여부를 판단할 필요 없음
                    bool isInf = arrOfPerson[j].isContact(arrOfPerson[k], inf_Dist); 
                    //isInf 를 통해 감염자와의 접촉 여부를 알 수 있음
                    //접촉일 경우 
                    if (isInf) { 
                        //상태와 시간 설정
                        arrOfPerson[j].setState(INFECT);
                        arrOfPerson[j].setTime(1);
                        //감염자 수 증가
                        accumulateInfect++;
                        //신규 감염자 출력
                        Print(arrOfPerson[j]);
                        //신규 감염자로 추가.
                        newArrOfInfectPerson[j] = true; 
                        //신규 감염자가 됐을 경우 이미 상태 업데이트를 해준 것과 동일하기 때문에 이를 파라미터로 if 문 수행
                        isChanged = true; 
                        break; //한명에게 감염됐으면 다른 감염자의 영향을 받지 않기 때문에 반복문을 탈출 
                    }
                }
            }
            if (!isChanged) { // 신규 감염자가 아닌경우 
                arrOfPerson[j].updateState();
                /*
                해당 사람의 현 상태에 따라 상황이 달라짐
                */
                switch (arrOfPerson[j].getState())
                {
                case 2: // 신규 감염자가 아닌경우 => 격리됨 => 바이러스 전파가 불가능함.
                    accumulateInsulator++; //누적 격리자 +1
                    arrOfInfectPerson[j] = false;
                    break;
                case 3:
                    accumulateCure++; //누적 회복 +1
                    break;
                case 4: // 3-> 4로 변경된경우 완치임.
                    arrOfPerson[j].setState(NONINF);
                    arrOfPerson[j].setTime(0);
                    break;
                }
            }
        }

        cout << "============= After " << i + 1 << "hours==========" << endl;
        /*전체 사람에 대한 좌표/상태/감염 시간 출력 */
        int arrOfState[4] = { 0,0,0,0 };
        for (int j = 0; j < people; j++) {
            arrOfState[arrOfPerson[j].getState()] += 1;
        }
        
        for (int j = 0; j < 4; j++) {
            cout << arrOfState[j] << " ";
        }
        cout << "\n";

        for (int j = 0; j < people; j++) {
            Print(arrOfPerson[j]);
        }


        /*  이동 가능 한 사람들의  위치를 랜덤값을 이용하여 변경,
        격리 및 회복단계는 이동 불가*/

        cout << "========= After " << i + 1 << "h movement========" << endl;
        /*이동 후 전체 사람들의 좌표 / 상태 / 감염 시간 출력 */
        for (int j = 0; j < people; j++) {
            arrOfPerson[j].move();
            Print(arrOfPerson[j]);
        }

        for (int i = 0; i < sizeof(newArrOfInfectPerson) / sizeof(bool); i++) {
            if (newArrOfInfectPerson[i]) // 신규 감염자일 경우
                arrOfInfectPerson[i] = true; // 다른 사람을 감염시킬 수 있음.
        }
    }
    cout << "============ Final result==============" << endl;
    /*현재 상태의 비감염자, 감염자, 격리, 회복된 사람들 수*/
    /*누적 감염자, 격리된 숫자, 회복된 숫자 */

    int arrOfState[4] = { 0,0,0,0 };
    for (int j = 0; j < people; j++) {
        arrOfState[arrOfPerson[j].getState()] += 1;
    }

    for (int j = 0; j < 4; j++) {
        cout << arrOfState[j] << " ";
    }
    cout<<"\n";
    //누적 상태 인원 수 계산 (누적 비 감염자는 계산하지 않음)
    cout << '0'<<' ' << accumulateInfect << ' ' << accumulateInsulator << ' ' << accumulateCure << '\n';
    return 0;
}