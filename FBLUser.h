#include <iostream>
#include <stdlib.h>
#include "FBLPostLL.h"
#include <vector>


using namespace std;

class FBLUser{




	private:
		string user;
		string pass;
		string first;
		string last;
		FBLPostLL *postLL;
		vector<FBLUser*> friends;
		vector<FBLPost*> feed;

		
		

	public:
		FBLUser();
		void setUser(string s);
		void setPass(string s);
		void setFirst(string s);
		void setLast(string s);
		void addFriend(FBLUser *u);
		string getUser();
		string getPass();
		string getFirst();
		string getLast();
		string readPost();
		void post(string);
		void addFeed(string s);
		void readFeed();
		void readWall();
		void postFeed(FBLPost*);
		void printFriends();
		string readFeedDel();
		FBLPostLL* getPostLL();
		string getAuthor();
	

		
};
