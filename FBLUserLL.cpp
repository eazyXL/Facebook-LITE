#include <stdio.h>
#include "FBLUserLL.h"
#include <string>


FBLUserLL::FBLUserLL(){
	cur = new Node();
	temp = new Node();
	head = new Node();
	
	
}

void FBLUserLL::sort(){



	if(head -> data == NULL){
		cout << "userLL Empty" << endl;
	}else if(head -> next -> data == NULL){
		cout << "sorted" << endl;
		
	}else{
	bool unsorted = true;
	
	while(unsorted){
		unsorted = false;
	Node *n = head;
	Node *nn = head -> next;


		while(true){
			
			if((*(n -> data)).getLast() > (*(nn -> data)).getLast()){
				FBLUser *tmp = n -> data;
				n -> data = nn -> data;
				nn -> data = tmp;
				unsorted = true;
			}

			if(nn -> next -> data == NULL){
				break;
			}
			n = n -> next;
			nn = nn -> next;

		}

		}
	
	}












}





void FBLUserLL::add_node(FBLUser *u){
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

void FBLUserLL::print(){
	cout << "\n" << endl;
	if(head -> data == NULL){
		cout << "userLL Empty" << endl;
	}else{
	Node *n = head;
		while(true){
			cout << (*(n -> data)).getLast() << ", ";
			cout << (*(n -> data)).getFirst() << " <";
			cout << (*(n -> data)).getUser() << ">" << endl;
			if(n -> next -> data == NULL){
				break;
			}
			n = n -> next;

		}
	
	}
	

	
}

void FBLUserLL::del_head(){
	if(head -> data != NULL && head -> next != NULL){
		head = head -> next;
	}else{
	head -> data == NULL;
	}
	
}

int FBLUserLL::validLogin(string u, string p){
	
	if(head -> data == NULL){
		return 0;
	}


	Node *n = head;
		while(true){
			if( u == ((*(n -> data)).getUser()) && p == ((*(n -> data)).getPass()) ){
				return 1;
			}
			if(n -> next -> data == NULL){
				break;
			}
			n = n -> next;

		}


	return 0;
}


int FBLUserLL::validUser(string u){
	
	if(head -> data == NULL){
		return 0;
	}


	Node *n = head;
		while(true){
			if( u == ((*(n -> data)).getUser())){
				return 1;
			}
			if(n -> next -> data == NULL){
				break;
			}
			n = n -> next;

		}


	return 0;
}




void* FBLUserLL::getNode(string u, string p){
	Node *r = new Node();

	if(head -> data == NULL){
		return r;
	}


	Node *n = head;
		while(true){
			if( u == ((*(n -> data)).getUser()) && p == ((*(n -> data)).getPass()) ){
				return n->data;
			}
			if(n -> next -> data == NULL){
				break;
			}
			n = n -> next;

		}


	return r;
}



void* FBLUserLL::getUser(string u){
	Node *r = new Node();

	if(head -> data == NULL){
		return r;
	}


	Node *n = head;
		while(true){
			if( u == ((*(n -> data)).getUser())){
				return n->data;
			}
			if(n -> next -> data == NULL){
				break;
			}
			n = n -> next;

		}


	return r;
}





/*
 	private:
		typedef struct Node{
			FBLUser* data;
			Node *next;
		}* node_ptr;

		node_ptr cur;
		node_ptr temp;
		node_ptr head;
		

	public:
		FBLUserLL();
		void add_node(FBLUser*);
		void del_head();
		void print();

		*/
