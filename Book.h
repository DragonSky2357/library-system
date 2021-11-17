#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <ctime>

#include "User.h"

using namespace std;


class Book {

private:
	int getBookWaitUser() { return bookWaitUser.size(); }
	
	class Borrow {
	public:
		Borrow() : bookBorrow(false), bookBorrowUserID(""), bookBorrowDate(time(NULL)) {}
		bool getBookBorrow() { return bookBorrow; }
		string getBookBorrowUserID() { return bookBorrowUserID; }
		time_t getBookBorrowDate() { return bookBorrowDate; }

		void setBookBorrow(bool setBookBorrow) { bookBorrow = setBookBorrow; }
		void setBookBorrowUserID(string setBookBorrowUserID) { bookBorrowUserID = setBookBorrowUserID; }
		void setBookBorrowDate(time_t setBookBorrowDate) { bookBorrowDate = setBookBorrowDate; }

	private:
		bool bookBorrow;
		string bookBorrowUserID;
		time_t bookBorrowDate;
	};

public:
	Book(const string bookTitle, const string bookAuth, const string bookPublisher, const string bookPublishing, 
		const string bookPrice, const string bookImage,const string bookDetail)
			:bookTitle(bookTitle), bookAuth(bookAuth), bookPublisher(bookPublisher),bookPublishing(bookPublishing),
		bookPrice(bookPrice), bookImage(bookImage),bookDetail(bookDetail),bookImportDay(time(NULL)){}

	string getBookTitle() { return bookTitle; }
	string getBookAuth() { return bookAuth; }
	string getBookPublisher() { return bookPublisher; }
	string getBookPublishing() { return bookPublishing; }
	string getBookImage() { return bookImage; }
	string getBookPrice() { return bookPrice; }
	string getBookBorrowUserID() { return bookBorrow.getBookBorrowUserID(); }
	string getBookDetail() { return bookDetail; }
	bool getBookBorrow() { return bookBorrow.getBookBorrow(); }

	void setBookTitle(string setBookTitle) { bookTitle = setBookTitle; }
	void setBookAuth(string setBookAuth) { bookAuth = setBookAuth; }
	void setBookPublisher(string setBookPublisher) { bookPublisher = setBookPublisher; }
	void setBookPublishing(string setBookPublishing) { bookPublishing = setBookPublishing; }
	void setBookImage(string setBookImage) { bookImage = setBookImage; }
	void setBookPrice(string setBookPrice) { bookPrice = setBookPrice; }
	void setBookBorrowUserID(string setBookBorrowUserID) { bookBorrow.setBookBorrowUserID(setBookBorrowUserID); }
	void setBookBorrow(bool setBookBorrow) { bookBorrow.setBookBorrow(setBookBorrow); }
	void setBookDetail(string setBookDetail) { bookDetail = setBookDetail; }

	void printBookInfomation();

private:
	string bookTitle;
	string bookAuth;
	string bookPublisher;
	string bookPublishing;
	string bookPrice;
	string bookImage;
	string bookDetail;
	time_t bookImportDay;
	Borrow bookBorrow;
	queue<User> bookWaitUser;
};