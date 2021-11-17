#pragma once

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class User {
public:
	User(const string userName, const string userID, const string userAddress,
		const string userPhoneNumber, const string userEmail)
		:userName(userName), userID(userID), userAddress(userAddress),
		userPhoneNumber(userPhoneNumber),userEmail(userEmail),userRegisterDay(time(NULL)){}
	
	void printUserInfomation();
	virtual ~User(){}
private:
	string userName;
	string userID;
	string userAddress;
	string userPhoneNumber;
	string userEmail;
	time_t userRegisterDay;
};