#include <iostream>
#include <stdlib.h>


using namespace std;

class FBLComment{

	private:
		string text;
		string first;
		string last;
		
		

	public:
		FBLComment();
		string getFirst();
		string getLast();
		string getText();
		void setFirst(string s);
		void setLast(string s);
		void setText(string s);
		

};		



