#include <iostream>
#include <stdlib.h>
#include "FBLUser.h"

using namespace std;

class FBLUserLL{




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
		int validLogin(string u, string p);
		int validUser(string u);
		void* getNode(string u, string p);
		void* getUser(string u);
		void sort();	
		
};
