// https://jaimemin.tistory.com/50?category=955507
// �� �ڷḦ ���鼭 �����ߴ�.

/*

���� PointConsoleOutput.cpp���� ������ Point Ŭ������ ������� �Ʒ��� main �Լ��� ���̴´�� �������� �Է��� �����ϵ���,

�׸��� ������ ������ ���̴� ��� ����� �̷������� >>�����ڸ� �����ε�����

int main(void)

{

        Point pos1;

        cout << "x, y ��ǥ ������ �Է�: ";

        cin >> pos1;

        cout << pos1;

 

        Point pos2;

        cout << "x, y ��ǥ ������ �Է�: ";

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
    cout << "x, y ��ǥ ������ �Է�: ";
    cin >> pos1;
    pos1.ShowPosition();
    cout << pos1;


    return 0;
}