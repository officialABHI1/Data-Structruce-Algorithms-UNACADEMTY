#include<bits/stdc++.h>
using namespace std;

void mergeSortedList(queue<int>&a, queue<int>&b, queue<int>& ans){
  
  //Base conditions
  
  if(a.empty() && b.empty())
    return;
    
  if(!a.empty() && !b.empty()){
    if(a.front()<b.front() ){
      ans.push(a.front());
      a.pop();
    }
    else
    {
      ans.push(b.front());
      b.pop();
    }
    mergeSortedList(a,b,ans);
  }
  else if(!a.empty() && b.empty()){
      ans.push(a.front());
      a.pop();
      mergeSortedList(a,b,ans);
  }
  else if(a.empty() && !b.empty()){
      ans.push(b.front());
      b.pop();
      mergeSortedList(a,b,ans);
  }
}

int main()
{
  int n,m,x;
  cin>>n>>m;
  
  queue<int>a,b;
  
  for(int i=0;i<n;i++){
    cin>>x;
    a.push(x);
  }
  
  for(int i=0;i<m;i++){
    cin>>x;
    b.push(x);
  }
  
  queue<int> ans;
  
  mergeSortedList(a,b,ans);
  
  while(!ans.empty()){
    cout<<ans.front()<<" ";
    ans.pop();
  }
  cout<<endl;
  
  return 0;
  
}
