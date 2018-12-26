#include <iostream>
#include <stdlib.h>
#include "FBLPost.h"

using namespace std;

class FBLPostLL{




	private:
		typedef struct Node{
			FBLPost* data;
			Node *next;
		}* node_ptr;

		node_ptr cur;
		node_ptr temp;
		node_ptr head;
		

	public:
		FBLPostLL();
		void add_node(FBLPost*);
		void del_head();
		void print();
		string read_head();
		FBLPost* getPost(string t);
		
};
