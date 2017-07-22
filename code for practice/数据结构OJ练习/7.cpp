# include <iostream>
# include <cmath>
using namespace std;

struct term{
	int coef;
	int exp;
	term *link;
	term(int c,int e, term* next=NULL){
		coef=c;
		exp=e;
		link=next;
	}
	term* insert_af(int c,int e){
		link= new term(c,e,link);
		return link;
	}
	friend ostream& operator << (ostream&,const term&);
}; 

class pol{
	private:
	    term *first;
	    friend pol operator + (pol&,pol&);
	    friend istream& operator >>(istream&, pol&);
	    friend ostream& operator <<(ostream&, pol&);
	public:
		pol(){
			first = new term(0,-1);
		}
	    term * gethead()const{
	    	return first;
		}
};

pol operator + (pol& a,pol& b){
	term *pa,*pb,*pc,*p;
	int temp;
	pol c;
	pc= c.gethead();
	pa = a.gethead()->link;
	pb = b.gethead()->link;
	while(pa != NULL&&pb != NULL){
		if(pa->exp == pb->exp){
			temp=pa->coef-pb->coef;
			if(fabs(temp)>0)
			pc= pc->insert_af(temp,pa->exp);
			pa=pa->link;
			pb=pb->link; 
		}
		else if(pa->exp<pb->exp){
			pc = pc->insert_af(pb->coef,pb->exp);
			pb = pb->link;
		}
		else{
			pc = pc->insert_af(pa->coef,pa->exp);
			pa = pa->link;
		}
		if(pa!=NULL) p=pa;
		else p=pb;
		while(p!=NULL){
			pc = pc->insert_af(p->coef,p->exp);
			p=p->link;
		}
		return c;
	}
}
ostream& operator << (ostream& out,const term& x){
	if(x.coef == 0) return out;
	out<<x.coef<<" ";
	switch(x.exp){
		case 0: break;
		default:out<<x.exp;break;
	}
	return out;
}
istream& operator >>(istream& in, pol& x){
	term* rear =x.gethead();
	int c,e;
	while(1){
		in>>c>>e;
		if(e<0) break;
		rear = rear->insert_af(c,e);
	}
	return in;
}
ostream& operator <<(ostream& out, pol& x){
	term *cur=x.gethead()->link;
	while(cur!=NULL){
		out<<*cur<<" ";
		cur = cur->link;
		return out;
	}
}
int main(){
	pol a,b;
	while(cin>>a>>b){
		pol c=a+b;
		cout<<c<<endl;
	}
	return 0;
}
