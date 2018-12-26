#include <stdio.h>
#include "FBLCommentLL.h"


FBLCommentLL::FBLCommentLL(){
	cur = new Node();
	temp = new Node();
	head = new Node();
	
	
	
}

void FBLCommentLL::add_node(FBLComment *u){

	if(head -> data == NULL){
		head -> data = u;
		head -> next = cur;
		cur -> prev = head;	
	}else{
	cur -> data = u;
	cur -> next = temp;
	temp -> prev = cur;
	temp = new Node();
	cur = cur -> next;
	

	}

}

void FBLCommentLL::print(){
	cout << "\n" << endl;

	if(head -> data == NULL){
		cout << "commentLL Empty" << endl;
	}else{
	Node *n = head;
		while(true){
			cout << (*(n -> data)).getFirst() << " " << (*(n -> data)).getLast() <<  endl;
			cout << (*(n -> data)).getText() << endl;
			cout << "\n" << endl;
			if(n -> next -> data == NULL){
				break;
			}
			n = n -> next;

		}
	
	}
	

	
}

void FBLCommentLL::printRev(){
	Node *revHead = new Node();
	cout << "\n" << endl;

	if(head -> data == NULL){
		cout << "commentLL Empty" << endl;
	}else{
	Node *n = head;
		while(true){

			if(n -> next -> data == NULL){
				revHead = n;
				break;
			}
			n = n -> next;

		}
	
	}


	if(revHead -> data == NULL){
		cout << "commentLL Empty" << endl;
	}else{
	Node *n = revHead;
		while(true){
			cout << (*(n -> data)).getFirst() << " " << (*(n -> data)).getLast() <<  endl;
			cout << (*(n -> data)).getText() << endl;
			cout << "\n" << endl;
			if(n -> prev == NULL){
				break;
			}
			n = n -> prev;

		}
	
	}



}


void FBLCommentLL::del_head(){
	if(head -> data != NULL && head -> next != NULL){
		head = head -> next;
	}else{
	head -> data == NULL;
	}
	
}



