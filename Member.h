#pragma once

#include <string>
#include <queue>
#include <list>

#include "User.h"
#include "Book.h"

using namespace std;

class Member : public User {
public:
	Member(const string userName, const string userID, const string userAddress,
		const string userPhoneNumber, const string userEmail, const time_t userRegisterDay)
		:User(userName, userID, userAddress, userPhoneNumber, userEmail, userRegisterDay),
		bookLoanCount(0),bookOverdueDay(time(NULL)) {}

	int getBookLoanCount() { return bookLoanCount; }
	time_t getBookOverdueDay() { return bookOverdueDay; }
	list<Book*> getBookBorrowState() { return bookBorrowState; }
	queue<Book*> getBookReservationState() { return bookReservationState; }

	void increaseBookLoanCount() { bookLoanCount++; }
	void decreaseBookLoanCount() { bookLoanCount--; }

	bool addBookBorrowState(const Book& addBook);
	bool delBookBorrowState(Book& delBook);

	virtual void printUserInfomation();
	static Member* initMember();
	void askToLibrary();

private:
	int bookLoanCount;
	time_t bookOverdueDay;
	list<Book*> bookBorrowState;
	queue<Book*> bookReservationState;
};