#include "AVLNode.h"
#include <iostream>



using namespace std;

AVLNode::AVLNode(int key){
		this->key=key;
		this->left=0;
		this->right=0;
		this->amount=1;
	}

int AVLNode::correct_height(){
	if(this==0)
		return 0;
	int a=this->left->correct_height();
	int b=this->right->correct_height();
	if(a>b)
		return a+1;
	else
		return b+1;
}

int AVLNode::defect_height(){
	if(this==0)
		return 0;
	return this->left->correct_height()-this->right->correct_height();
}

int AVLNode::get_amount(){
	if(this==0)
		return 0;
	return this->amount;
}

AVLNode* AVLNode::rotate_left(){
	AVLNode *p=this;
	AVLNode *q=this->right;
	p->right=q->left;
	q->left=p;
	p->amount=p->amount-(q->right->get_amount()+1);
	q->amount=q->amount+(p->left->get_amount()+1);
	return q;
}

AVLNode* AVLNode::rotate_right(){
	AVLNode *p=this;
	AVLNode *q=this->left;
	p->left=q->right;
	q->right=p;
	p->amount=p->amount-(q->left->get_amount()+1);
	q->amount=q->amount+(p->right->get_amount()+1);
	return q;
}

AVLNode* AVLNode::correctm2(){
	AVLNode *p=this;
	AVLNode *q=this->right;
	if(q->defect_height()>0){
		q=q->rotate_right();
		p->right=q;
	}
	p=p->rotate_left();
	return p;
}


AVLNode* AVLNode::correct2(){
	AVLNode *p=this;
	AVLNode *q=this->left;
	if(q->defect_height()<0){
		q=q->rotate_left();
		p->left=q;
	}
	p=p->rotate_right();
	return p;
}

AVLNode* AVLNode::rebalance(){
	AVLNode *p=this;
	if(this->defect_height()==-2){
		p=p->correctm2();
	}
	else if(this->defect_height()==2){
		p=p->correct2();
	}
	return p;
}

AVLNode* AVLNode::insert(int key){
	AVLNode *p=0;
	if(this==0){
		p=new AVLNode(key);
		return p;
	}
	if(key<this->key){
		this->left=this->left->insert(key);
	}
	else{
		this->right=this->right->insert(key);
	}
	this->amount++;
	p=this->rebalance();
	return p;
}

void AVLNode::print_all(int offset){
	if(this==0) return;
	this->left->print_all(offset+6);
	for(int i=0;i<offset;i++)
		cout << " ";
	cout << this->key << endl;
	this->right->print_all(offset+6);
}

int AVLNode::search_k_min(int k){
	if(k<=this->left->get_amount())
		return this->left->search_k_min(k);
	else if(k==this->left->get_amount()+1)
		return this->key;
	else if(k<=this->amount)
		return this->right->search_k_min(k-this->left->get_amount()-1);
	else{
		cout << "k не может быть больше количества вершин" << endl;
		return 0;
	}
}

int AVLNode::amount_less_k(int k){
	if(this==0)
		return 0;
	if(k==this->key)
		return this->left->get_amount();
	if(k<this->key)
		return this->left->amount_less_k(k);
	return this->left->get_amount()+1+this->right->amount_less_k(k);
}
