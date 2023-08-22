#include <iostream>
#include <fstream>
#include <string>
#include "AVLNode.h"


using namespace std;

int get_number(string str, int i){
	int number=0;
	bool positive=true;
	if(str[i]=='-'){
		positive=false;
		i++;
	}
	while(str[i]!=' '&&i<str.size()){
		number=number*10+(str[i]-'0');
		i++;
	}
	if(!positive){
		number=number*(-1);
	}
	return number;
}

int main(){
	ifstream fin("test.in");
	ifstream finresult("test.out");
	string line;
	AVLNode *root;
	int answer;
	bool flag;


	while(getline(fin,line)){
		root=0;
		flag=true;
		for(int i=0;i<line.size();i++){
			if(line[i]=='k'){
				i=i+2;
				root=root->insert(get_number(line,i));
			}
			else if(line[i]=='m'){
				i=i+2;
				finresult >> answer;
				if(answer!=root->search_k_min(get_number(line,i)))
					flag=false;
			}
			else if(line[i]=='n'){
				i=i+2;
				finresult >> answer;
				if(answer!=root->amount_less_k(get_number(line,i)))
					flag=false;
			}
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
