# include <iostream>
using namespace std;
class seqlist{
	protected:
		int maxsize;
		int last;
		int *data;
	public:
		seqlist(int sz){
			if(sz>0){
				maxsize=sz;
				last=-1;
				data=new int[maxsize];
			}
		}
		void input(){
			while(1){
				cin>>last;
				last--;
				if(last<=maxsize-1)
				break;
			}
			for(int i=0;i<=last;i++){
				cin>>data[i];
			}
		}
		void output(){
			for(int i=0;i<=last;i++)
			cout<<data[i]<<" ";
			cout<<endl;
		}
		bool search(int x){
			for(int i=0;i<last+1;i++){
				if(data[i]==x)
				return true;
			}
			return false;
		}
		int length(){
			return last+1;
		}
		bool getdata(int i,int &x){
			if(i>0&&i<=last+1){
				x=data[i-1];
				return true;
			}
			else return false; 
		}

		void insert(int i,int x){
			data[i]=x;
			last++;
		}
};
void uni(seqlist la,seqlist lb){
	int lena,lenb;
	int temp;
    lena=la.length();
	lenb=lb.length();
	for(int i=1;i<=lenb;i++){
		lb.getdata(i,temp);
		if(!la.search(temp))
			la.insert(lena,temp);
		la.output();
	}
}
void mergelist(seqlist la,seqlist lb,seqlist &lc){
	int lena,lenb;
	int ai,bj,i=1,j=1,k=0;
	lena=la.length();
	lenb=lb.length();
	while((i<=lena)&&(j<=lenb)){
		la.getdata(i,ai);
		lb.getdata(j,bj);
		if(ai<bj){
			lc.insert(k++,ai);
			i++;
		}
		else{
			lc.insert(k++,bj);
			j++;
		}
	}
	while(i<=lena){
		la.getdata(i++,ai);
		lc.insert(k++,ai);
	}
	while(j<=lenb){
		lb.getdata(j++,bj);
	    lc.insert(k++,bj);
	}
}
int main(){
	int sz1,sz2;
    seqlist la(200),lb(200),lc(400);
    la.input();
    lb.input();
    mergelist(la,lb,lc);
    lc.output();
	return 0;
}
