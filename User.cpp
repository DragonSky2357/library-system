#include "User.h"

#pragma warning(disable:4996)

void User::printUserInfomation(){
	cout << userName << endl;
	cout << userID << endl;
	cout << userAddress << endl;
	cout << userPhoneNumber << endl;
	cout << userEmail << endl;
	
	struct tm* pTimeInfo;
	pTimeInfo = localtime(&userRegisterDay);

	int userRegisterYear = pTimeInfo->tm_year + 1900;
	int userRegisterMonth = pTimeInfo->tm_mon + 1;
	int userRegisterDay = pTimeInfo->tm_mday;

	cout << userRegisterYear << "³â" << userRegisterMonth << "¿ù" << userRegisterDay <<"ÀÏ" << endl;
}

