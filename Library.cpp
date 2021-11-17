#include "Library.h"

#pragma warning(disable:4996)

Library::Library()
{
	libraryManager =  Manager::initManager();
	librarySynthesisBookList = BookList::initBookList();
	loadBookData();
}

void Library::addMember()
{
}

void Library::borrowBook()
{
}

void Library::returnBook()
{
}

void Library::searchBook(){

	cout << librarySynthesisBookList->searchBook()->getBookDetail();
}

bool Library::loadBookData()
{
	ifstream fin("C:\\Users\\qkrdy\\source\\repos\\LibrarySystem\\LibrarySystem\\20211118\\20211118.txt");
	string data;

	while (getline(fin, data))
	{
		vector<string> v;
		char* c = strtok((char*)data.c_str(), ",");
		while (c) {
			v.push_back(c);
			c = strtok(NULL, ",");
		}

		string bookTitle = v[0];
		string bookAuth = v[1];
		string bookPublisher = v[2];
		string bookPublishing = v[3];
		string bookPrice = v[4];
		string bookImage = v[5];
		string bookDetail = v[6];

		Book* newBook = new Book(bookTitle, bookAuth, bookPublisher, bookPublishing, bookPrice, bookImage, bookDetail);
		librarySynthesisBookList->addBook(newBook);
	}

	return true;
}

bool Library::loadUserData()
{
	return false;
}