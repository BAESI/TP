#define SRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Page {
private:
    int count;
    Page* prev;
    Page* next;
public:
    Page(int i) {
        count = i;
        prev = NULL;
        next = NULL;
    }
    int getConut() {
        return count;
    }
    void setCount(int i) {
        count = i;
    }
    Page* getNext() {
        return next;
    }
    void setNext(Page* n) {
        next = n;
    }
    Page* getPrev() {
        return prev;
    }
    void setPrev(Page* p) {
        prev = p;
    }
};

int main() {
    int byteSize = 0;
    int wordCount = 0;

    string s;
    vector<string> v;
    ifstream myFile; 
    myFile.open("C:\\Users\\82106\\Desktop\\객체지향설계\\TP\\202002_객체지향프로그래밍_텀프로젝트+주제\\test.txt");
    string input;
    string consoleMessage = "";
    while (getline(myFile, s, ' ')) {
        v.push_back(s);
    }
    if (!myFile.is_open()) {
        cout << "파일 열기 실패" << endl;
    }
    myFile.close();
    Page* page = new Page(wordCount);

    while (1) {
        wordCount = page->getConut();
        for (int i = 0; i < 20; i++) {
            cout << setw(2) << i + 1 << "| ";
            while (byteSize + size(v[wordCount]) < 76) {
                if ((byteSize + size(v[wordCount]) + size(v[wordCount + 1])) > 75) {
                    cout << v[wordCount];
                    byteSize += size(v[wordCount++]);
                }
                else {
                    cout << v[wordCount] << " ";
                    byteSize += (size(v[wordCount++]) + 1);
                }
                if (wordCount == v.size() - 1) {
                    cout << v[wordCount];
                    break;
                }
            }
            byteSize = 0;
            cout << endl;
            if (wordCount == v.size() - 1) {
                break;
            }
        }
        if (page->getNext() == NULL) {
            page->setNext(new Page(wordCount));
        }
        if (page->getNext()->getPrev() == NULL) {
            page->getNext()->setPrev(page);
        }

        for (int i = 0; i < 81; i++) {
            cout << "-";
        }
        cout << "\nn:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후종료" << endl;
        for (int i = 0; i < 81; i++) {
            cout << "-";
        }
        cout << "\n(콘솔메시지) " << consoleMessage << endl;
        for (int i = 0; i < 81; i++) {
            cout << "-";
        }
        cout << "\n입력 : ";
        cin >> input;

           if (input[0] == 'n') {
               if (!(wordCount == v.size() - 1)) {
                   page = page->getNext();
                   consoleMessage = "";
               }
               else {
                   consoleMessage = "This is the last page!";
               }
           }
           else if (input[0] == 'p') {
               if (!(page->getPrev() == 0)) {
                   page = page->getPrev();
                   consoleMessage = "";
               }
               else {
                   consoleMessage = "This is the first page!";
               }
           }
           else if (input[0] == 'i') {
               int tempCount;
               int tempSize = 0;
               vector<string> tempV;
               if (page->getPrev() != NULL) {
                   tempCount = page->getConut();
               }
               else {
                   tempCount = 0;
               }
               string tok;
               stringstream ss(input);
               int n;
               while (getline(ss, tok, ',')) {
                   tempV.push_back(tok);
               }
               stringstream ss2(tempV[0].erase(0, 2));
               ss2 >> n;
               cout << n << endl;
               for (int i = 0; i < n - 1; i++) {
                   while (tempSize + size(v[tempCount]) < 76) {
                       if ((tempSize + size(v[tempCount]) + size(v[tempCount + 1])) > 75) {
                           tempSize += size(v[tempCount++]);
                       }
                       else {
                           tempSize += (size(v[tempCount++]) + 1);
                       }
                   }
                   tempSize = 0;
               }
               stringstream ss3(tempV[1]);
               ss3 >> n;
               v.insert(v.begin() + tempCount + n, tempV[2].substr(0, size(tempV[2]) - 1));
           }
           else if (input[0] == 'd') {
               int tempCount;
               int tempSize = 0;
               vector<string> tempV;
               if (page->getPrev() != NULL) {
                   tempCount = page->getConut();
               }
               else {
                   tempCount = 0;
               }
               string tok;
               stringstream ss(input);
               int n;
               while (getline(ss, tok, ',')) {
                   tempV.push_back(tok);
               }
               stringstream ss2(tempV[0].erase(0, 2));
               ss2 >> n;
               cout << n << endl;
               for (int i = 0; i < n - 1; i++) {
                   while (tempSize + size(v[tempCount]) < 76) {
                       if ((tempSize + size(v[tempCount]) + size(v[tempCount + 1])) > 75) {
                           tempSize += size(v[tempCount++]);
                       }
                       else {
                           tempSize += (size(v[tempCount++]) + 1);
                       }
                   }
                   tempSize = 0;
               }
               stringstream ss3(tempV[1]);
               ss3 >> n;
               v.erase(v.begin() + tempCount + n - 1);
           }
           else if (input[0] == 'c') {
               int tempCount = 0;
               stringstream ss(input);
               vector<string> tempV;
               string tok;
               while (getline(ss, tok, ',')) {
                   tempV.push_back(tok);
               }
               tempV[0] = tempV[0].erase(0, 2);
               tempV[1] = tempV[1].substr(0, size(tempV[1]) - 1);
               while (tempCount != v.size()) {
                   if (v[tempCount++] == tempV[0]) {
                       v[tempCount - 1] = tempV[1];
                   }
               }
           }
           else if (input[0] == 's') {
               int tempCount = 0;
               input = input.erase(0, 2);
               input = input.substr(0, size(input) - 1);
               while (tempCount != v.size()) {
                   if (v[tempCount++] == input) {
                       cout << v[tempCount - 1] << endl;
                       break;
                   }
               }
           }
           else if (input[0] == 't') {
               return 0;
           }
           else {
               consoleMessage = "Unvalid input!";
           }

       }


        return 0;
    }
