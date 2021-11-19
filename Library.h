#pragma once

#include <list>
#include <fstream>
#include "User.h"
#include "Manager.h"
#include "Member.h"
#include "BookList.h"

class Library {
public:
	Library();

	void addMember();
	void borrowBook();
	void returnBook();
	Book* searchBook();
	Member* findUser(const string identifyID, const string identifyPhoneNumber);

private:
	bool addManager();
	bool loadManagerData();
	bool loadBookData();
	bool loadMemberData();
private:
	Manager*	libraryManager;
	list<User*> libraryMembers;
	BookList*	librarySynthesisBookList;

public:
	static const int MAXIMUM_BORROW_COUNT = 10;
};