#include <iostream>
#include <optional>

using namespace std;

class Loan {
	private:
		int memeberId;
		int bookId;
		
	public:
		Loan() {
			memeberId = 0;
			bookId = 0;
		}
		
		int getMemberId() {
			return memeberId;
		};
		
		void setMemeberId(int m) {
			memeberId = m;
		};
		
		int getBookId() {
		    return bookId;
		};
		
		void setBookId(int b) {
			bookId = b;
		};
};

class Member {
	private:
		int id;
		string name;
		string family;
		
	public:
		Member() {
		    id = 0;
		    name = "";
		    family = "";
		};
		
		int getId() {
			return id;
		};
		
		void setId(int i) {
			id = i;;
		};
		
		string getName() {
			return name;
		};
		
		void setName(string n) {
			name = n;
		};
		
		string getFamily() {
			return family;
		};
		
		void setFamily(string f) {
			family = f;
		};
};

class Book {
	private:
	    int id;
	    string name ;
	    
	public:
		Book() {
			id = 0;
			name = "";
		};
		
		int getId() {
			return id;
		};
		
		void setId(int i) {
			id = i;
		};
		
		string getName() {
			return name;
		};
		
		void setName(string n) {
			name = n;
		};
		
		void print() {
			cout << "id: " << id << ", " << "name: " << name << endl;
		}
};

class Library {
    private:
	    Book  bookList[10];
	    Member memberList[10];
	    Loan loanList[10];
	    
	    int bookListSize;
	    int memberListSize;
	    int loanListSize;
	  
    public:
    	Library() {
    		bookListSize = 0;
    		memberListSize = 0;
    		loanListSize = 0;
		};
		
		void addBook(Book book) {
			Book *ptrBook = searchBook(book.getId());
			
			if (ptrBook == NULL) {
				bookList[bookListSize] = book;
			    bookListSize++;	
			}
		}
		
		Book * searchBook(int id) {
			for (int i = 0; i < bookListSize; i++) {
		        if (bookList[i].getId() == id) {
		        	return &bookList[i];
				}
			}
			return NULL;
		}
		
		void deleteBook(int id) {
			for (int i = 0; i < bookListSize; i++) {
		        if (bookList[i].getId() == id) {
		            for (int j = i; j < bookListSize - 1; j++) {
		            	bookList[j] = bookList[j + 1];
					}
					bookListSize--;
				}
		    }
	    } 
	    
	    void addMember(Member member) {
	    	if (searchMember(member.getId()) == NULL) {
	    		memberList[memberListSize] = member;
	    	    memberListSize++;
			}
		}
		
		Member * searchMember(int id) {
			for (int i = 0; i < memberListSize; i++) {
				if (memberList[i].getId() == id) {
		        	return &memberList[i];
				}
			}
			return NULL;
		}
				
		void deleteMember(int id) {
			for (int i = 0; i < memberListSize; i++) {
				if (memberList[i].getId() == id) {
					for (int j = i; j < memberListSize - 1; j++) {
						memberList[j] = memberList[j + 1];
					}
					memberListSize--;
				}
			}
		}
		
		bool canMemberLoanBook(int memberId) {
			if (searchMember(memberId) !=  NULL && searchLoanList(memberId) != NULL) {
				return true;
			}
			return false;
		}
		
		void registerLoan(int memberId, int bookId) {
			if (searchMember(memberId) != NULL && searchBook(bookId) != NULL) {
				loanList[loanListSize].setBookId(bookId);
				loanList[loanListSize].setMemeberId(memberId);
				loanListSize++;
			}
		}
		
		Loan * searchLoanList(int memberId) {
			for (int i = 0; i < loanListSize; i++) {
				if (loanList[i].getMemberId() == memberId ) {
					return &loanList[i];
				}
			}
			return NULL;
		}
		
		void removeLoan(int bookId, int memberId) {
			for (int i = 0; i < loanListSize; i++) {
				if (loanList[i].getBookId() == bookId && loanList[i].getMemberId() == memberId ) {
					for (int j = i; j < loanListSize - 1; j++) {
						loanList[j] = loanList[j + 1];
					}
					loanListSize--;
				}
			}
		}
	};
	
	void Menu() {	
	int sizeListBook = 0;
	int valueSearch = 0;
	string number;
		
	while (number != "0") {
        cout << "1.ADD Book" << endl;
	    cout << "2.Search Book" << endl;
	    cout << "3.Delete Book" << endl;
	
        cin >> number;
    
    	Library library;
    	
    	if (number == "1") {
    	    Book book;
    	    	
    	    int id;
    	    string name;
    	    	
        	cout << "Please Enter iD And Name: " << endl;
			cin >> id >> name ;
				
			book.setId(id);
			book.setName(name);
				
			library.addBook(book);	  
		}
		
		if (number == "2") {
		    int bookId;
		    
		    Library library;
		    	
			cout << "Please Enter Value ID Book: " << endl;
			cin >> bookId;
				
			Book *bookPtr = library.searchBook(bookId);

            if (bookPtr != NULL) {
                bookPtr->print();
            } 
			else {
                cout << "Book not found!" << endl;
            }
		}
	        
	    if (number == "3") {
	        cout << "Please Enter iD: ";
		}
	}
}
	
int main() {
	 
    Menu();
	
	return 0;     	
}