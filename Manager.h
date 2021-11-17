#pragma once

#include <string>
#include "User.h"

using namespace std;

class Manager : public User{
public:
	Manager(const string userName, const string userID, const string userAddress,
		const string userPhoneNumber, const string userEmail, const string userGrade="»ç¿ø")
		:User(userName, userID, userAddress, userPhoneNumber, userEmail), userGrade(userGrade) {}
	
	string getUserGrade() { return userGrade; }

	virtual void printUserInfomation();
	static Manager* initManager();
	void notificationOfLibrary();

private:
	string userGrade;
};