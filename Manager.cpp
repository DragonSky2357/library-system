#include "Manager.h"

void Manager::printUserInfomation(){
	User::printUserInfomation();
	cout << getUserGrade() << endl;
}

Manager* Manager::initManager()
{
	string inputManagerName; cout << "�̸� : "; cin >> inputManagerName;
	string inputManagerID; cout << "ID : "; cin >> inputManagerID;
	string inputManagerAddress; cout << "�ּ� : "; cin >> inputManagerAddress;
	string inputManagerPhoneAddress; cout << "�޴��� ��ȣ : "; cin >> inputManagerPhoneAddress;
	string inputManagerEmail; cout << "�̸��� : "; cin >> inputManagerEmail;
	string inputManagerGrade; cout << "���� : "; cin >> inputManagerGrade;
	time_t inputManagerRegisterDay = time(NULL);

	return new Manager(inputManagerName, inputManagerID, inputManagerAddress,
		inputManagerPhoneAddress, inputManagerEmail, inputManagerRegisterDay,inputManagerGrade);
}

void Manager::notificationOfLibrary(){
	// ������ ��������
}


