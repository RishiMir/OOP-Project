#include<iostream>
#include <string>
#include <sstream>
#include<fstream>
using namespace std;
class Sign_in {};
class Sign_up_User {
private:
	string dob; 
	string gender;
	int age;
	string Username;
	int password;
	string email;
	int phno;
public:
	string a, b,str1,Dob;
	int A, B,ag,Day,Month,Year;
	void setAge() {
		cout << "Enter Age" << endl;
		cin >> ag;
		if (ag > 16 && ag < 80) { // Age validation
			age = ag;
		}
		else {
			cout << "Invalid age!Setting to default (16)." << endl;
			age = 16;
		}
	}

	void setDateOfBirth() {
		cout << "Enter the date in dd/mm/yyyy format: ";
		cin >> Dob;


		for (char& ch : Dob) {
			if (ch == '/') {
				ch = ' ';
			}
		}

		istringstream dateStream(Dob);
		dateStream >> Day >> Month >> Year;

		if (dateStream.fail() || Day < 1 || Day > 31 || Month < 1 || Month > 12 || Year > 2024) {
			cout << "Invalid date format!" << endl;
		}
		else {
//apply file handling to write dob
		}
	}
	string str2;
	void setGender() {
		cout << "Enter your Gender" << endl;
		cin >> str2;
		if (str2 == "Male" || str2 == "Female" || str2 == "Other") {
			gender = str2;
		}
		else {
			cout << "Invalid gender! Setting to default (Other)." << endl;
			gender = "Other";
		}
	}


	// Getters
	int getAge() const {
		return age;
	}

	string getDateOfBirth() const {
		return dob;
	}

	string getGender() const {
		return gender;
	}
	void set_Username() {
		cout << "Enter your Username for account creation" << endl;
		getline(cin, a);
		Username = a;
	}
	void set_Password() {
		cout << "Set your 4 number pin" << endl;
		cin >> A;
		if (A > 999 && A < 10000) {
			password = A;
		}
		else if (A < 999 || A > 10000) {
			cout << "Invalid pin" << endl;
		}
	}
	void set_Email() {
		cout << "Enter your Email for account creation" << endl;
		getline(cin, b);
		email = b;
	}
	void set_phno() {
		cout << "Enter Your Phone Number" << endl;
		cin >> B;
		if (B / 10000000000 == 0 && B / 1000000000 == 3 && B < 1000000000000 && B>10000000000) {
			phno = B;
		}
		else {
			cout << "Invalid Number" << endl;
		}
	}
	//apply file handling for class/file user and use inheritance for class user and page.
	friend class Sign_in;
};
class Sign_in {
private:
	string User_name;
	int pass_word;
public:
	friend class Sign_up;
	void Check_Username_pass(Sign_up_User& acc) {//a
		cout << "Enter Username" << endl;
		getline(cin, User_name);
		if (strcmp(User_name.c_str(), acc.Username.c_str()) == 0) {
			cout << "You entered the right username" << endl;
		}
		else {
			cout << "You entered the wrong Username" << endl;
		}
	cout << "Enter 4 digit pin" << endl;
	cin >> pass_word;
	if (pass_word == acc.password) {
		cout << "Correct passowrd" << endl;
	}
	else {
		cout << "Re-enter your password" << endl;
	}
}

};
class Sign_in_Page;
class Sign_Up_Page {
private:
	string Username;
	int password;
	string email;
	int phno;
	string Doc;
public:
	string a, b, str1, Doc;
	int A, B, Day, Month, Year;
	void setDateOfCreation() {
		cout << "Enter the date in dd/mm/yyyy format: ";
		cin >> Doc;


		for (char& ch : Doc) {
			if (ch == '/') {
				ch = ' ';
			}
		}

		istringstream dateStream(Doc);
		dateStream >> Day >> Month >> Year;

		if (dateStream.fail() || Day < 1 || Day > 31 || Month < 1 || Month > 12 || Year > 2024) {
			cout << "Invalid date format!" << endl;
		}
		else {
			//apply file handling to write dob
		}
	}
	void set_Username() {
		cout << "Enter your Username for page creation" << endl;
		getline(cin, a);
		Username = a;
	}
	void set_Password() {
		cout << "Set your 4 number pin" << endl;
		cin >> A;
		if (A > 999 && A < 10000) {
			password = A;
		}
		else if (A < 999 || A > 10000) {
			cout << "Invalid pin" << endl;
		}
	}
	void set_Email() {
		cout << "Enter your Email for page creation" << endl;
		getline(cin, b);
		email = b;
	}
	void set_phno() {
		cout << "Enter Your Phone Number" << endl;
		cin >> B;
		if (B / 10000000000 == 0 && B / 1000000000 == 3 && B < 1000000000000 && B>10000000000) {
			phno = B;
		}
		else {
			cout << "Invalid Number" << endl;
		}
	}
	//apply file handling for class/file user and use inheritance for class user and page.
	friend class Sign_in_Page;
};



