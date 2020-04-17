/*

Chapter 07������ ���� HASComposite.cpp�� ���ؼ� ������ �� Ŭ������ �����Ͽ���(������ Ŭ������ ���Ǵ� ���� ����)

class Gun

{

        ....

}

 

class Police

{

private:

        int handcuffs; //������ ������ ��

        Gun *pistol; //�����ϰ� �ִ� ����

public:

        ....

}

�̿� Police Ŭ������ ������� ���� ���簡 �̷������� ���� �����ڿ� ���� �����ڸ� ���ÿ� �����ϰ� ���� Ȯ���� ���� main �Լ��� ������ �����غ���

*/
// #include <iostream>
// using namespace std;

// class Gun {
// private:
//     int bullet;
// public:
//     Gun(int num) : bullet(num) {
//         cout << num << "�� ������ ���� ��������ϴ�." << endl;
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