#include "AVLNode.h"
#include <iostream>

using namespace std;

int main(){
	AVLNode *p=0;
	char key;
	int number;
	while(true){
		std::cin >> key >> number;
		if(key=='k'){
			p=p->insert(number);
			p->print_all(0);
			cout << endl;
		}
		else if(key=='m')
			cout << p->search_k_min(number) << endl;
		else if(key=='n')
			cout << p->amount_less_k(number) << endl;
	}
}
