#include<iostream>
#include <WinSock2.h>
#include <windows.h>
#include<process.h>
#include<direct.h>
#include <fstream>
#include <sstream>
#include <conio.h>
#include "Book.h"
#include "BookList.h"
#include "User.h"
#include "Manager.h"
#include "Member.h"
#include "Library.h"

#include "System.h"


#include "CSmtp.h"


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

	
	//User* u = new Manager("김철수", "testID", "address", "010-1234-5678", "test@naver.com", "사원");
	//u->printUserInfomation();

	//Library c;
	//c.searchBook();
	
	//c.borrowBook();
	//c.returnBook();

   // GDI+ 관련된 어떤 함수라도 사용 전에 해당 함수를 호출해야 합니다.
	
	
	

	//printQRcode(30, 30, 200, 200);


	CSmtp mail;

	mail.SetSMTPServer("smtp.gmail.com", 587);
	mail.SetSecurityType(SMTP_SECURITY_TYPE::USE_TLS);


	//Gmail 로그인
	mail.SetLogin("qkrdydals327@gmail.com");
	mail.SetPassword("free9803@&");



	//송신자 정보
	mail.SetSenderName("DragonSky");                  //이름
	mail.SetSenderMail("qkrdydals327@gmail.com");    //송신자 메일



	//수신자 정보
	mail.AddRecipient("qkrdydals327@naver.com");     //받는사람 메일



	//문서
	mail.SetSubject("test"); //제목
	mail.AddMsgLine("Hello, Email\nWow");               //본문



	//첨부파일
	// mail.AddAttachment("E:/temp/boy.png");
	// mail.AddAttachment("E:/temp/VideoScreenShot.jpg");



	//보내기
	mail.Send();

	getch();
	
	return 0;
}