class Sign_in_Page {
private:
	string User_name;
	int pass_word;

public:
	friend class Sign_up_Page;

	void Check_Username_pass(Sign_Up_Page& page) {
		cout << "Enter Username: ";
		cin.ignore();  // Clear buffer before reading input
		getline(cin, User_name);

		if (User_name == page.Username) {
			cout << "You entered the correct username." << endl;
			cout << "Enter your 4-digit pin: ";
			cin >> pass_word;

			if (pass_word == page.password) {
				cout << "Login successful! Correct password." << endl;
			}
			else {
				cout << "Incorrect password! Please try again." << endl;
			}
		}
		else {
			cout << "Invalid username. Access denied." << endl;
		}
	}
};
class Post {
private:
public:
	int emotion;
	string Emo, Text_post;
	string dateInput;
	int day, month, year;
	void create_post() {
		string Text_post;
		while (true) {
			cout << "Create your post" << endl;
			cout << "Enter text (must end with a full stop): ";
			getline(cin, Text_post);
			if (!Text_post.empty() && Text_post.back() == '.') {
				cout << "Your post: " << Text_post << endl;
				break;
			}
			else {
				cout << "Invalid input. The text must end with a full stop ('.'). Please try again." << endl;
			}
		}

		cout << "How are you feeling" << endl;
		cout << "1. Happy\n2. Sad\n3. Angry\n4. Hungry\n" << endl;
		cin >> emotion;
		if (emotion / 10 == 0) {
			if (emotion == 1) {
				string emoji3;
				int emoj1;
				Emo = "Happy";
				cout << "Do you want to add emoji(yes/no)" << endl;
				cin >> emoji3;
				if (emoji3 == "yes") {
					cout << "1.smiley face\2.tears of joy(Enter 1 or 2)" << endl;
					cin >> emoj1;
						if (emoj1 == 1) {
							//use smfl
							//use file hanling
							emoji3 = "Smiley Face Emoji";
								cout << "Smiley face emoji saved" << endl;
						}
						else if (emoj1 == 2) {
							//use smfl
							//use file hanling
							emoji3 = "Tears of joy";
							cout << "Tears of joy emoji saved" << endl;
						}
						else {
							emoji3 = "Grinning Face";
							cout << "Grinning Face saved(default)" << endl;
						}
						
				}
			}
			if (emotion == 2) {
				string emoji4;
				int emoj2;
				Emo = "Sad";
				cout << "Do you want to add emoji(yes/no)" << endl;
				cin >> emoji4;
				if (emoji4 == "yes") {
					cout << "1.Disappointment\2.Crying(Enter 1 or 2)" << endl;
					cin >> emoj2;
					if (emoj2 == 1) {
						//use smfl
						//use file hanling
						emoji4 = "Disappointment Emoji";
						cout << "Disappointmen emoji saved" << endl;
					}
					else if (emoj2 == 2) {
						//use smfl
						//use file hanling
						emoji4 = "Crying";
						cout << "Crying emoji saved" << endl;
					}
					else {
						emoji4 = "Stunned in Agony";
						cout << "Stunned in agony saved";
					}
				}
			}
			if (emotion == 3) {
				string emoji5;
				int emoj3;
				Emo = "Angry";
				cout << "Do you want to add emoji(yes/no)" << endl;
				cin >> emoji5;
				if (emoji5 == "yes") {
					cout << "1.Yellow Face\2.Frowning Face(Enter 1 or 2)" << endl;
					cin >> emoj3;
					if (emoj3 == 1) {
						//use smfl
						//use file hanling
						emoji5 = "Yellow Face";
						cout << "Yellow Face emoji saved" << endl;
					}
					else if (emoj3 == 2) {
						//use smfl
						//use file hanling
						emoji5 = "Frowning";
						cout << "Frowning emoji saved" << endl;
					}
					else {
						emoji5 = "Flaming";
						cout << "Flaming saved";
					}
				}
			}
			if (emotion == 4) {
				Emo = "Hungry";
			}
		}
		cout << "Enter the date in dd/mm/yyyy format: ";
		cin >> dateInput;


		for (char& ch : dateInput) {
			if (ch == '/') {
				ch = ' ';
			}
		}

		istringstream dateStream(dateInput);
		dateStream >> day >> month >> year;

		if (dateStream.fail() || day < 1 || day > 31 || month < 1 || month > 12 || year > 2024) {
			cout << "Invalid date format!" << endl;
		}
		else {
			cout << "Day: " << day << ", Month: " << month << ", Year: " << year << endl;
		}
			string location;

			while (true) {
				cout << "Enter alphabets only: ";
				cin >> location;

				// Check if input is alphabetic
				bool Loc = true;
				for (char ch : location) {
					if (!isalpha(ch)) {
						Loc = false;
						break;
					}
				}

				if (Loc) {
					cout << "The location is: " << location << endl;
				}
				else {
					cout << "Invalid input. Please enter alphabets only." << endl;
				}
			}
		}
	//Revisit for file handling and comparision
	void Tag() {
		int j;
		string User, page;
		cout << "1.Tag User\n2.Tag page" << endl;
		cin >> j;
		if (j == 1) {
			cout << "Enter the user you want to Tag" << endl;
			getline(cin, User);
			if (User) {
				cout << "User Tagged" << endl;
			}
			else {
				cout << "User Not found" << endl;
			}

		}
		else if (j == 2) {
			cout << "Enter the Page you want to Tag" << endl;
			getline(cin, page);
			if (page) {
				cout << "Page Tagged" << endl;
			}
			else {
				cout << "Page Not found" << endl;
			}
		}
		else {
			cout << "Please try Again,Enter a Valid command" << endl;
		}
	}
};
class memory {
private:

public:
	int emot,emoji2;
	string str1,caption,emotion1,emoji,Userita;
	void Share_memory() {
		cout << "Enter the post number you want to share: " << endl;
		cin >> str1;
		//apply file handling to check if post exists
		if (exists) {
			cout << "Give Caption" << endl;
			getline(cin, caption);
			cout << "Enter your Emotion" << endl;
			cout << "1.Nostalgia\n2.cringe\n" << endl;
			cin >> emot;
			if (emot == 1) {
				emotion1 = "Nostalgia";
				cout << "Do you want to use an emoji(yes/no)" << endl;
				cin >> emoji;
				if (emoji == "yes") {
					cout << "Select an emoji to express your inner feeling" << endl;
					cout << "1.Pleading face emoji\n2.pensive face Emoji" << endl;
					cin >> emoji2;
				}
				else if(emoji=="no") {
					cout << "Proceeding without an emoji" << endl;
				}
				}
			if (emot == 2) {
				emotion1 = "Cringe";
				cout << "Do you want to use an emoji(yes/no)" << endl;
				cin >> emoji;
				if (emoji == "yes") {
					cout << "Select an emoji to express your inner feeling" << endl;
					cout << "1.Awkward Grimace\n2.Melting Face" << endl;
					cin >> emoji2;
				}
			}
			cout << "Enter the user or page you want to Tag" << endl;
			getline(cin, Userita);
			//open file
			//read file
			//if statements
			cout << "User has been tagged" << endl;
			//else statements
			cout << "User not found" << endl;
			cout<<"Continuing without tagging anyone"<<endl;
			}
		
	}
	
};

class comment {
private:
string username;
string commenttext;
string taggeduser;
public:
void addcommemt{
	cout <<"Enter username"<<endl;
	getline(cin,username);
	cout << "Enter comment text "<<endl;
	getline(cin,taggeduser);
	if (commentText.empty() || commentText.back() != '.') {
            cout << "Invalid comment. Must end with a full stop ('.'). Try again." << endl;
            return;
        }

        // Optional tagging
        char choice;
        cout << "Do you want to tag a user? (y/n): ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter the username to tag: ";
            getline(cin, taggedUser);
        } else {
            taggedUser = "None";
        }
}
class highlights {

};
