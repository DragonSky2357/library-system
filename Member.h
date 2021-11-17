#pragma once

#include <string>
#include <queue>

#include "User.h"
#include "Book.h"

using namespace std;

class Member : public User {
public:
	Member(const string userName, const string userID, const string userAddress,
		const string userPhoneNumber, const string userEmail)
		:User(userName, userID, userAddress, userPhoneNumber, userEmail), 
			bookLoanCount(0),bookOverdueDay(time(NULL)) {}

	int getBookLoanCount() { return bookLoanCount; }
	time_t getBookOverdueDay() { return bookOverdueDay; }
	queue<Book*> getBookReservationState() { return bookReservationState; }

	virtual void printUserInfomation();
	static Member* initMember();
	void askToLibrary();

private:
	int bookLoanCount;
	time_t bookOverdueDay;
	queue<Book*> bookReservationState;
};