# include <iostream>
# include <stdio.h>
# include <string.h>
using namespace std; 

const int maxsize = 11;

struct node{
	char name[8];
	int link;
};

class staticlist{
	node elem[maxsize];
	int avil;
	public:
		void initlist(){
			memset(elem,0,sizeof(elem));
			avil = 2;
			elem[0].link=avil;
			elem[1].link=0;
			for(int i=2;i<maxsize-1;i++)
			elem[i].link = i+1;
			elem[maxsize-1].link=0;
		}
		int locate(int i){
			if(i<0) return -1;
			else if(i==0) return 1;
			int j= 1,p = elem[1].link;
			while(p!=0&&j<i){
				p = elem[p].link;j++;
			}
			return p;
		}
		bool insert(int i,char* na){
			int p=locate(i-1);
			if(p == -1) return false;
			int q=avil;
			avil = elem[avil].link;
			elem[0].link = avil;
			strcpy(elem[q].name,na);
			elem[q].link=elem[p].link;
			elem[p].link=q;
			return true;
		}
		bool remove(int i){
			int p = locate(i-1);
			if(p==-1) return false;
			int q=elem[p].link;
			elem[p].link = elem[q].link;
			elem[q].link = avil;
			avil = q;
			elem[0].link = avil;
			return true;
		}
		void show(){
		    for(int i=0;i<11;i++){
		    	printf("%-8s%2d\n",elem[i].name,elem[i].link);
			}
			cout<<"********************"<<endl;
		}
		int search(char *na){
			int p= elem[1].link;
			while(p!=0){
				if(strcmp(elem[p].name,na)==0)
				break;
				else
				p = elem[p].link;
			}
			return p;
		}
};
int main(){
	char option[20];
	staticlist s;
	s.initlist();
	while(cin>>option){
		if(option[0]=='s'&&option[1]=='h'){
			s.show();
		}
		else if(option[0]=='i'){
			int i;
			char na[8];
			cin>>i>>na;
			s.insert(i,na);
		}
		else if(option[0]=='d'){
			int i;
			cin>>i;
			s.remove(i);
		}
		else if(option[0]=='s'&&option[1]=='e'){
			char na[8];
			cin>>na;
			printf("%2d\n",s.search(na));
			cout<<"********************"<<endl;
		}
	}
	return 0;
}
