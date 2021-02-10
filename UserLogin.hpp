#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class UserLogin {
private:
    
    unordered_map< string, string > table;
    

public:
    UserLogin(); // default constructor

    void readIn(const string& filename); // add data from file to hash table

    size_t numberOfUsers(); // return the number of users

    string passWordCheck(const string& userName); // returns the passWord of the given user

    size_t wordBucketIdMethod1(const string& userName); // return the bucket number where the given user is located

    size_t wordBucketIdMethod2(const string& userName); // another way to find the bucket number where the given user is located

    bool validateUser(const string& userName); // look up given user

    bool authenticateUser(const string& userName, const string& passWord);// authenticate given user and password
       
};

UserLogin::UserLogin() {
}

// COMPLETE THE FOLLOWING FUNCTIONS

void UserLogin::readIn(const string& filename) {
    
	//name (tab) ID
	string line;
	ifstream users(filename);
	if (users.is_open()) {
		std::string letters;
		//grab word one
		//grab word two
		//make a pair
		//insert into table
		int type = 1;
		string username;
		string password;

		//grabs string separated by tab
		while(users>>letters) {
			if (type == 1) {
				username = letters;
				type = 2;
			} else {
				password = letters;
				table.insert({{username, password}});
				type = 1;
			}
		}
	}
	users.close();
	std::cout << "finished" << std::endl;
}

size_t UserLogin::numberOfUsers() {

	return table.size();
}

string UserLogin::passWordCheck(const string& userName) {

	if (validateUser(userName)) {
		return table.at(userName);
	} else {
		return "Non-existent User";
	}
}

size_t UserLogin::wordBucketIdMethod1(const string& userName) {

    // TO DO
	return table.bucket(userName);	
}

size_t UserLogin::wordBucketIdMethod2(const string& userName) {
    
    // TO DO
    	typedef unordered_map<string,string> stringmap;
	stringmap mymap;
	stringmap::hasher fn = mymap.hash_function();
	cout << "jack: " << fn("jack") << endl;
	cout << "bobeep: " << fn("bobeep") << endl;
	cout << "bucket count: " << table.bucket_count() << endl;
	return fn(userName) % table.bucket_count();
}

bool UserLogin::validateUser(const string& userName) {
    if (table.count(userName)) {
	   return true;
    } else {
	   return false; 
	}
}

bool UserLogin::authenticateUser(const string& userName, const string& passWord) { 
    
    // TO DO
     if (validateUser(userName)) {
	if (passWordCheck(userName) == passWord) {
		return true;
	} else {
		return false;
	}
     }
     return false;
		
 }
