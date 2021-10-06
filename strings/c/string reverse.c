string reverseWord(string str){
    
  //Your code here
  for(int i=0;i<str.size()/2;i++){
        char temp;
        temp=str[i];
        str[i] = str[str.size()-i-1];
        str[str.size()-i-1]=temp;
  }
  
  return str;
}