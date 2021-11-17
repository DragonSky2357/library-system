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

	cout << "제목     => "; cin >> newBookTitle;
	cout << "저자     => "; cin >> newBookAuth;
	cout << "출판사   => "; cin >> newBookPublisher;
	cout << "출판일   => "; cin >> newBookPublishing;
	cout << "표지     => "; cin >> newBookImage;
	cout << "가격     => "; cin >> newBookPrice;
	cout << "디테일   => "; cin >> newBookDetail;

	Book* newBook = new Book(newBookTitle, newBookAuth, newBookPublisher,
		newBookPublishing, newBookImage, newBookPrice, newBookDetail);
	
	bookList.push_back(newBook);
	bookCount++;

	return true;
}

bool BookList::addBook(Book* newBook) {
	bookList.push_back(newBook);
	return true;
}
bool BookList::deleteBook()
{
	Book* deleteBook = searchBook();

	if (deleteBook != nullptr) {
		for (auto it = bookList.begin(); it != bookList.end(); it++) {
			if ((*it)->getBookTitle() == deleteBook->getBookTitle()) {
				bookList.erase(it);
				delete deleteBook;
				bookCount--;
				return true;
			}
		}
	}
	return false;
}

Book* BookList::searchBook(){
	string searchBookTitle;
	cin.ignore();
	cout << "제목   => "; getline(cin,searchBookTitle);

	for (auto it = bookList.begin(); it != bookList.end(); it++) {
		if ((*it)->getBookTitle() == searchBookTitle)
			return (*it);
	}
	return nullptr;
}


void BookList::listBookPrint()
{
	for (auto it = bookList.begin(); it != bookList.end(); it++) {
		(*it)->printBookInfomation();
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "--------------------------------------------------------------------------" << endl;
	}
}

