/*

Chapter 07�� ���� 07-2�� �ι� ° ���������� ������ �� Ŭ���� ���Ǹ� �䱸�Ͽ���.

class Book

{

private:

        char *title; //å�� ����

        char *isbn; //����ǥ�ص�������ȣ

        int price; //å�� ����

        ....

};

 

class EBook :public Book

{

private:

        char *DRMKey; //���Ȱ��� Ű

        ....

};

�� �� ������ �� Ŭ������ ������� Book Ŭ������, EBook Ŭ������ ���� ���簡 ������ �ǵ��� ��������ڿ� ���� �����ڸ� �����ϰ�,

���� Ȯ���� ���� main �Լ��� ������ �����غ���.

����� �� ������ �ذ��� ���ؼ��� �������� �����غ��� �� ��ҵ��� �� ���� �����Ѵ�.

Ư�� �ռ� ���� ���� ����� ������ ������ ������ �� ������ �ذ��ϱ� �ٶ���.

"C++����, AAA�� �����ڴ� AAA ��ü �Ǵ� AAA�� ���� Ȥ�� ���������� ����ϴ� ��� ��ü�� ������ �� �ִ�."

*/


#include <iostream>
#include <cstring>

using namespace std;


class Book {
private:
    char *title; //å�� ����
    char *isbn; //����ǥ�ص�����ȣ
    int price; //å�� ����

public:
    Book(const char *t, const char *i, int p) : price(p) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        isbn = new char[strlen(i) + 1];
        strcpy(isbn, i);
    }
    //���� ������
    Book(const Book& ref) : price(ref.price) {
        title = new char[strlen(ref.title) + 1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(isbn, ref.isbn);
    }
    //���� ������ �����ε�
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
    char *DRMkey; //���Ȱ��� Ű
public:
    Ebook(const char *t, const char *i, int p, const char *d) : Book(t, i, p) {
        DRMkey = new char[strlen(d) + 1];
        strcpy(DRMkey, d);
    }
    //���� ������
    Ebook(const Ebook& ref) : Book(ref) {
        DRMkey = new char[strlen(ref.DRMkey) + 1];
        strcpy(DRMkey, ref.DRMkey);
    }
    //���� ������
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
    Ebook ebook1("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    Ebook ebook2 = ebook1; //���� �������� ȣ��
    ebook2.showEbookInfo();
    cout << endl;
    Ebook ebook3("gudetama", "gudetama", 0, "gudetama");
    ebook3 = ebook2; //���� �������� ȣ��
    ebook3.showEbookInfo();

    return 0;
}