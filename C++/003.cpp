// https://jaimemin.tistory.com/50?category=955507
// 이 자료를 보면서 공부했다.

/*

예제 PointConsoleOutput.cpp에서 정의한 Point 클래스를 대상으로 아래의 main 함수가 보이는대로 데이터의 입력이 가능하도록,

그리고 실행의 예에서 보이는 대로 출력이 이뤄지도록 >>연산자를 오버로딩하자

int main(void)

{

        Point pos1;

        cout << "x, y 좌표 순으로 입력: ";

        cin >> pos1;

        cout << pos1;

 

        Point pos2;

        cout << "x, y 좌표 순으로 입력: ";

        cin >> pos2;

        cout << pos2;

        return 0;

}

*/

#include <iostream>

using namespace std;

class Point {
private:
    int xpos;
    int ypos;
public:
    Point(int x, int y) : xpos(x), ypos(y) {}

    void ShowPosition() {
        cout << '[' << this->xpos << ", " << this->ypos << ']' << endl;
    }
    friend istream& operator>>(istream& is, Point& p);
    friend ostream& operator<<(ostream& os, Point& p);
};

istream& operator>>(istream& is, Point& p) { // cin >> p -> operator>> (cin, p)
    is >> p.xpos >> p.ypos;
    return is;
}

ostream& operator<<(ostream& os, Point& p) {
    os << '[' << p.xpos << ", " << p.ypos << ']' << endl;
    return os;
}


int main() {
    Point pos1(3, 4);
    pos1.ShowPosition();
    cout << "x, y 좌표 순으로 입력: ";
    cin >> pos1;
    pos1.ShowPosition();
    cout << pos1;


    return 0;
}