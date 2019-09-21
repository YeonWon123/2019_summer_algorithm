// AlphaCode problem
// ECNA ACM Regional 2004
// t feil

#include <iostream>
using namespace std;

void printit(char c){
   cout<<c<<endl;
}

int main(){
  char c,c1,c2;
  int last, last1, last2;

  cin>>c1;
  while(c1!='0'){
    last=1; 
    if(cin.peek() != '\n'){
      cin>>c2; 
      last2=1;
      if((c1=='1' || (c1=='2' && c2<'7')) && c2!='0') last=last1=2;
      else last=last1=1;
      while(cin.peek() != '\n'){
        cin>>c;
        if(c!='0') last=last1; else last=0;
        if(c2=='1' || (c2=='2' && c<'7'))
          last += last2;
        c2=c; last2=last1; last1=last;
      }
    }
    cout<<last<<endl;
    cin>>c1;
  }
return 0;
}