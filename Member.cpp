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

	return new Member(inputMemberName, inputMemberID, inputMemberAddress,
		inputMemberPhoneAddress, inputMemberEmail);
}

void Member::askToLibrary(){
	// �����ϱ�
}
