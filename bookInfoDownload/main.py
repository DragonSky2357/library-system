import requests
import os
import urllib.request
import qrcode
from bs4 import BeautifulSoup
from datetime import datetime
from tqdm import tqdm


def Start(pages):
    bookTotalInfos = GetBooksInformationData(pages)
    books = GetProcessData(bookTotalInfos)
    SaveBookData(books)

# 알라딘 사이트 크롤링
def GetBooksInformationData(pages):  
    bookTotalInfos=[]
    baseURL = "https://www.aladin.co.kr/shop/common/wbest.aspx?BranchType="

    for index in tqdm(range(1,pages,1)):
        bookInfoURL = baseURL+str(index)
        html = requests.get(bookInfoURL).text
        soup = BeautifulSoup(html,"html.parser")
        bookTotalInfos=bookTotalInfos+soup.select_one("form#Myform").find_all("div","ss_book_box")
    
    print("GetBooksInformationDataComplete")
    return bookTotalInfos

# 크로링 데이터 책 정보 처리
def GetProcessData(bookTotalInfos):
    books=[]

    for book in tqdm(bookTotalInfos):
        # 첵 종합 정보
        bookInfo = book.find('div',"ss_book_list").find_all('li')

        index=0
        if(len(bookInfo)==4):
            index=1
        # 책 제목
        bookTitle = bookInfo[1-index].get_text().split(' ㅣ ')[0].split('-')[0].strip()
        # 책 상세 정보
        bookDetail = bookInfo[1-index].find("a")["href"].strip()
        # 가격
        bookPrice = bookInfo[3-index].find('span').get_text().strip().replace(",","")
        # 책 저자, 출판사, 출판일
        bookData = bookInfo[2-index].get_text().strip().split(' | ')
        # 저자
        bookAuth = bookData[0].replace("(지은이)","").strip().replace(" ","").split(",")[0]
        # 출판사
        bookPublisher = bookData[1]
        # 출판일
        bookPublishing = bookData[2]
        # 책 이미지
        bookImage = book.find('img')["src"].strip()
        
        print(bookDetail)

        # 책 정보 리스트에 저장
        books.append({
            "title":bookTitle,
            "auth":bookAuth,
            "publisher":bookPublisher,
            "publishing":bookPublishing,
            "price":bookPrice,
            "image":bookImage,
            "detail": bookDetail
        })

    print("ProcessDataComplete")
    return books
# QR코드 생성
def MakeQRcode(bookTitle,detailURL,bookImagePath):
    qrcode.make(detailURL).save(bookImagePath+"\\"+bookTitle+".png")

# 책 정보 txt저장 및 이미지 다운로드
def SaveBookData(books):
    # 오늘 날짜
    today = str(datetime.today().year)+str(datetime.today().month)+str(datetime.today().day)
    # 저장할 기본 디렉토리
    bookDirectoryPath = os.getcwd()+'\\'+today
    # 이미지 디렉토리
    bookImagePath = bookDirectoryPath+'\\'+'Image'

    # 데이터 txt 저장 및 이미지 다운로드
    try:
        os.makedirs(bookDirectoryPath,exist_ok=True)
        os.makedirs(bookImagePath,exist_ok=True)

        booksFiletxt = open(bookDirectoryPath+'\\'+today+".txt","w")
        for book in tqdm(books):
            booksFiletxt.write(book["title"]+",")
            booksFiletxt.write(book["auth"]+",")
            booksFiletxt.write(book["publisher"]+",")
            booksFiletxt.write(book["publishing"]+",")
            booksFiletxt.write(book["price"]+",")
            booksFiletxt.write(book["image"]+",")
            booksFiletxt.write(book["detail"]+"\n")
            urllib.request.urlretrieve(book["image"],bookImagePath+'\\'+book["title"]+'.jpg')
        booksFiletxt.close()

        for book in tqdm(books):
            MakeQRcode(book["title"],book["detail"],bookImagePath)

    except excption as e:
        print(e)
    
    finally:
        print("SaveBookDataComplete")

# 1페이지당 25책 정보 n*25 => Start(n)
Start(2)