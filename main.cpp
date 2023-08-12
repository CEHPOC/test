#include "AVLNode.h"
#include <iostream>

int main(){
	AVLNode *p=0;
	char key;
	int number;
	while(true){
		std::cin >> key >> number;
		if(key=='k'){
			p=p->insert(number);
			p->print_all(0);
		}
		else if(key=='m')
			std::cout << p->search_k_min(number) << " ";
		else if(key=='n')
			std::cout << p->amount_less_k(number) << " ";
	}
}
