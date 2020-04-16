// https://jaimemin.tistory.com/49?category=955507
// 이 자료를 보면서 공부했다.


/*

~연산자는 단항 연산자로서 비트단위 not의 의미를 갖는다.

즉, ~연산자는 비트단위로 1은 0으로, 0은 1로 바꾼다.

이에 우리는 Point 객체를 대상으로 다음과 같이 연산이 가능하도록 ~연산자를 오버로딩하고자 한다.

Point pos2= ~pos1;

위의 ~연산의 결과로 반환된 객체의 xpos 멤버에는 pos1의 ypos값이,

반환된 객체의 ypos 멤버에는 pos1의 xpos 값이 저장되어야 한다

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
    Point operator~() {
        return Point(this->ypos, this->xpos);
    }

};

int main() {
    Point pos1(3, 4);

    pos1.ShowPosition();
    (~pos1).ShowPosition();

    return 0;
}