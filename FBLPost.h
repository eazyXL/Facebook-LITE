#include <iostream>
#include <stdlib.h>
#include "FBLCommentLL.h"

using namespace std;

class FBLPost{

	private:
		int likes;
		string text;
		FBLCommentLL *commentLL;
		string author;
		
		

	public:
		FBLPost();
		void setLikes(int i);
		void setText(string s);
		void setAuthor(string s);
		int getLikes();
		string getText();
		void comment(string t, string f, string l);
		string getAuthor();
		void like();
		void printComments();
		void printCommentsRev();
	

};		



