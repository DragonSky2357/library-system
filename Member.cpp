#include "Member.h"

void Member::printUserInfomation(){
	User::printUserInfomation();
	cout << getBookLoanCount() << endl;
	// å ��ü�� �� ��ü��Ȳ
	// ���� ��Ȳ
}

Member* Member::initMember(){
	string inputMemberName; cout << "�̸� : "; cin >> inputMemberName;
	string inputMemberID; cout << "ID : "; cin >> inputMemberID;
	string inputMemberAddress; cout << "�ּ� : "; cin >> inputMemberAddress;
	string inputMemberPhoneAddress; cout << "�޴��� ��ȣ : "; cin >> inputMemberPhoneAddress;
	string inputMemberEmail; cout << "�̸��� : "; cin >> inputMemberEmail;
	time_t inputMemberRegisterDay = time(NULL);

	return new Member(inputMemberName, inputMemberID, inputMemberAddress,
		inputMemberPhoneAddress, inputMemberEmail, inputMemberRegisterDay);
}

bool Member::addBookBorrowState(const Book& addBook){
	Book* newBorrowBook = new Book(addBook);

	bookBorrowState.push_back(newBorrowBook);
	return true;
}

bool Member::delBookBorrowState(Book& delBook){

	const string delBookTitle = delBook.getBookTitle();

	auto isBookInBookBorrowState =
		find_if(bookBorrowState.begin(),bookBorrowState.end(),
			[delBookTitle](Book* book) {return book->getBookTitle() == delBookTitle; });
	
	if (isBookInBookBorrowState != bookBorrowState.end()) {
		bookBorrowState.erase(isBookInBookBorrowState);
		return true;
	}
	
	return false;
}

void Member::askToLibrary(){
	// �����ϱ�
}
