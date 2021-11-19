#pragma once

#include<iostream>
#include <string>
#include <list>
#include "Book.h"

class BookList {
private:
	list<Book*> bookList;
	string bookCategory;
	int bookCount;
	
public:
	BookList(const string bookCategory="종합")
		:bookCategory(bookCategory),bookCount(0){}
	static BookList* initBookList(const string bookCategory="종합");
	int getBookCount() { return bookCount; }

	bool addPersonalBook();
	bool addBook( Book* newBook);
	bool deleteBook();
	list<Book*>::iterator searchBook();
	void listBookPrint();
};