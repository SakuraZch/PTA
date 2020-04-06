
// 2020/3/8 //

#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} ElemType;  

typedef  struct
{ ElemType  *R; 
  int  length;
} SSTable;                      

void  Create(SSTable &T)
{ int i;
  T.R=new ElemType[MAXSIZE+1];
  cin>>T.length;
  for(i=1;i<=T.length;i++)
     cin>>T.R[i].key;   
}

int Search_Bin(SSTable T, KeyType k)
{
  int low = 0, mid = T.length / 2, high = T.length - 1;
  while(low <= high)
  {
    if(T.R[mid].key == k)
    {
      return mid;
    }
    else if(T.R[mid].key < k)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
    mid = (low + high) / 2;
  }

  return 0;
}

int main () 
{  SSTable T;  KeyType k;
   Create(T);
   cin>>k;
   int pos=Search_Bin(T,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   system("pause");
   return 0;
}

/* 请在这里填写答案 */
