#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "FBLUserLL.h"

using namespace std;


	FBLUserLL *userLL = new FBLUserLL();
	FBLUser *logged = new FBLUser();




int readMenu(){
	string user = (*logged).getAuthor();
	string text = (*logged).readFeedDel();
	
	

	FBLUser *tmp;
	void *ptr = (*userLL).getUser(user);
	tmp = static_cast<FBLUser *>(ptr);

	FBLPostLL *postLL = (*tmp).getPostLL();
	FBLPost *thepost = (*postLL).getPost(text);

	cout << (*tmp).getFirst() << " " << (*tmp).getLast() << endl;
	cout << (*thepost).getText() << endl;
	cout << "\n" << endl;
	




	while(true){
	cout << "\n" << endl;
	cout << "LIKE" << endl;
	cout << "or" << endl;
	cout << "COMMENT <text>" << endl;
	cout << "or" << endl;
	cout << "READ_AZ" << endl;
	cout << "or" << endl;
	cout << "READ_ZA" << endl;
	cout << "or" << endl;
	cout << "DONE" << endl;
	string s;
	getline(cin, s);

	if(s == "DONE"){
		break;
	}else if(s == "LIKE"){
		(*thepost).like();
	}else if(s == "READ_AZ"){
		(*thepost).printComments();

	}else if(s == "READ_ZA"){
		(*thepost).printCommentsRev();

	}else{

	int i;
	i = s.find(' ', 0);
	string first = s.substr(0, i );
	string temp = s.substr(i+1, i + 2); 
	string second;

	while(true){
		if(temp != " "){
			break;
		}else{
		i = i +1;
		temp = s.substr(i+1, i+2);
		}
	}
	second = s.substr(i+1);
		if(first == "COMMENT"){
			(*thepost).comment(second, (*logged).getFirst(), (*logged).getLast());
			cout << second << endl;
		}
		

	}




	}


return 0;
}





int logMenu(){
	
	while(true){
	cout << "\n" << endl;
	cout << "LOGOUT" << endl;
	cout << "or" << endl;
	cout << "POST <text>" << endl;
	cout << "or" << endl;
	cout << "FRIEND <userid>" << endl;
	cout << "or" << endl;
	cout << "MYFRIENDS" << endl;
	cout << "or" << endl;
	cout << "MYFEED" << endl;
	cout << "or" << endl;
	cout << "MYWALL" << endl;
	cout << "or" << endl;
	cout << "READ\n" << endl;
	string s;
	getline(cin, s);

	if(s == "LOGOUT"){
	FBLUser *t = new FBLUser();
	logged = t;
	break;
	}
	
	if(s == "MYFRIENDS"){
	(*logged).printFriends();
	}
	if(s == "MYFEED"){
	(*logged).readFeed();
	}
	if(s == "MYWALL"){
		(*logged).readWall();
	}


	if(s == "READ"){
		readMenu();
	}else{
		
	int i;
	i = s.find(' ', 0);
	string first = s.substr(0, i );
	string temp = s.substr(i+1, i + 2); 
	string second;

	while(true){
		if(temp != " "){
			break;
		}else{
		i = i +1;
		temp = s.substr(i+1, i+2);
		}

	}
	second = s.substr(i+1);
	if(first == "POST"){
	(*logged).post(second);
	}
	
	
	if(first == "FRIEND"){


		int k = (*userLL).validUser(second);
		if(k == 0){
			cout << "No User with that Username\n" << endl;
		}else{
			FBLUser *tmp;
			void *ptr = (*userLL).getUser(second);
			tmp = static_cast<FBLUser *>(ptr);
			(*logged).addFriend(tmp);
			(*tmp).addFriend(logged);	
		}



	}

	


	}
		



	}



return 0;
}

int main(int argc, char** argv){

	while(true){
		cout << "\n" << endl;
	cout << "CREATE <Userid> <Password> <First> <Last>" << endl;
	cout << "or" << endl;
	cout << "USERS" << endl;
	cout << "or" << endl;
	cout << "SORTUSERS" << endl;
	cout << "or" << endl;
	cout << "LOGIN <Userid> <passwd>" << endl;
	cout << "or" << endl;
	cout << "QUIT\n" << endl;

	 

		
	
	string s;
	getline(cin, s);


	if(s == "USERS"){
		(*userLL).print();	
	
	}

	if(s == "SORTUSERS"){
		(*userLL).sort();	


	}

	if(s == "QUIT"){
	break;
	}
	
	vector<string> broken;
	istringstream iss(s);

	for(string s; iss >> s;){
		broken.push_back(s);
	}

	if(broken[0] == "CREATE"){

		int v = 0;
	        v = (*userLL).validUser(broken[1]);
		if(v == 0){
		FBLUser *t = new FBLUser();
		(*t).setUser(broken[1]);
		(*t).setPass(broken[2]);
		(*t).setFirst(broken[3]);
		(*t).setLast(broken[4]);
		(*userLL).add_node(t);
		cout << "User Created\n" << endl;
		}else{
			cout << "User already exists \n" << endl;
		}
		
	}

	if(broken[0] == "LOGIN"){
		int k = 0;
		string user = "";
		string pass = "";
		if(broken.size() != 3){
			k = 0;
		}else{
		user = broken[1];
		pass = broken[2];
		k = (*userLL).validLogin(user, pass);
		}
		if(k == 0){
			cout << "No User with that Username and Password\n" << endl;
		}else{
			cout<< "Login Successful\n" << endl;
			void *ptr = (*userLL).getNode(user, pass);
			logged = static_cast<FBLUser *>(ptr);
			logMenu();	
		}


	
	}
	
	}


return 0;
}


