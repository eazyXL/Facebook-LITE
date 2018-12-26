#include <iostream>
#include <stdlib.h>
#include "FBLComment.h"


using namespace std;

class FBLCommentLL{




	private:
		typedef struct Node{
			Node *prev;
			FBLComment* data;
			Node *next;
		}* node_ptr;

		node_ptr cur;
		node_ptr temp;
		node_ptr head;
		

	public:
		FBLCommentLL();
		void add_node(FBLComment*);
		void del_head();
		void print();
		void printRev();
		string read_head();
		
};
