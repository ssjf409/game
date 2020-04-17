/*

Chapter 07의 문제 07-2의 두번 째 문제에서는 다음의 두 클래스 정의를 요구하였다.

class Book

{

private:

        char *title; //책의 제목

        char *isbn; //국제표준도서범ㄴ호

        int price; //책의 정가

        ....

};

 

class EBook :public Book

{

private:

        char *DRMKey; //보안관련 키

        ....

};

이 때 정의한 두 클래스를 대상으로 Book 클래스도, EBook 클래스도 깊은 복사가 진행이 되도록 복사생성자와 대입 연산자를 정의하고,

이의 확인을 위한 main 함수도 적절히 정의해보자.

참고로 이 문제의 해결을 위해서는 여러분이 생각해봐야 할 요소들이 몇 가지 존재한다.

특히 앞서 말한 다음 사실을 완전히 이해한 다음에 이 문제를 해결하기 바란다.

"C++에서, AAA형 참조자는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 참조할 수 있다."

*/


#include <iostream>
#include <cstring>

using namespace std;


class Book {
private:
    char *title; //책의 제목
    char *isbn; //국제표준도서번호
    int price; //책의 가격

public:
    Book(const char *t, const char *i, int p) : price(p) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        isbn = new char[strlen(i) + 1];
        strcpy(isbn, i);
    }
    //복사 생성자
    Book(const Book& ref) : price(ref.price) {
        title = new char[strlen(ref.title) + 1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(isbn, ref.isbn);
    }
    //대입 연산자 오버로딩
    Book& operator=(const Book& ref) {
        cout << "Book &operator=()" << endl;
        delete[] title;
        delete[] isbn;

        title = new char[strlen(ref.title) + 1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
    }

    void showBookInfo() {
        cout << "title : " << title << endl;
        cout << "ISBN : " << isbn << endl;
        cout << "price : " << price << endl;
    }
    ~Book() {
        delete[] title;
        delete[] isbn;
    }
};
 

class Ebook : public Book {
private:
    char *DRMkey; //보안관련 키
public:
    Ebook(const char *t, const char *i, int p, const char *d) : Book(t, i, p) {
        DRMkey = new char[strlen(d) + 1];
        strcpy(DRMkey, d);
    }
    //복사 생성자
    Ebook(const Ebook& ref) : Book(ref) {
        DRMkey = new char[strlen(ref.DRMkey) + 1];
        strcpy(DRMkey, ref.DRMkey);
    }
    //대입 연산자
    Ebook& operator=(const Ebook& ref) {
        cout << "Ebook &operator=()" << endl;
        Book::operator=(ref);
        delete[] DRMkey;
        DRMkey = new char[strlen(ref.DRMkey) + 1];
        strcpy(DRMkey, ref.DRMkey);
        return *this;
    }
    void showEbookInfo() {
        showBookInfo();
        cout << "DRMKey : " << DRMkey << endl;
    }
    ~Ebook() {
        delete[] DRMkey;
    }
};

int main() {
    Ebook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    Ebook ebook2 = ebook1; //복사 생성자의 호출
    ebook2.showEbookInfo();
    cout << endl;
    Ebook ebook3("gudetama", "gudetama", 0, "gudetama");
    ebook3 = ebook2; //대입 연산자의 호출
    ebook3.showEbookInfo();

    return 0;
}