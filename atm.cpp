

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main();

class user{
    private:
    int id;
    string name;
    int pass;
    int bal;

    public:

  user(int x,string n ,int p){
    id=x;
    bal=0;
    name=n;
    pass=p;
    cout<<endl<<"We sincerely thank you for opening your account with us"<<endl;
  }

    void deposit(int**a){
     int p, m;
          int c=0;
     while(c<3){
    cout<<"Enter the Password:";
     cin>>p;
     if(p!=pass){
        cout<<"Wrong password!!"<<endl;
        c++;
     }
     else {
      break;
     }
     if(c==3){
      return;
     }
     }
     cout<<"Enter the Amount:";
     cin>>m;
      bal+=m;
      **a+=m;
      cout<<"Name:"<<name<<endl;
      cout<<"ID:"<<id<<endl;
     cout<<"Amount Deposited"<<endl;
     return;
   
}

void check(){
    int p;
       int c=0;
     while(c<3){
    cout<<"Enter the Password:";
     cin>>p;
     if(p!=pass){
        cout<<"Wrong password!!"<<endl;
        c++;
     }
     else {
      break;
     }
     if(c==3){
      return;
     }
     }
      cout<<"Name:"<<name<<endl;
      cout<<"ID:"<<id<<endl;
        cout<<"Your Balance:"<<bal<<endl;  
    return;
}

void withdraw(int**a){
        int p, m;
               int c=0;
     while(c<3){
    cout<<"Enter the Password:";
     cin>>p;
     if(p!=pass){
        cout<<"Wrong password!!"<<endl;
        c++;
     }
     else {
      break;
     }
     if(c==3){
      return;
     }
     }
     cout<<"Enter the Amount:";
     cin>>m;
     if(m>bal){
      cout<<"No Enough Balance";
      return;
     }
     bal-=m;
     **a-=m;
     cout<<"Name:"<<name<<endl;
      cout<<"ID:"<<id<<endl;
     cout<<"Please collect cash"<<endl;
     return;     
}

void changepass(){
    int p,np;
      cout<<"Enter Your current Password:";
     cin>>p;
       int c=0;
     while(c<3){
    cout<<"Enter the Password:";
     cin>>p;
     if(p!=pass){
        cout<<"Wrong password!!"<<endl;
        c++;
     }
     else {
      break;
     }
     if(c==3){
      return;
     }
     }
    
         cout<<"Enter New Password:";
     cin>>np; 
     if(np==p){
        cout<<endl<<"Your current password is same as new password!! \n Please chose another password choose another"<<endl;
        return;
     }
     else{
        pass=np;
      cout<<"Password updated succesfully"<<endl;
        return;
     }
     
}
    void deleteacc(int**a){
        *a-=bal;
       bal=0; 
       id=0;
       name='\0';
       pass=0;
    }
};

void adduser(vector<user>& v ,vector<int>& c){
  int id;
  string name;
  int pass;
   cout<<"Enter New id:";
   cin>>id;
   cout<<"Enter Name:";
   cin>>name;
   cout<<"Enter Password:";
   cin>>pass;
   c.push_back(id);
   v.push_back(user( id,name,pass));
   return;
}

int index(int x,vector<int>&c){
    int i;
for(i=0;i<c.size();i++){
    if(x==c[i]){
return i;
    }
}
cout<<"ID not found"<<endl;
return -1;
}

void deposit(vector<user>& v, vector<int>&c,int* a){
int id ,x;
cout<<endl<<"Enter Id:";
cin>>id;
 x= index(id,c);
 if(x<0){
    return;
 }
v[x].deposit(&a);
return;
}

void withdraw(vector<user>& v, vector<int>&c,int* a){
int id ,x;
cout<<endl<<"Enter Id:";
cin>>id;
 x= index(id,c);
 if(x<0){
    return;
 }
v[x].withdraw(&a);
return;
}

void check(vector<user>& v, vector<int>&c){
int id ,x;
cout<<endl<<"Enter Id:";
cin>>id;
 x= index(id,c);
 if(x<0){
    return;
 }
v[x].check();
return;
}

void changepass(vector<user>& v, vector<int>&c){
int id ,x;
cout<<endl<<"Enter Id:";
cin>>id;
 x= index(id,c);
 if(x<0){
    return;
 }
v[x].changepass();
return;
}

void deleteacc(vector<user>& v, vector<int>&c,int* a){
int id ,x;
cout<<endl<<"Enter Id:";
cin>>id;
 x= index(id,c);
 if(x<0){
    return;
 }
v[x].deleteacc(&a);
c[x]=0;
return;
}

void atmdep(int** a){
     int p, m,pass=141812;
            int c=0;
     while(c<3){
    cout<<"Enter the Password:";
     cin>>p;
     if(p!=pass){
        cout<<"Wrong password!!"<<endl;
        c++;
     }
     else {
      break;
     }
     if(c==3){
      return;
     }
     }
     cout<<endl<<"Enter the Amount:";
     cin>>m;
      **a+=m;
     cout<<endl<<"Amount Deposited"<<endl;
     return;     
}

void atmdraw(int** a){
     int p, m,pass=141812;
               int c=0;
     while(c<3){
    cout<<"Enter the Password:";
     cin>>p;
     if(p!=pass){
        cout<<"Wrong password!!"<<endl;
        c++;
     }
     else {
      break;
     }
     if(c==3){
      return;
     }
     } 
     cout<<endl<<"Enter the Amount:";
     cin>>m;
       if(m>**a){
      cout<<"No Enough Balance";
      return ;
     }
     cout<<"Enter the Password:";
     cin>>p;
      **a-=m;
     cout<<endl<<"Take the Cash"<<endl;
     return;  
   
}
void atmbal(int ** a){
 cout<<endl<<endl<<"The remaining ATM balance is:"<<**a<<endl;
}

void atm(int *a){

int s;
while(1){
cout<<endl<<"Select the option:"<<endl<<"1.Check Balance\n2.Deposit\n3.Withdraw\n4.EXIT\n";
 cout <<"Enter your option:";
    cin>>s;
   
        switch(s){
        case 1: atmbal(&a);
        break;
        case 2 :atmdep(&a) ;
        break;
        case 3 : atmdraw(&a);
        break;
        case 4: return;
    }
}
    return;
}

int main(){
    int a=100000;//default atm balance is 100000
    int s;
vector<user>u;
vector<int>c;
cout<<"Welcome to SBI"<<endl;
    while(1){
    cout<<"+================================================================================================================================================+";
    cout<<endl<<"Select any one option:"<<endl<<"1.New user\n2.Deposit\n3.Withdraw\n4.Check Balance\n5.Change Password\n6.Delete account\n7.EXIT\nX.IF ADMIN ENTER SECRET CODE\n";
    cout<<"+================================================================================================================================================+";
    cout <<endl<<endl<<"Enter your option:";
    cin>>s;
    cout<<"+================================================================================================================================================+";
    switch(s){
        case 1:adduser(u,c);
        break;
        case 2 : deposit(u,c,&a);
        break;
        case 3 : withdraw(u,c,&a);
        break;
        case 4: check(u,c);
        break;
        case 5: changepass(u,c);
        break;
        case 6: deleteacc(u,c,&a);
        break;
        case 1418: atm(&a);
        break;    
        case 7 : return(0);
        default: cout<<"Wrong option!!"<<endl;
    }
    }
}
