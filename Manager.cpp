#include "Manager.h"

void Manager::printUserInfomation(){
	User::printUserInfomation();
	cout << getUserGrade() << endl;
}

Manager* Manager::initManager()
{
	string inputManagerName; cout << "이름 : "; cin >> inputManagerName;
	string inputManagerID; cout << "ID : "; cin >> inputManagerID;
	string inputManagerAddress; cout << "주소 : "; cin >> inputManagerAddress;
	string inputManagerPhoneAddress; cout << "휴대폰 번호 : "; cin >> inputManagerPhoneAddress;
	string inputManagerEmail; cout << "이메일 : "; cin >> inputManagerEmail;
	string inputManagerGrade; cout << "직급 : "; cin >> inputManagerGrade;

	return new Manager(inputManagerName, inputManagerID, inputManagerAddress,
		inputManagerPhoneAddress, inputManagerEmail, inputManagerGrade);
}

void Manager::notificationOfLibrary(){
	// 도서관 공지사항
}


