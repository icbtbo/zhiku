# include <iostream>
# include <stdlib.h>
# include <string.h>
# include <cstring>
# include <string>
using namespace std;
# define list_init_size 100
# define listincrement 10

typedef struct{
	string* elem;
	int length;
	int listsize;
}Seqlist;

int locateelem(Seqlist L,string e);

bool init_list(Seqlist &L){
	L.elem = new string[list_init_size*sizeof(string)];
	if (!L.elem)
	return false;
	L.length = 0;
	L.listsize = list_init_size;
	return true;
}

bool listinsert(Seqlist & L,int i,string e){
	string *p;
	if (i<1||i>L.length+1)
	    return false;
	if(locateelem(L,e)==0){
	if(L.length>=L.listsize){
		string *newbase = new string[(L.listsize+listincrement)*sizeof(string)];//
		if(!newbase)
		return false;
		string *srcpty = L.elem;
		string *destpty =newbase;
		int n=L.length;
		while(n--) *destpty++=*srcpty++;
		L.listsize+=listincrement;
	}
	string *q = &(L.elem[i-1]);
	for (p = &(L.elem[L.length-1]); p>=q;p--)
	    *(p+1)=*p;
	    *q = e; 
	    L.length++;
	    return true;
	}
}

bool Delete(Seqlist &L, string e){
	string * p;
	if(locateelem(L,e)!=0){
		int i=locateelem(L,e);
	string *q = &(L.elem[i-1]);
	for ( q;q < &(L.elem[L.length-1]);q++)
	    *(q)=*(q+1);
	    L.length--;
	    return true;
	}
}

int locateelem(Seqlist L,string e){
	int i;
	string *p;
	i = 1;
	p = L.elem;
	while (i <= L.length && strcmp(p[i-1].c_str(),e.c_str())!=0)
	    ++i;
	if (i <= L.length)
	    return i;
	else
	    return 0;
}

void showall(Seqlist L){
	if(L.length==0)
	cout<<endl;
	else{
	for(int i=0;i<L.length-1;i++)
	cout<<L.elem[i]<<" ";
	cout<<L.elem[L.length-1]<<endl;
    }
}
int main(){
	Seqlist L;
	int a;
	string str,temp;
	init_list(L);
	while(cin>>str){
		if(str == "insert"){
		cin>>a>>temp;
		listinsert(L,a,temp);
		}
		else if(str=="search"){
		cin>>temp;
		cout<<locateelem(L,temp)<<endl;
	    }
		else if(str=="show"){
		showall(L);
	    }
		else if(str=="delete"){
		cin>>temp;
		Delete(L,temp);
	    }
    }
    return 0;
}

