#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#define NONINF 0
#define INFECT 1
#define ISOLATE 2
#define RECOVER 3


class Person {
	int x, y;     // ����� ��ǥ (x, y���� 0~100����)
	int state = 0;   // ���� ���� (00-���� �ȵ�, 1-����, 2 - �ݸ�, 3-ȸ��)  
	int time = 0;   //���� ��� �ð�, state�� 1�� �ٲ� �������� 1�ð����� 1���� ���� 
	/* �ʿ��� ���� �����Ͽ� ���*/

    //����� ���� �߰��� ����
    int index;
    
public:
    Person();
	Person(int i);
	void move();
	void updateState();
	bool isContact(Person p,double infDist);
	/* �ʿ��� ���� �����Ͽ� ���*/

    //����� ���� �߰��� �Լ�
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
    index  = i; //���� �Լ� ���� (0~10������ ��) 
	x = rand() % 11;
	y = rand() % 11;
	/* �ʿ��� ���� �����Ͽ� ���*/
}

void Person::move() {
    if(getState() == INFECT || getState() == NONINF){
        x = rand() % 11;
        y = rand() % 11;
    }
	/* �ʿ��� ���� �����Ͽ� ���*/
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
/*��¿��ÿ��� ����� Print() �Լ�*/
void Print(Person p) { //��ü �迭�� ����Ͽ��⶧���� �迭�� �ε��� ��� �� 
	cout << p.getIndex() << '\t' << p.getX() << '\t' << p.getY() << '\t' << p.getState() << '\t' << p.getTime() << endl;
}

int main() {
	/*simulation setting*/
	int people = 10;     // �����ϴ� ��� ���
	int infect_num = 1;    // ���� �ϴ� ��� �� �ʱ� ������ 
	int total_interval = 5;   // �� 5�ð������� ��ȭ ����
	int interval = 1;    // 1�ð� ���� 1�ѹ��� ��ġ�� �ٲ��, ������ Ȯ�� �� ���� ���� ����
	double inf_Dist = 3;  // infection distance 
	
	srand(1);   //�������� ���� ��뺯������ ����
	
	/*�ʿ��� �ڵ带 �ۼ� �ϼ���*/

    Person arrOfPerson[20];
    bool arrOfInfectPerson[20];


    for(int i = 0; i < people; i++){
        arrOfPerson[i] = Person(i);
    }

    //�ʱ� ������
    arrOfPerson[infect_num].setState(INFECT);
    arrOfInfectPerson[0] = true;
    int numOfInfect = 1;

    cout<<"index   X   Y   S  T\n";
    for(int i = 0; i < people; i++){
        Print(arrOfPerson[i]);
    }


	for (int i = 0; i < total_interval; i++) {
		/*���� �����ڿ� infection distance �̳��� �ִ� ������� Ȯ���Ͽ� 
		�ش� ����� �����ڷ� ���� �����ϰ�  �� �� ���� ������Ʈ  */


		cout << "============" << i + 1 << "h New cases=============" << endl;
		/* ���Ӱ� �����ڵ� ����� ��ǥ/����/���� �ð� ��� */

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
		/*��ü ����� ���� ��ǥ/����/���� �ð� ��� */
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
		/*  �̵� ���� �� �������  ��ġ�� �������� �̿��Ͽ� ����,
		�ݸ� �� ȸ���ܰ�� �̵� �Ұ�*/

		
		cout << "========= After " << i + 1 << "h movement========" << endl;
		/*�̵��� ��ü ������� ��ǥ / ���� / ���� �ð� ��� */
        for(int j = 0; j < people; j++){
            arrOfPerson[j].move();
            Print(arrOfPerson[j]);
        }
	}
	cout << "============ Final result==============" << endl;
	  /*���� ������ �񰨿���, ������, �ݸ�, ȸ���� ����� ��*/
	  /*���� ������, �ݸ��� ����, ȸ���� ���� */

}