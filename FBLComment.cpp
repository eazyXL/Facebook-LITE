#include <stdio.h>
#include "FBLComment.h"


FBLComment::FBLComment(){
	text = "";
	first = "";
	last = "";
}

/*setters*/
void FBLComment::setText(string s){
	text = s;
}
void FBLComment::setFirst(string s){
	first = s;
}
void FBLComment::setLast(string s){
	last = s;
}

/*getters*/

string FBLComment::getText(){
	return text;
}
string FBLComment::getFirst(){
	return first;
}
string FBLComment::getLast(){
	return last;
}
