#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define  error 0
#define   ok   1
#define   overflow  -1
#define STACK_INIT_SIZE  100
#define STACKINCREMENT 10
#define OPSETSIZE  7
char OPSET[OPSETSIZE]={'+','-','*','/','(',')','#'};
unsigned char Prior[7][7] = {     //  算符间的优先关系
     '>','>','<','<','<','>','>',
   '>','>','<','<','<','>','>',
   '>','>','>','>','<','>','>',
   '>','>','>','>','<','>','>', 
   '<','<','<','<','<','=',' ',
   '>','>','>','>',' ','>','>',
   '<','<','<','<','<',' ','='
};  
typedef int Status;
template <typename T>
struct SqStack
{
 T  *top;
 T  *base;
 int  stacksize;
};//顺序栈结构模板
template <typename T1,typename T2>
Status InitStack(T1 &S)
{
 S.base=(T2 *)malloc(STACK_INIT_SIZE*sizeof(T2));
 if(!S.base)  exit (overflow);
 S.top=S.base;
 S.stacksize=STACK_INIT_SIZE;
 return ok;
}//初始化栈函数模板
template <typename T1,typename T2>
Status Push(T1 &S,T2 e)
{
 if(S.top-S.base>=S.stacksize)
 {
  S.base=(T2 *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(T2));
     if(!S.base)  exit (overflow);
  S.top=S.base+S.stacksize;
  S.stacksize+=STACKINCREMENT;
 }
 *S.top++=e;
 return ok;
}//入栈函数模板
template <typename T1,typename T2>
Status Pop(T1 &S,T2 &e)
{
 if(S.top==S.base) return error;
 e=*--S.top;
 return ok;
}//出栈函数模板
template <typename T1,typename T2>
T2 GetTop(T1 S)
{
 if(S.top==S.base)
  return error;
 else
  return *(S.top-1);
}//获取栈顶元素模板
Status In(char Test,char* TestOp) {
   bool Find=false;
   for (int i=0; i< OPSETSIZE; i++) {
      if (Test == TestOp[i]) Find= true;
   }
   return Find;
}//判断是否为运算符
float Operate(float a,unsigned char theta, float b) {
   switch(theta) {
      case '+': return a+b;
      case '-': return a-b;
      case '*': return a*b;
      case '/': return a/b;
      default : return 0;
   } 
}//运算 
int ReturnOpOrd(char op,char* TestOp) {
   int i;
   for(i=0; i< OPSETSIZE; i++) {
      if (op == TestOp[i]) return i;
   }
   return 0;
}
char precede(char Aop, char Bop) {
   return Prior[ReturnOpOrd(Aop,OPSET)][ReturnOpOrd(Bop,OPSET)];
}//ReturnOpOrd和precede组合，判断运算符优先级
int EvaluateExpression(char* expre ) {  
   // 算术表达式求值的算符优先算法。
   // 设OPTR和OPND分别为运算符栈和运算数栈，OPSET为运算符集合。
   SqStack<char>  OPTR;    // 运算符栈，字符元素
   SqStack<float> OPND;    // 运算数栈，实数元素
   char TempData[20];
   float Data,a,b;
   char theta,*c,x,Dr[2];
   
   InitStack<SqStack<char>,char> (OPTR);
   Push (OPTR, '#');
   InitStack <SqStack<float>,float>(OPND);
   strcpy(TempData,"\0");//将TempData置为空
   c=expre;
   while (*c!= '#' || GetTop<SqStack<char>,char>(OPTR)!= '#')
   {
      if (!In(*c, OPSET)) 
   {
        Dr[0]=*c;
        Dr[1]='\0';//存放单个数
         strcat(TempData,Dr);//将单个数连到TempData中，形成字符串
         c++;
         if(In(*c,OPSET))//如果遇到运算符，则将字符串TempData转换成实数，入栈，
        {
            Data=(float)atof(TempData);///////////////////////////////////////////////////////////////////////////////***************************************** 
            Push(OPND, Data);
            strcpy(TempData,"\0");
        }
    } 
   else 
   {   // 不是运算符则进栈
         switch (precede(GetTop<SqStack<char>,char>(OPTR), *c)) { 
            case '<':   // 栈顶元素优先权低
                 Push(OPTR, *c);  
                 c++;
                 break;
            case '=':   // 脱括号并接收下一字符
                 Pop(OPTR, x);   
                 c++;
                 break;
            case '>':   // 退栈并将运算结果入栈
                 Pop(OPTR, theta);
                 Pop(OPND, b);  
                 Pop(OPND, a);                      
                 Push(OPND, Operate(a, theta, b)); 
                 break;
         } // switch
      }
   } // while
   return GetTop<SqStack<float>,float>(OPND);
} // EvaluateExpression
int  main()
{
	char c[1000];
	while(cin>>c){
      printf("%d\n",EvaluateExpression(c));
    }  
 return 0;
}
