#include "Book.h"
#include "BookList.h"

BookList* BookList::initBookList(const string bookCategory)
{
	return new BookList(bookCategory);
}

bool BookList::addPersonalBook(){
	string newBookTitle;
	string newBookAuth;
	string newBookPublisher;
	string newBookPublishing;
	string newBookImage;
	string newBookPrice;
	string newBookDetail;

	cout << "����     => "; cin >> newBookTitle;
	cout << "����     => "; cin >> newBookAuth;
	cout << "���ǻ�   => "; cin >> newBookPublisher;
	cout << "������   => "; cin >> newBookPublishing;
	cout << "ǥ��     => "; cin >> newBookImage;
	cout << "����     => "; cin >> newBookPrice;
	cout << "������   => "; cin >> newBookDetail;

	Book* newBook = new Book(newBookTitle, newBookAuth, newBookPublisher,
		newBookPublishing, newBookImage, newBookPrice, newBookDetail);
	
	bookList.push_back(newBook);
	bookCount++;

	return true;
}

bool BookList::addBook(Book* newBook) {
	bookList.push_back(newBook);
	bookCount++;
	return true;
}
bool BookList::deleteBook()
{
	bookList.erase(searchBook());
	return false;
}

list<Book*>::iterator BookList::searchBook(){
	string searchBookTitle;
	cin.ignore();
	cout << "����   => "; getline(cin,searchBookTitle);

	for (auto it = bookList.begin(); it != bookList.end(); it++) {
		if ((*it)->getBookTitle() == searchBookTitle)
			return (it);
	}

	return bookList.end();
}


void BookList::listBookPrint()
{
	for (auto it = bookList.begin(); it != bookList.end(); it++) {
		(*it)->printBookInfomation();
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "--------------------------------------------------------------------------" << endl;
	}
}

