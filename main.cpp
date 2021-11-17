#include<iostream>
#include<Windows.h>
#include<process.h>
#include<direct.h>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "BookList.h"
#include "User.h"
#include "Manager.h"
#include "Member.h"

#include "Library.h"

#pragma warning(disable:4996)

using namespace std;

int main(void) {
	
	char curDir[1000];

	//system("C:\\Users\\qkrdy\\source\\repos\\LibrarySystem\\Debug\\BookDownload.exe");
	
	_getcwd(curDir, 1000);

	

	/*
	Book* temp1 = new Book("거꾸로 읽는 세계사","유시민 ","돌베개 ","2021년 10월","17,500","https://image.aladin.co.kr/product/28182/0/cover150/k502835770_1.jpg");
	Book* temp2 = new Book("이상한 과자 가게 전천당 12", "히로시마레이코 ", "길벗스쿨  ", "2021년 11월", "12,000","https://image.aladin.co.kr/product/28182/0/cover150/k502835770_1.jpg");
	*/

	
	User* u = new Manager("김철수", "testID", "address", "010-1234-5678", "test@naver.com", "사원");
	u->printUserInfomation();

	Library c;
	c.searchBook();
	

	

	// list.deleteBook();
	// a->printBookInfomation();
	// list.listBookPrint();
}