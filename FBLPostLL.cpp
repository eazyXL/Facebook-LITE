#include <stdio.h>
#include "FBLPostLL.h"


FBLPostLL::FBLPostLL(){
	cur = new Node();
	temp = new Node();
	head = new Node();
	
	
}

void FBLPostLL::add_node(FBLPost *u){
	if(head -> data == NULL){
		head -> data = u;
		head -> next = cur;	
	}else{
	cur -> data = u;
	cur -> next = temp;
	temp = new Node();
	cur = cur -> next;
	

	}

}

void FBLPostLL::print(){
	if(head -> data == NULL){
		cout << "postLL Empty" << endl;
	}else{
	Node *n = head;
		while(true){
			cout << "Likes: " << (*(n -> data)).getLikes() << " ";
			cout << (*(n -> data)).getText() << endl;
			cout << "\n" << endl;
			if(n -> next -> data == NULL){
				break;
			}
			n = n -> next;

		}
	
	}
	

	
}

void FBLPostLL::del_head(){
	if(head -> data != NULL && head -> next != NULL){
		head = head -> next;
	}else{
	head -> data == NULL;
	}
	
}

string FBLPostLL::read_head(){
	if(head -> data == NULL){
		return "Nothing to READ";
	}

	if(head -> data != NULL && head -> next != NULL){
		string x = (*(head->data)).getText();
		head = head -> next;
		return x;
	}else{
	string x = (*(head->data)).getText();
	head -> data == NULL;
	return x;
	}


}

FBLPost* FBLPostLL::getPost(string t){
	cur = head;

	while(true){
		if((*(cur -> data)).getText() == t){
			return cur -> data;
		
		}
		cur = cur -> next;
	
	}


}

