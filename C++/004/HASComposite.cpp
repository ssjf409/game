/*

Chapter 07에서는 예제 HASComposite.cpp를 통해서 다음의 두 클래스를 정의하였다(완전한 클래스의 정의는 예제 참고)

class Gun

{

        ....

}

 

class Police

{

private:

        int handcuffs; //소유한 수갑의 수

        Gun *pistol; //소유하고 있는 권총

public:

        ....

}

이에 Police 클래스를 대상으로 깊은 복사가 이뤄지도록 대입 연산자와 복사 생성자를 동시에 정의하고 이의 확인을 위해 main 함수도 적절히 정의해보자

*/
// #include <iostream>
// using namespace std;

// class Gun {
// private:
//     int bullet;
// public:
//     Gun(int num) : bullet(num) {
//         cout << num << "발 장전된 총을 만들었습니다." << endl;
//     }
//     void shoot() {
//         if(bullet > 0) {
//             cout << "BBANG!!" << endl;
//             bullet--;
//         } else {
//             cout << "NO BULLET!" << endl;
//         }
//     }
// };


// class Police {
// private:
//     int handcuffs;
//     Gun *pistol;
// public:
//     Police(int hNum, int bNum) : handcuffs(hNum) {
//         if(bNum > 0) {
//             pistol = new Gun(bNum);
//         } else {
//             pistol = NULL;
//         }
//     }
//     void putHandCuff() {
//         cout << "SNAP!" << endl;
//         handcuffs--;
//     }
//     void shoot() {
//         if(pistol == NULL) {
//             cout << "NO GUN!!" << endl;
//         } else {
//             pistol->shoot();
//         }
//     }
//     ~Police() {
//         if(pistol != NULL) {
//             delete pistol;
//         }
//     }
// };

// int main() {
//     Police pman1(5, 3);
//     pman1.shoot();
//     pman1.putHandCuff();

//     Police pman2(0, 3);
//     pman2.shoot();
//     pman2.putHandCuff();
//     return 0;
// }


#include <iostream>
using namespace std;

class Gun {
private:
    int bullet;
public:
    Gun(int num) : bullet(num) {}
    void shoot() {
        if(bullet > 0) {
            cout << "BBANG!!" << endl;
            bullet--;
        } else {
            cout << "NO BULLET!" << endl;
        }
    }
};


class Police {
private:
    int handcuffs;
    Gun *pistol;
public:
    Police(int hNum, int bNum) : handcuffs(hNum) {
        if(bNum > 0) {
            pistol = new Gun(bNum);
        } else {
            pistol = NULL;
        }
    }
    Police(const Police& ref) : handcuffs(ref.handcuffs) {
        if(ref.pistol != NULL) {
            pistol = new Gun(*(ref.pistol));
        } else {
            pistol = NULL;
        }
    }

    Police& operator=(const Police& ref) {
        cout << "Police& operator=()" << endl;
        handcuffs = ref.handcuffs;
        if(pistol != NULL) delete pistol;
        if(ref.pistol != NULL) {
            pistol = new Gun(*(ref.pistol));
        } else {
            pistol = NULL;
        }
        return *this;
    }


    void putHandCuff() {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void shoot() {
        if(pistol == NULL) {
            cout << "NO GUN!!" << endl;
        } else {
            pistol->shoot();
        }
    }
    ~Police() {
        if(pistol != NULL) {
            delete pistol;
        }
    }
};

int main() {
    Police pman1(5, 3);
    Police pman2 = pman1;
    pman2.putHandCuff();
    pman2.shoot();

    Police pman3(2, 4);
    pman3 = pman1;
    pman3.putHandCuff();
    pman3.shoot();
    return 0;
}