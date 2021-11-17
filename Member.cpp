#include "Member.h"

void Member::printUserInfomation(){
	User::printUserInfomation();
	cout << getBookLoanCount() << endl;
	// 책 연체일 및 연체현황
	// 예약 현황
}

Member* Member::initMember(){
	string inputMemberName; cout << "이름 : "; cin >> inputMemberName;
	string inputMemberID; cout << "ID : "; cin >> inputMemberID;
	string inputMemberAddress; cout << "주소 : "; cin >> inputMemberAddress;
	string inputMemberPhoneAddress; cout << "휴대폰 번호 : "; cin >> inputMemberPhoneAddress;
	string inputMemberEmail; cout << "이메일 : "; cin >> inputMemberEmail;

	return new Member(inputMemberName, inputMemberID, inputMemberAddress,
		inputMemberPhoneAddress, inputMemberEmail);
}

void Member::askToLibrary(){
	// 문의하기
}
