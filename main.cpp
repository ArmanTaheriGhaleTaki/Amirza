#include<iostream>
#include<conio.h>
#include <fstream>
#include <string>
#include <cstring>

//global var 
std::string name [30];
int password [30];
int mission [30];
int coin [30];
int extra[30];
int chance[30];
int UserAmount=0;


//FUNTION prototype menue
void MainMenu();
void InternalMenu();
void SigninMenu_USERNAME();
void SigninMenu_PASSWORD();
void MissonComplete(int missionNum);
void SeasonComplete(int seasonNum);
void Achive_wheeloffortune();
void NotAchive_wheeloffortune();

//FUNCTION prototype login
int  userAmount();
void userSet();
void showUser();
bool checkPassword(std::string user , int pass);

//FUNCTION prototype signup
bool checkReapeat(std::string user);
void makeUser();

//FUNCTION prototype file


//FUNCTION Rank
void showRank();





int main(){
    short int  choose=0;
    // MainMenu();
    // std::cin>>choose;
    // switch (choose)
    // {
    // case 1 :
    //     makeUser();
    //     break;
    // case 2 :
    
    //     break;
    // case 3 :

    //     break;
    // case 4 :

    //     break;
    // case 5 :

    //     break;
    // }
    userSet();
    showRank();
    
}



//FUNCTION menue
void MainMenu(){
    std::cout<<"Welcome to this game:\n";
    std::cout<<"******* Main Menu *******\n";
    std::cout<<"1.Signup\n";
    std::cout<<"2.Login\n";
    std::cout<<"3.Rank\n";
    std::cout<<"4.Challenge\n";
    std::cout<<"5.Exit\n\n";
    std::cout<<"Please enter your choice:\n";
}
void InternalMenu(){
    std::cout<<"******* Internal Menu *******\n";
    std::cout<<"1.Continue game\n";
    std::cout<<"2.Choose level\n";
    std::cout<<"3.Wheel of Luck\n";
    std::cout<<"4.Edit profile\n";
    std::cout<<"5.Logout\n";
    std::cout<<"\n\n";
    std::cout<<"Please enter your choice:\n";
}
void SigninMenu_USERNAME(){
    std::cout<<"Enter your username:\n";
}
void SigninMenu_PASSWORD(){
    std::cout<<"Enter your password:\n";
}
void MissonComplete(int missionNum){
    std::cout<<"congratulations you have finished mission "<<missionNum<<std::endl;

}
void SeasonComplete(int seasonNum){
    std::cout<<"congratulations you have finished season "<<seasonNum<<std::endl;

}
void Achive_wheeloffortune(){
    std::cout<<"you achive a chance for wheel of fortune";

}
void NotAchive_wheeloffortune(){
    std::cout<<"you don't achive any chance for wheel of fortune";
}

//FUNCTION login
int userAmount(){
    std::ifstream user ("user.txt");
        int amount=0 ;
        user >> amount;
        return amount;

}
void userSet(){
    std::ifstream user ("user.txt");
    int temp ;
    user >> temp;
    int counter=0;
    while(user>>name [counter]>>password[counter]>>mission[counter]>>coin[counter]>>extra[counter]>>chance[counter]){
        counter++;
    }
}
void showUser(){
    for(int i=0;i<userAmount();i++){
            std::cout<<"name:\t"<<name[i]<<"\tpassword:\t"<<password[i]<<"\tmission:\t"<<mission[i]<<"\tcoin:\t"<<coin[i]<<"\textra:\t"<<extra[i]<<"\tchance:\t"<<chance[i]<<std::endl;
            // std::cout<<name[i]<<password[i]<<mission[i]<<coin[i]<<extra[i]<<chance[i]<<std::endl;

    }
}
bool checkPassword(std::string user , int pass)
{   int i =0;
    for( ; i<userAmount();i++)
    {
        if(user.compare(name[i])==0)
        break;
    }
    if(i==userAmount()){
        std::cout<< "there is no such a user name"<<std::endl;
        return 0;
    }
    if(pass==password[i]){
        return 1;
    }
    return 0;
}
bool login(){
    std::string user;
    int pass,temp;
    std::cout<<"enter your username";
    std::cin>> user;
    while (checkReapeat(user)==0)
    {
        std::cout<<"there is no such a user name please enter a valid one"<<std::endl;
        std::cin>>user;
    }
    std::cout<<"enter your password"<<std::endl;
    std::cin>>pass;
    std::cout<<"repeat your password"<<std::endl;
    std::cin>>temp;
}
//FUNCTION signup
bool checkReapeat(std::string user){
        for(int i =0 ; i<userAmount();i++)
    {
        if(user.compare(name[i])==0)
        return 1;
    }
    return 0;
}
void makeUser(){
    int pass,temp ;
    std::string user;
    std::cout<< "please enter username"<<std::endl;
    std::cin>>user;

while(checkReapeat(user)==1)
{
    std::cout<< "this user name has been taken please enter another username"<<std::endl;
    std::cin>>user;
}
    std::cout<<"enter your password"<<std::endl;
    std::cin>>pass;
    std::cout<<"confirm your password"<<std::endl;
    std::cin>>temp;
    while (temp!=pass)
    {
        std::cout<<"please enter the same pass word"<<std::endl;
        std::cout<<"enter your password"<<std::endl;
        std::cin>>pass;
        std::cout<<"confirm your password"<<std::endl;
        std::cin>>temp;
    }

int tag =userAmount();
name[tag]=user;
password [tag]=pass;
mission [tag]=1;
coin [tag]=0;
extra[tag]=0;
chance[tag]=0;

}
//FUNCTION file
void reWrite(){

}


//FUNCTION Rank
void showRank(){
    int amount =userAmount();
    int  indexSort[amount];
    for(int i =0 ; i<amount;i++){
        indexSort[i]=i;
    }
    for (int i = 0; i <amount ; i++)
    {
        for (int j = i+1; j <amount ; j++)
        {
            if(mission[indexSort[i]]<mission[indexSort[j]]){
                int temp = indexSort[i];
                indexSort[i]=indexSort[j];
                indexSort[j]=temp;
            }
        }
    }
    for (int w = 0; w < amount; w++)
    {
        std::cout<<"Username:\t"<<name[indexSort[w]]<<"\t\t"<<"misson:\t"<<mission[indexSort[w]]<<std::endl;
    }
    std::cout<<std::endl;
}


