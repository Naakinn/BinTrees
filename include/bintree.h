#ifndef BINTREE_H
#define BINTREE_H

class node {
	public:
		int key; 
		int value; 
		node* left; 
		node* right;
		 
		node(int key, int value, node* left, node* right); 
		node(int key, int value); 
		node(int key); 
}; 

class search_tree {
	private: 
		void _print(node* tmp); 
		void _r_print(node* tmp);  
		void _free(node* tmp); 
		void throw_exeption(const char* msg); 
	public: 
		node* root; 
		
		search_tree(); 
		bool is_empty(); 
		int get(int key); 
		void insert(int key, int value = 0); 
		void print(bool reversed = false); 
		void free(); 
		void remove(int key); 
}; 
#endif 
