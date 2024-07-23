#include "bintree.h"
#include <iostream>

node::node(int key, int value, node* left, node* right): key{ key }, value{ value }, left{ left }, right{ right } {}
node::node(int key, int value): node(key, value, nullptr, nullptr) {}
node::node(int key): node(key, 0) {} 
 
search_tree::search_tree(): root{ nullptr } {};  

bool search_tree::is_empty() {
	return root == nullptr; 
}

void search_tree::insert(int key, int value) {
	node* ptr = new node{ key, value }; 
	if (this->is_empty()) {
		root = ptr; 
		return; 
	}
	node* tmp = root; 
	while (1) {
		if (tmp->key > key) {
			if (tmp->left == nullptr) {
				tmp->left = ptr; 
				return; 
			} 
			tmp = tmp->left; 
		}
		else {
			if (tmp->right == nullptr) {
				tmp->right = ptr; 
				return; 
			}
			tmp = tmp->right; 
		}
	}
		 
}
 
void search_tree::_print(node* tmp) {
	if (tmp == nullptr) return; 
	_print(tmp->left); 
	std::cout << tmp->key << ' '; 
	_print(tmp->right); 
}

void search_tree::_r_print(node* tmp) {
	if (tmp == nullptr) return; 
	_r_print(tmp->right); 
	std::cout << tmp->key << ' '; 
	_r_print(tmp->left); 
}

void search_tree::print(bool reversed) {
	node* tmp{ root }; 
	!reversed ? this->_print(tmp) : this->_r_print(tmp); 
}
 
void search_tree::throw_exeption(const char* msg) {
	std::cout << msg << '\n'; 
	std::terminate(); 
}
 
int search_tree::get(int key) {
	node* tmp = root; 
	while (1) {
		if (tmp->key == key) {
			return tmp->value; 
		}
		else if (tmp->key > key) {
			if (tmp->left != nullptr) {
				tmp = tmp->left; 
			} 
			else throw_exeption("Key is out of range"); 
		}
		else {
			if (tmp->right != nullptr) {
				tmp = tmp->right; 
			}
			else throw_exeption("Key is out of range"); 
		}
	}
} 
void search_tree::remove(int key) {
	node* tmp = root; 
	while (1) {
		if (tmp->key > key) {
			if (tmp->left != nullptr) {
				if (tmp->left->key == key) {
					delete tmp->left; 
					tmp->left = nullptr; 
					return; 
				}
				tmp = tmp->left; 
			} 	
			else throw_exeption("Key is out of range"); 
		}
		else {
			if (tmp->right != nullptr) {
				if (tmp->right->key == key) {
					delete tmp->right; 
					tmp->right = nullptr; 
					return; 
				} 
				tmp = tmp->right; 
			}
			else throw_exeption("Key is out of range"); 
		}
	} 
}
void search_tree::_free(node* tmp) {
	if (tmp == nullptr) return; 
	_free(tmp->left); 
	node* right = tmp->right; 
	delete tmp; 
	_free(right); 
}

void search_tree::free() {
	node* tmp = root; 
	_free(tmp); 
	root = nullptr; 
}
