#include<iostream>
#include<string>
using namespace std;

int validateip(string ip){
    //separating the ip into four parts and converting to intergers
    string p1,p2,p3,p4;
    //special case "0.0.0.0">> because it starts with the 0
    if(ip=="0.0.0.0"){return 1;}
    //minimum length of ip :7 --> 0.0.0.0
    //maximun length of ip :15 --->234.222.222.222
    if(ip.length()<7 ||ip.length()>15 ){
        return 0;
    }
    //count_dot for counting the periods
    int count_dot =0;
    //p variable is used for changing the string variables
    int p=1;
    for(int i=0;i<ip.length();i++){
        //if any character is not valid such as a,b,c,/,' etc
        if(ip[i]!='.'&& ip[i]!='0'&&ip[i]!='1'&&ip[i]!='2'&&ip[i]!='3'&&ip[i]!='4'&&ip[i]!='5'&&ip[i]!='6'&&ip[i]!='7'&&ip[i]!='8'&&ip[i]!='9')
        {return 0;}
        //case "...." or "35..54.4"
        if(ip[i]=='.'){
            p++;
            count_dot++;
            if(ip[i+1]=='.'){
                return 0;
            }
        }
        //appending in the string
        if(p==1 && ip[i]!='.'){
            p1=p1+(ip[i]);
        }
        else if(p==2 && ip[i]!='.'){
            p2=p2+(ip[i]);
        }
        else if(p==3 && ip[i]!='.'){
            p3=p3+(ip[i]);
        }
        else if(p==4 && ip[i]!='.'){
            p4=p4+(ip[i]);
        }
        else{continue;}
        
    }

    //!!!!!!!!!!!!!
    //deals with cases such as 23.004.23.001
   if(p1[0]=='0' && p1.length()>1){return 0;}
   if(p2[0]=='0' && p2.length()>1){return 0;}
   if(p3[0]=='0' && p3.length()>1){return 0;}
   if(p4[0]=='0' && p4.length()>1){return 0;}

   if(count_dot!=3){return 0;}
   //converting string to interger;
    int intp1=stoi(p1);
    int intp2=stoi(p2);
    int intp3=stoi(p3);
    int intp4=stoi(p4);
    cout<<intp1<<endl;
    cout<<intp2<<endl;
    cout<<intp3<<endl;
    cout<<intp4<<endl;

    if( (intp1 >=1 && intp1 <=255) &&(intp2 >=0 && intp2 <=255)&&(intp3 >=0 && intp3 <=255)&&(intp4 >=0 && intp4 <=255)){
        return 1;
    }
    return 0;
}



int main(){
        int testcases;
        cout<<"enter the tests:";
        cin>>testcases;
        while(testcases--)
        {string ip;
        cout<<"Enter the ip:"<<endl;
        cin>>ip;
        int ans=0;
        ans = validateip(ip);
        cout<<"the answer is as ::"<<ans<<endl;
        }
    
}
