#ifndef _BSTREE_H
#define _BSTREE_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename KEY_T, typename VAL_T>
struct Node {
	KEY_T key;
	VAL_T value;
	Node<KEY_T, VAL_T> *left;
	Node<KEY_T, VAL_T> *right;
};

template <typename KEY_T, typename VAL_T>
class BinaryTree {
private:
	Node<KEY_T, VAL_T> *root;
	
	void destroy_subtree(Node<KEY_T, VAL_T> *subtree) {
		if (subtree != NULL) {
			destroy_subtree(subtree->left);
			destroy_subtree(subtree->right);
			delete subtree;
		}
	}
	
	void insert(KEY_T key, VAL_T val, Node<KEY_T, VAL_T> *subtree) {
		if (key < subtree->key) {
			if (subtree->left != NULL)
				insert(key, val, subtree->left);
			else {
				subtree->left = new Node<KEY_T, VAL_T>;
				subtree->left->key = key;
				subtree->left->value = val;
				subtree->left->left = NULL;
				subtree->left->right = NULL;
			}
		}
		
		else if (key >= subtree->key)
		{
			if (subtree->right != NULL)
				insert(key, val, subtree->right);
			else
			{
				subtree->right = new Node<KEY_T, VAL_T>;
				subtree->right->key = key;
				subtree->right->value = val;
				subtree->right->left = NULL;
				subtree->right->right = NULL;
			}
		}
	}
	
	Node<KEY_T, VAL_T>* search(KEY_T& key, Node<KEY_T, VAL_T> *subtree)
	{
		if (subtree != NULL) {
			if (key == subtree->key)
				return subtree;
			if (key < subtree->key)
				return search(key, subtree->left);
			else
				return search(key, subtree->right);
		}
		else return NULL;
	}

	Node<KEY_T, VAL_T>* min_el(Node<KEY_T, VAL_T>* subtree){
		while(subtree->left != NULL) subtree = subtree->left;
		return subtree;
	}

	void del(KEY_T key, Node<KEY_T, VAL_T> *subtree) {
		if(subtree == NULL) return;
		else if(key < subtree->key) subtree->left = del(key, subtree->left);
		else if(key > subtree->key) subtree->right = del(key, subtree->right);
		else {
			if (subtree->left == NULL && subtree->right == NULL) { 
				delete subtree;
				subtree = NULL;
			}
			else if (subtree->right != NULL) {
				Node<KEY_T, VAL_T> *tmp = new Node<KEY_T, VAL_T>;
				tmp = subtree;
				subtree = subtree->right;
				delete tmp;
			}
			else if (subtree->left != NULL) {
				Node<KEY_T, VAL_T> *tmp = new Node<KEY_T, VAL_T>;
				tmp = subtree;
				subtree = subtree->left;
				delete tmp;
			}
			else {
				Node<KEY_T, VAL_T> *tmp = new Node<KEY_T, VAL_T>;
				tmp = min_el(subtree->right);
				subtree->data = tmp->data;
				subtree->ker = tmp->key;
				subtree->right = del(tmp->key, subtree->right);
			}
		}
	}

public:
	//friend class Marker;
	//to be continued..
	BinaryTree() {
		root = NULL;
	}
	
	~BinaryTree() {
		destroy_subtree(root);
	}
	
	void Insert(KEY_T key, VAL_T val) {
		if (root != NULL)
			insert(key, val, root);
		else {
			root = new Node<KEY_T, VAL_T>;
			root->key = key;
			root->value = val;
			root->left = NULL;
			root->right = NULL;
		}
	}
	
	Node<KEY_T, VAL_T>* Search(KEY_T key) {
		return search(key, root);
	}
	
	VAL_T& operator[](KEY_T key) {
		Node<KEY_T, VAL_T>* node = search(key, root);
		if (node != NULL)
			return node->value;
		else
			throw std::logic_error("No such element in the tree");
	}

	Node<KEY_T, VAL_T>* Del(KEY_T key) {
		return del(key, root);
	}
};

#endif