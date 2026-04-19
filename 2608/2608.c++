#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;
int roma[129];
string roma2[1001];
int romtonum(string temp){
    int ret=roma[temp[0]];
    for(int i=1; i<temp.size(); i++){
        if(roma[temp[i-1]]<roma[temp[i]]) ret += roma[temp[i]]-roma[temp[i-1]]*2;
        else ret += roma[temp[i]];
    }
    return ret;}
string numtorom(int num){
    string temp;
    switch(num){
        case 0: return "";
        case 1: return "I";
        case 5: return "V";
        case 10: return "X";
        case 50: return "L";
        case 100: return "C";
        case 500: return "D";
        case 1000: return "M";
        case 4: return "IV";
        case 9: return "IX";
        case 40: return "XL";
        case 90: return "XC"; 
        case 400: return "CD";
        case 900: return "CM";
        default:
            if(num/10 == 0){
                if(num>5){ 
                    num -=5; temp += numtorom(5);
                }
                if(num%3==1)temp+= "I";
                if(num%3==2)temp+= "II";
                if(num%3==0)temp+= "III";
            }
            else if(num/100 == 0){
                if(num>50){ 
                    num -=50; temp += numtorom(50);
                }
                if((num/10)%3==1)temp+= "X";
                if((num/10)%3==2)temp+= "XX";
                if((num/10)%3==0)temp+= "XXX";
            }
            else if(num/1000 == 0){
                if(num>500){ 
                    num -=500; temp += numtorom(500);
                }
                if((num/100)%3==1)temp+= "C";
                if((num/100)%3==2)temp+= "CC";
                if((num/100)%3==0)temp+= "CCC"; 
            }
            else if(num/10000 == 0){
                for(int i=1; i<=(num/1000); i++)
                    temp+="M";
            }
    }
    return temp;
}
int main(){
    roma['I'] =1;
    roma['V'] =5;
    roma['X'] =10;
    roma['L'] =50;
    roma['C'] =100;
    roma['D'] =500;
    roma['M'] =1000;
    string str1,str2;
    cin>>str1>>str2;
    int num=romtonum(str1) + romtonum(str2);
    cout<<num<<endl;
    string result;
    int ten=10;
    while(num != 0){
        result.insert(0, numtorom(num%ten));
        num -= num%ten;
        ten *=10;
    }
    cout<<result<<endl;
    return 0;
}
