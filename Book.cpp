#include "Book.h"

void Book::printBookInfomation() {
	cout << "����     => " << getBookTitle() << endl;
	cout << "����     => " << getBookAuth() << endl;
	cout << "���ǻ�   => " << getBookPublisher() << endl;
	cout << "������   => " << getBookPublishing() << endl;
	cout << "ǥ��     => " << getBookImage() << endl;
	cout << "����     => " << getBookPrice() << endl;
	cout << "������ => " << getBookDetail() << endl;

	string bookLoanState = bookBorrow.getBookBorrow() ? "������ : �����ο�[" + to_string(getBookWaitUser())+"]" : "���Ⱑ��";
	cout << "������Ȳ => " << bookLoanState << endl;
}
