#include "Library.h"

#pragma warning(disable:4996)

Library::Library()
{
	librarySynthesisBookList =  BookList::initBookList();
	loadManagerData();
	loadMemberData();
	loadBookData();
}

void Library::borrowBook(){
	string identifyID; cout << "아이디 : "; cin >> identifyID;
	string identifyPhoneNumber; cout << "휴대폰 번호 : "; cin >> identifyPhoneNumber;

	Member* borrowUser =  findUser(identifyID, identifyPhoneNumber);

	if (borrowUser->getBookLoanCount() >= Library::MAXIMUM_BORROW_COUNT) {
		cout << "대여가능한 권수를 초과하였습니다.";
		return;
	}

	Book* findBook = searchBook();


	if (findBook->getBookBorrow() == true) {
		cout << "대출중이여서 대출 불가" << endl;
		return;
	}


	findBook->setBookBorrow(true);
	borrowUser->addBookBorrowState(*findBook);
	borrowUser->increaseBookLoanCount();

}

void Library::returnBook() {
	string identifyID; cout << "아이디 : "; cin >> identifyID;
	string identifyPhoneNumber; cout << "휴대폰 번호 : "; cin >> identifyPhoneNumber;

	Member* borrowUser = findUser(identifyID, identifyPhoneNumber);

	if (borrowUser->getBookLoanCount()==0) {
		cout << "반납하실 책이 없습니다.";
		return;
	}

	Book* findBook = searchBook();

	if (!borrowUser->delBookBorrowState(*findBook)) {
		cout << "반납하실 책이 회원 대출 목록에 없습니다.";
		return;
	}

	findBook->setBookBorrow(false);
	borrowUser->decreaseBookLoanCount();
}


Member* Library::findUser(const string identifyID, const string identifyPhoneNumber){

	for (auto it = libraryMembers.begin(); it != libraryMembers.end(); it++) {
		if ((*it)->getUserID() == identifyID && 
			(*it)->getUserPhoneNumber() == identifyPhoneNumber) {
			return (Member*)(*it);
		}
	}

	return nullptr;
}

Book* Library::searchBook() {
	return  (*librarySynthesisBookList->searchBook());
}


bool Library::addManager()
{
	libraryManager = Manager::initManager();
	ofstream fout("C:\\Users\\qkrdy\\source\\repos\\LibrarySystem\\LibrarySystem\\ManagerDB\\Manager.txt");

	if (!fout.is_open()) {
		cout << "파일 생성 실패";
	}

	string writeManagerName = libraryManager->getUserName();
	string writeManagerID = libraryManager->getUserID();
	string writeManagerAddress = libraryManager->getUserAddress();
	string writeManagerPhoneNumber = libraryManager->getUserPhoneNumber();
	string writeManagerEmail = libraryManager->getUserEmail();
	string writeManagerGrade = libraryManager->getUserGrade();
	time_t writeManagerRegisterDay = libraryManager->getUserRegisterDay();

	fout << writeManagerName << ',' << writeManagerID << ',' << writeManagerAddress << ','
		<< writeManagerPhoneNumber << ',' << writeManagerEmail << ',' << writeManagerGrade << ','
		<< writeManagerRegisterDay << endl;

	fout.close();

	return false;
}

bool Library::loadManagerData()
{
	ifstream fin("C:\\Users\\qkrdy\\source\\repos\\LibrarySystem\\LibrarySystem\\ManagerDB\\Manager.txt");

	if (!fin.is_open()) {
		cout << "파일 없음";
		addManager();
		return true;
	}

	string data;

	getline(fin, data);

	vector<string> v;
	char* c = strtok((char*)data.c_str(), ",");
	while (c) {
		v.push_back(c);
		c = strtok(NULL, ",");
	}

	string managerName = v[0];
	string managerID = v[1];
	string managerAddress = v[2];
	string managerPhoneNumber = v[3];
	string managerEmail = v[4];
	string managerGrade = v[5];
	time_t managerRegisterDay = _atoi64(v[6].c_str());

	libraryManager = new Manager(managerName, managerID, managerAddress,
						managerPhoneNumber, managerEmail, managerRegisterDay, managerGrade);

	return false;
}
void Library::addMember(){
	Member* newMember = Member::initMember();
	libraryMembers.push_back(newMember);

	ofstream fout("C:\\Users\\qkrdy\\source\\repos\\LibrarySystem\\LibrarySystem\\MemberDB\\Member.txt",ios::app);

	if (!fout.is_open()) {
		cout << "파일 생성 실패";
	}

	string writeMemberName = newMember->getUserName();
	string writeMemberID = newMember->getUserID();
	string writeMemberAddress = newMember->getUserAddress();
	string writeMemberPhoneNumber = newMember->getUserPhoneNumber();
	string writeMemberEmail = newMember->getUserEmail();
	time_t writeMemberRegisterDay = newMember->getUserRegisterDay();

	fout << writeMemberName << ',' << writeMemberID << ',' << writeMemberAddress << ','
		<< writeMemberPhoneNumber << ',' << writeMemberEmail << ',' << writeMemberRegisterDay << endl;

	fout.close();
}
bool Library::loadMemberData()
{
	ifstream fin("C:\\Users\\qkrdy\\source\\repos\\LibrarySystem\\LibrarySystem\\MemberDB\\Member.txt");

	if (!fin.is_open()) {
		cout << "회원 파일 실패";
		return false;
	}

	string data;
	while (getline(fin, data))
	{
		vector<string> v;
		char* c = strtok((char*)data.c_str(), ",");
		while (c) {
			v.push_back(c);
			c = strtok(NULL, ",");
		}

		string memberName = v[0];
		string memberID= v[1];
		string memberAddress = v[2];
		string memberPhoneNumber = v[3];
		string memberEmail = v[4];
		time_t memberRegisterDay = _atoi64(v[5].c_str());
		
		libraryMembers.push_back(
			new Member(memberName, memberID, memberAddress,
			memberPhoneNumber, memberEmail, memberRegisterDay)
		);
	}

	return true;
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

		
		librarySynthesisBookList->addBook(
			new Book(bookTitle, bookAuth, bookPublisher,
				bookPublishing, bookPrice, bookImage, bookDetail)
		);
	}

	return true;
}

