#include "FBLUser.h"
#include <stdio.h>



FBLUser::FBLUser(){
	user = "userid";
	pass = "password";
	first = "first name";
	last = "last name";
	postLL = new FBLPostLL();
}

/*getters*/
string FBLUser::getUser(){
	return user;	
}
string FBLUser::getPass(){
	return pass;
}	
string FBLUser::getFirst(){
	return first;
}
string FBLUser::getLast(){
	return last;
}
string FBLUser::readPost(){
	return (*postLL).read_head();
}
string FBLUser::getAuthor(){
	int x = feed.size() -1;
	string ret = feed[x] -> getAuthor();
	return ret;
}
string FBLUser::readFeedDel(){
	int x = feed.size() - 1;
	string ret = feed[x] -> getText();
	feed.pop_back();
	return ret;
}
FBLPostLL* FBLUser::getPostLL(){
	return postLL;

}


/*setters*/
void FBLUser::setUser(string s){
	user = s;
}
void FBLUser::setPass(string s){
	pass = s;
}
void FBLUser::setFirst(string s){
	first = s;
}
void FBLUser::setLast(string s){
	last = s;
}
void FBLUser::post(string s){
	addFeed(s);
	FBLPost *temp = new FBLPost;
	(*temp).setText(s);
	(*temp).setAuthor(user);
	(*postLL).add_node(temp);

}
void FBLUser::addFriend(FBLUser *u){
	friends.push_back(u);

}

void FBLUser::addFeed(string s){
	FBLPost *temp = new FBLPost;
	(*temp).setText(s);
	(*temp).setAuthor(user);
	
	for(int i = 0; i < friends.size(); i++){
		FBLUser *user;
		user = friends[i];
		(*user).postFeed(temp);

	}
	
}

void FBLUser::postFeed(FBLPost* p){
	feed.push_back(p);
}
void FBLUser::readFeed(){
	for(int i = 0; i < feed.size(); i++){
	string t = feed[i] -> getText();
	cout << t << "\n" << endl;
		
	}


}
void FBLUser::readWall(){
	(*postLL).print();
}

void FBLUser::printFriends(){
	for(int i = 0; i < friends.size(); i++){
		FBLUser *temp;
		temp = friends[i];
		cout << (*temp).getFirst() << " " << (*temp).getLast() << "\n" << endl;
	}
}



