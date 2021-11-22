class Solution {
public:
    string addStrings(string num1, string num2) {
        string s="";int i = num1.size()-1,j = num2.size()-1;
        int carry = 0;
        
        while(i >=0 && j >=0){
            int a = (num1[i]-'0')+(num2[j]-'0') + carry;
            carry = 0;
            if(a > 9){
                carry = 1;
            }
            s = to_string(a%10) + s;
            i--;
            j--;
        }
        
        while(i >= 0){
            int a = (num1[i]-'0')+carry;
            carry = 0;
            if(a > 9){
                carry = 1;
            }
            s= to_string(a%10) + s;
            i--;  
        }
        
        while(j >=0){
            int a = (num2[j]-'0')+carry;
            carry = 0;
            if(a > 9){
                carry = 1;
            }
            s= to_string(a%10) + s;
            j--;
        }
        if(i == -1 && j == -1 && carry!=0){
            
            s = to_string(carry) + s;
            
        }
        return s;
    }
};