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
	void searchBook();
	
private:
	bool loadBookData();
	bool loadUserData();

private:
	Manager*	libraryManager;
	list<User*> libraryMembers;
	BookList*	librarySynthesisBookList;
};