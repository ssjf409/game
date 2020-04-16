// https://jaimemin.tistory.com/49?category=955507
// 이 자료를 보면서 공부했다.

/*

부호 연산자로는 -는 단항 연산자이다.

이 연산자는 피연산자의 부호를 반전시킨 겨로가를 반환한다.

예를 들어서 다음 문장이 실행되면,

int num2= -num1;

num2에는 num1과 절대값은 같지만 부호가 다른 값이 저장된다.

물론 num1의 값에는 영향을 미치지 않는다.

이와 유사하게 Point 클래스를 대상으로 - 연산자를 오버로딩 해보자.

다음의 문장이 실행되면, Point pos2= -pos1;

Pos2의 멤버변수는 pos1의 멤버변수 값과 다른 부호의 값으로 초기화되도록 오버로딩해보자

*/

#include <iostream>

using namespace std;

class Point{
private:
    int xpos;
    int ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() {
        cout << '[' << this->xpos << ", " << this->ypos << ']' << endl;
    }
    Point operator-() {
        return Point(-this->xpos, -this->ypos);
    }
    Point operator-(Point& a) {
        return Point(this->xpos - a.xpos, this->ypos - a.ypos);
    }
};




int main() {
    Point pos1(3, 4);
    Point pos2(1, 2);
    pos1.ShowPosition();
    (-pos2).ShowPosition();
    (pos1 - pos2).ShowPosition();

    return 0;
}