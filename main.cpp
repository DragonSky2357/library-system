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
	Book* temp1 = new Book("�Ųٷ� �д� �����","���ù� ","������ ","2021�� 10��","17,500","https://image.aladin.co.kr/product/28182/0/cover150/k502835770_1.jpg");
	Book* temp2 = new Book("�̻��� ���� ���� ��õ�� 12", "���νø������� ", "�������  ", "2021�� 11��", "12,000","https://image.aladin.co.kr/product/28182/0/cover150/k502835770_1.jpg");
	*/

	
	//User* u = new Manager("��ö��", "testID", "address", "010-1234-5678", "test@naver.com", "���");
	//u->printUserInfomation();

	//Library c;
	//c.searchBook();
	
	//c.borrowBook();
	//c.returnBook();

   // GDI+ ���õ� � �Լ��� ��� ���� �ش� �Լ��� ȣ���ؾ� �մϴ�.
	
	
	

	//printQRcode(30, 30, 200, 200);


	CSmtp mail;

	mail.SetSMTPServer("smtp.gmail.com", 587);
	mail.SetSecurityType(SMTP_SECURITY_TYPE::USE_TLS);


	//Gmail �α���
	mail.SetLogin("qkrdydals327@gmail.com");
	mail.SetPassword("free9803@&");



	//�۽��� ����
	mail.SetSenderName("DragonSky");                  //�̸�
	mail.SetSenderMail("qkrdydals327@gmail.com");    //�۽��� ����



	//������ ����
	mail.AddRecipient("qkrdydals327@naver.com");     //�޴»�� ����



	//����
	mail.SetSubject("test"); //����
	mail.AddMsgLine("Hello, Email\nWow");               //����



	//÷������
	// mail.AddAttachment("E:/temp/boy.png");
	// mail.AddAttachment("E:/temp/VideoScreenShot.jpg");



	//������
	mail.Send();

	getch();
	
	return 0;
}


