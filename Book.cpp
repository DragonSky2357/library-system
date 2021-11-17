#include "Book.h"

void Book::printBookInfomation() {
	cout << "제목     => " << getBookTitle() << endl;
	cout << "저자     => " << getBookAuth() << endl;
	cout << "출판사   => " << getBookPublisher() << endl;
	cout << "출판일   => " << getBookPublishing() << endl;
	cout << "표지     => " << getBookImage() << endl;
	cout << "가격     => " << getBookPrice() << endl;
	cout << "디테일 => " << getBookDetail() << endl;

	string bookLoanState = bookBorrow.getBookBorrow() ? "대출중 : 예약인원[" + to_string(getBookWaitUser())+"]" : "대출가능";
	cout << "대출현황 => " << bookLoanState << endl;
}
