#include <stdio.h>
#include "FBLPost.h"


FBLPost::FBLPost(){
	likes = 0;
	text = "";
	author = "";
	commentLL = new FBLCommentLL(); 

}

/*setters*/
void FBLPost::setLikes(int i){
	likes = i;
}
void FBLPost::setText(string s){
	text = s;
}
void FBLPost::setAuthor(string s){
	author = s;
}
void FBLPost::comment(string t, string f, string l){

	FBLComment *comm = new FBLComment();
	(*comm).setText(t);
	(*comm).setFirst(f);
	(*comm).setLast(l);
	(*commentLL).add_node(comm);
}
void FBLPost::like(){
	likes++;
}

/*getters*/
int FBLPost::getLikes(){
	return likes;
}
string FBLPost::getText(){
	return text;
}
string FBLPost::getAuthor(){
	return author;
}
void FBLPost::printComments(){
	(*commentLL).print();
}
void FBLPost::printCommentsRev(){
	(*commentLL).printRev();
}
