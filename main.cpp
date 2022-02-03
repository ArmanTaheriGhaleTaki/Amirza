//including header files
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstring>
#include<time.h>
#include<stdlib.h>

//global user array 
std::string name [30];
int password [30];
int mission [30];
int coin [30];
int extra [30];
int chance [30];
int UserAmount=0;

//global variable

int seasonamount;
std::string username;

//global word struct

struct word
{
    std::string chars;
    int main;
    int sub;
    std::string words[50];
};

//FUNCTION prototype menu
void MainMenu();
void InternalMenu();

//FUNCTION prototype login
void userAmount();
void userSet();
void showUser();
bool checkPassword(std::string user , int pass);
bool login();

//FUNCTION prototype signup
bool checkReapeat(std::string user);
void makeUser();


//FUNCTION prototype file
void reWrite();


//FUNCTION prototype Rank
void showRank();


//FUNCTION prototype InternalMenu
void WheelofLuck(std::string username);
void editProfile(std::string preuser);


// FUNCTION prototype Game
void seasonNum();
int showup(int level,std::string user,word *word);
int showLevels(std::string user,int missionOfSeason[]);
void showdown(int level,std::string user,word *word);
void challenge(word *word);

int main(){
    system("CLS");
    srand(time(0));
    userAmount();//reads the amount of users from user.txt
    seasonNum();//reads the amount of seasons from level.txt
    std::ifstream user ("levels.txt");//reads the whole words form level.txt and puts them in the array of stuct "word"
    int seasonAmount,lines=0 ;
    user >> seasonAmount;
    int missionOfSeason[seasonAmount];
    for(int w =0 ; w<seasonAmount ;w++){
        user>> missionOfSeason[w];
        lines+=missionOfSeason[w];
    }
    word missonLine[lines];
    for(int q=0;q<lines;q++){
        user>> missonLine[q].chars >>missonLine[q].main>>missonLine[q].sub;
        int counter=missonLine[q].main+missonLine[q].sub;
        for(int e=0;e<counter;e++){
            user>>missonLine[q].words[e];
        }
    }
    std::string Username;
    short int  choose=0;
    userSet();
    int randomnum=rand()%lines;
    main:
    MainMenu();
    choose=0;
    std::cin>>choose;

    switch (choose)
    {
    case 1 :
        makeUser();
        goto main;
        break;
    case 2 :
    if(login()==1)
    {            
        int userIndex =0;
            for( ; userIndex<UserAmount;userIndex++){
            if(username.compare(name[userIndex])==0)
            break;  
            }
        sub:
        system("CLS");
        InternalMenu();
        choose=0;
        std::cin >> choose;
        int missionlevel=0;
        switch (choose)
        {
        case 1:
        play:
        system("CLS");
            choose=showup(mission[userIndex],username,&missonLine[mission[userIndex]-1]);
            if(choose==1){
                showup(mission[userIndex],username,&missonLine[mission[userIndex]-1]);
                goto play;
            }
                else{
                goto sub;
            }
            
        case 2:
            missionlevel=showLevels( username, missionOfSeason);
            showdown(missionlevel,username,&missonLine[mission[userIndex]-1]);
            goto sub;
        break;
        case 3:
        system("CLS");
        WheelofLuck(username);
        goto sub;
            break;
        case 4:
        system("CLS");
        editProfile(username);
        goto sub;
            break;
        case 5:
        system("CLS");
        goto main;
            break;
        }
    }
    else{
    system("CLS");
    goto main;
    }
        break;
    case 3 :
        showRank();
        goto main;
        break;

    case 4 :
    challenge(&missonLine[randomnum]);
    goto main;
        break;
    case 5 :
    exit(1);
        break;
    }
}

//FUNCTION menu
void MainMenu(){//shows the main menu of the game
    std::cout<<"Welcome to this game:\n";
    std::cout<<"******* Main Menu *******\n";
    std::cout<<"1.Signup\n";
    std::cout<<"2.Login\n";
    std::cout<<"3.Rank\n";
    std::cout<<"4.challenge\n";
    std::cout<<"5.Exit\n\n";
    std::cout<<"Please enter your choice:\n";
}
void InternalMenu(){//shows the internal menu of the game
    std::cout<<"******* Internal Menu *******\n";
    std::cout<<"ussername : "<<username<<std::endl<<std::endl;
    std::cout<<"1.Continue game\n";
    std::cout<<"2.Choose level\n";
    std::cout<<"3.Wheel of Luck\n";
    std::cout<<"4.Edit profile\n";
    std::cout<<"5.Logout\n";
    std::cout<<"\n\n";
    std::cout<<"Please enter your choice:\n";
}
//FUNCTION login
void userAmount(){//reads the amount of users from user.txt
    std::ifstream user ("user.txt");
        int amount=0 ;
        user >> amount;
        UserAmount= amount;

}
void userSet(){//reads the users and their information from user.txt
    std::ifstream user ("user.txt");
    int temp ;
    user >> temp;
    int counter=0;
    while(user>>name [counter]>>password[counter]>>mission[counter]>>coin[counter]>>extra[counter]>>chance[counter]){
        counter++;
    }
}
void showUser(){//show all the users and their information
    for(int i=0;i<UserAmount;i++){
            std::cout<<"name:\t"<<name[i]<<"\tpassword:\t"<<password[i]<<"\tmission:\t"<<mission[i]<<"\tcoin:\t"<<coin[i]<<"\textra:\t"<<extra[i]<<"\tchance:\t"<<chance[i]<<std::endl;
    }
}
bool checkPassword(std::string user , int pass){ //check if the password is correct
    int i =0;
    for( ; i<UserAmount;i++)
    {
        if(user.compare(name[i])==0)
        break;
    }
    if(i==UserAmount){
        std::cout<< "there is no such a user name"<<std::endl;
        return 0;
    }
    if(pass==password[i]){
        return 1;
    }
    return 0;
}
bool login(){//checks if the user name and password are correct
    system("CLS");
    int pass,temp;
    std::cout<<"enter your username"<<std::endl;
    std::cin>> username;
    int i =0;
    while (checkReapeat(username)==0)
    {
        std::cout<<"there is no such a username please enter a valid one"<<std::endl;
        std::cin>>username;
    }
    for( ; i<UserAmount;i++){
    if(username.compare(name[i])==0)
    break;  
    }
    std::cout<<"enter your password"<<std::endl;
    std::cin>>pass;
    if(pass==password[i]){
        return 1;
    }
    int j =2;
    while (j>0)
    {
        switch (j)
        {
        case 2:
            std::cout<<"password is not correct you can try "<<j<<" more times"<<std::endl;
            break;
        
        case 1:
            std::cout<<"password is not correct you can try "<<j<<" more time"<<std::endl;
            break;
        }
        std::cin>>pass;
        j--;
        if(pass==password[i]){
        return 1;
    }
    }    
    return 0;
}

//FUNCTION signup
bool checkReapeat(std::string user){//checks if the username is already exist
        for(int i =0 ; i<UserAmount;i++)
    {
        if(user.compare(name[i])==0)
        return 1;
    }
    return 0;
}
void makeUser(){//maiking new user 
    system("CLS");
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

int tag =UserAmount;
UserAmount++;
name[tag]=user;
password [tag]=pass;
mission [tag]=1;
coin [tag]=0;
extra[tag]=0;
chance[tag]=0;
reWrite();
    system("CLS");
}
//FUNCTION file
void reWrite(){//rewrite the user.txt file
    std::ofstream user ("user.txt");
    user << UserAmount<<std::endl;
    for (int i = 0; i < UserAmount ; i++)
    {
        user<<name[i]<<"\t"<<password[i]<<"\t"<<mission[i]<<"\t"<<coin[i]<<"\t"<<extra[i]<<"\t"<<chance[i]<<"\t\n";
    }
}

//FUNCTION Rank
void showRank(){//show the sorted user by their mission number that they passed
    system("CLS");
    int amount =UserAmount;
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
        std::cout<<"Username:\t"<<name[indexSort[w]]<<"\t\t"<<"mission:\t"<<mission[indexSort[w]]<<std::endl;
    }
    std::cout<<std::endl;
    getch();
    system("CLS");
}

//FUNCTION InternalMenu
void WheelofLuck(std::string user){//rooling the wheelofluck
    int choice=0;
    int i =0;
            for( ; i<UserAmount;i++){
            if(user.compare(name[i])==0)
            break;  
    }
    if(chance[i]==0){
        std::cout<<user<<"  don't have any chance for wheel of luck ."<<std::endl;
    }
    else
    {  
        if(chance[i]==1){
        std::cout<<user<<" has "<<chance[i]<<" chance for wheel of luck ."<<std::endl;
        }
        else{
        std::cout<<user<<" has "<<chance[i]<<" chances for wheel of luck ."<<std::endl;
        }
        std::cout<<"wheel of luck has 6 kinds of awards"<<std::endl;
        std::cout<<"50  coins 30% chance"<<std::endl;
        std::cout<<"70  coins 20% chance"<<std::endl;
        std::cout<<"90  coins 20% chance"<<std::endl;
        std::cout<<"110 coins 15% chance"<<std::endl;
        std::cout<<"150 coins 10% chance"<<std::endl;
        std::cout<<"220 coins  5% chance"<<std::endl;
        std::cout<<"would you like to roll the wheel of luck?"<<std::endl;
        std::cout<<"1.yes"<<std::endl;
        std::cout<<"2.no"<<std::endl<<std::endl;
        std::cin>>choice;
    }
        if(choice==1){
        chance[i]--;
        int temp = (rand()%20)+1;
        switch (temp)
        {
        case 1 ... 6:
            std::cout<<user<<" won 50\n";
            coin[i]+=50;
            break;
        case 7 ... 10:
            coin[i]+=70;
            std::cout<<user<<" won 70\n";
            break;
        case 11 ... 14:
            coin[i]+=90;
            std::cout<<user<<" won 90\n";
            break;
        case 15 ... 17:
            coin[i]+=110;
            std::cout<<user<<" won 110\n";
            break;
        case 18 ... 19:
            coin[i]+=150;
            std::cout<<user<<" won 150\n";
            break;
        case 20 :
            coin[i]+=220;
            std::cout<<user<<" won 220\n";
            break;
        }
        getch();
        reWrite();

    }

}
void editProfile(std::string preuser){//making new user name and password for an account 
    int pass,temp ;
int i =0;
            for( ; i<UserAmount;i++){
            if(preuser.compare(name[i])==0)
            break;  
    }
    std::cout<<"ussername : "<<username<<std::endl<<std::endl;
    std::cout<<"enter your password"<<std::endl;
    std::cin>>pass;
while (pass!=password[i])
{
    std::cout<<"the password is not correct\n";
    std::cin>>pass;
}

    std::string user;
    std::cout<< "please enter new username"<<std::endl;
    std::cin>>user;

while(checkReapeat(user)==1)
{
    std::cout<< "this user name has been taken please enter another username"<<std::endl;
    std::cin>>user;
}
    std::cout<<"enter your new password"<<std::endl;
    std::cin>>pass;
    std::cout<<"confirm your new password"<<std::endl;
    std::cin>>temp;
    while (temp!=pass)
    {
        std::cout<<"please enter the same password"<<std::endl;
        std::cout<<"enter your  new password"<<std::endl;
        std::cin>>pass;
        std::cout<<"confirm your new password"<<std::endl;
        std::cin>>temp;
    }

name[i]=user;
password [i]=pass;
username=user;
reWrite();

}

// FUNCTION Game
void seasonNum(){//reads the amount of seasons  from the level.txt
    std::ifstream user ("levels.txt");
    int temp ;
    user >> temp;
    seasonamount=temp;
}
int showup(int level,std::string user,word *word){//shows the words that the user has to guess
    std::ifstream userFile ("levels.txt");
    int seasonAmount,lines=0 ;
    userFile >> seasonAmount;
    int missionOfSeason[seasonAmount];
    for(int w =0 ; w<seasonAmount ;w++){
        userFile>> missionOfSeason[w];
    }
    int season =1;
    int leveltemp = level;
    int r=0;
    for(;r<seasonAmount;r++){
        if(leveltemp<=missionOfSeason[r]){
            break;
        }
        else{
            leveltemp-=missionOfSeason[r];
            season++;
        }
    }
    int i =0;
            for( ; i<UserAmount;i++){
            if(user.compare(name[i])==0)
            break;  
            }
    std::cout<< "season : "<<season<<"\tlevel : "<<leveltemp<<"\tcoin : "<<coin[i]<<"\textra words: "<<extra[i]<<std::endl<<std::endl;
    std::cout<<"ussername : "<<username<<std::endl<<std::endl;
    std::cout<<"mian words : "<<word->main<<"\t\tsub words : "<<word->sub<<std::endl;

    for(int j=0;word->chars[j];j++)
    {
        std::cout<<word->chars[j]<<"  ";
    }
    std::cout<<std::endl<<std::endl;
    int counterWord=0;
    std::string answer;
    for(int j=0;j<22;j++)
    {
        if(word->words[j][0]!='\0'){
        counterWord++;
        }
    }
    bool solved[counterWord]{0};
        for(bool  flag=0; flag==0;){
        for(int j=0;j<counterWord;j++){
                if(solved[j]==false)
                {
                for(int q=word->words[j].length();q>0;q--)
                {
                    std::cout<<"- ";
                }
                std::cout<<std::endl;
                }
                else{
                    std::cout<<word->words[j]<<"\n";
                }
        }
            std::cout<<"enter the word you want to solve"<<std::endl;
            std::cin>> answer;
            for(int z=0 ; z<counterWord;z++)
            {
                if(answer.compare(word->words[z])==0)
                {
                    if(solved[z]==true)
                    {
                        std::cout<<"you already solved this word"<<std::endl;
                        getch();
                    }
                    else{
                    std::cout<<"you solved the word"<<std::endl;
                        if(word->main<(z+1)){
                            extra[i]++;
                            if(extra[i]>=6){
                                extra[i]-=6;
                                coin[i]+=50;
                                std::cout<<"you receive 50 coins because you give 6 extra words to the game"<<std::endl;
                                reWrite();

                            }
                            reWrite();
                        }
                    solved[z]=true;
                    getch();
                    }
                    
                }
            }
            for(int h=0 , counter=0;h<word->main;h++){
                if(solved[h]==true){
                    counter++;
                }
                if(counter==word->main){
                    flag=1;
                    break;
                }
            }
            system("CLS");
    std::cout<< "season : "<<season<<"\tlevel : "<<leveltemp<<"\tcoin : "<<coin[i]<<"\textra words: "<<extra[i]<<std::endl<<std::endl;
    std::cout<<"ussername : "<<username<<std::endl<<std::endl;
    std::cout<<"mian words : "<<word->main<<"\t\tsub words : "<<word->sub<<std::endl;
    for(int j=0;word->chars[j];j++)
    {
    std::cout<<word->chars[j]<<"  ";
    }
    std::cout<<std::endl<<std::endl;
    }
            system("CLS");
            std::cout<<"congratulations you passed the mission "<<std::endl;
            mission[i]++;
            std::cout<<"here is your reward 100 coins"<<std::endl<<std::endl;
            coin[i]+=100;
            leveltemp++;
    if(leveltemp>missionOfSeason[r]){
        std::cout<<"you passed the season too"<<std::endl;
        std::cout<<"your reward is a chance for wheel of luck"<<std::endl; 
        chance[i]++;
    }
    reWrite();
        std::cout<<"would you like to play next mission?"<<std::endl;
        std::cout<<"1.yes"<<std::endl;
        std::cout<<"2.no"<<std::endl<<std::endl;
        int choose =0;
        std::cin>>choose;
        return choose;
}
int showLevels(std::string user,int missionOfSeason[]){//reads the level that player wants to play
system("CLS");
    int result=0;
        int i =0;
            for( ; i<UserAmount;i++){
            if(username.compare(name[i])==0)
            break;  
    }
    std::cout<<"which mission would you like to play?"<<std::endl;
    for(int g=0,t=0;g<mission[i];g++){
            int season =1;
    int leveltemp = g+1;
    for(int r=0;r<seasonamount;r++){
        if(leveltemp<=missionOfSeason[r]){
            break;
        }
        else{
            leveltemp-=missionOfSeason[r];
            season++;
        }
    }

    std::cout<<g+1<<" .season "<<season<<"\tmission "<<leveltemp<<std::endl;
    }
    std::cout<<std::endl;
    std::cin>>result;
    system("CLS");
    for(;result<1||result>mission[i];){
        std::cout<<"you have to choose a mission that you have already passed"<<std::endl;
        std::cout<<"which mission would you like to play?"<<std::endl;
    for(int g=0,t=0;g<mission[i];g++){
            int season =1;
    int leveltemp = g+1;
    for(int r=0;r<seasonamount;r++){
        if(leveltemp<=missionOfSeason[r]){
            break;
        }
        else{
            leveltemp-=missionOfSeason[r];
            season++;
        }
    }

    std::cout<<g+1<<" .season "<<season<<"\tmission "<<leveltemp<<std::endl;
    }
    std::cout<<std::endl;
    std::cin>>result;
    system("CLS");
    }
return result;
}
void showdown(int level,std::string user,word *word){
        std::ifstream userFile ("levels.txt");
    int seasonAmount,lines=0 ;
    userFile >> seasonAmount;
    int missionOfSeason[seasonAmount];
    for(int w =0 ; w<seasonAmount ;w++){
        userFile>> missionOfSeason[w];
    }
    int season =1;
    int leveltemp = level;
    for(int r=0;r<seasonAmount;r++){
        if(leveltemp<=missionOfSeason[r]){
            break;
        }
        else{
            leveltemp-=missionOfSeason[r];
            season++;
        }
    }
    int i =0;
            for( ; i<UserAmount;i++){
            if(user.compare(name[i])==0)
            break;  
            }
    std::cout<< "season : "<<season<<"\tlevel : "<<leveltemp<<"\tcoin : "<<coin[i]<<"\textra words: "<<extra[i]<<std::endl<<std::endl;
    std::cout<<"ussername : "<<username<<std::endl<<std::endl;
    std::cout<<"mian words : "<<word->main<<"\t\tsub words : "<<word->sub<<std::endl;

    for(int j=0;word->chars[j];j++)
    {
        std::cout<<word->chars[j]<<"  ";
    }
    std::cout<<std::endl<<std::endl;
    int counterWord=0;
    std::string answer;
    for(int j=0;j<22;j++)
    {
        if(word->words[j][0]!='\0'){
        counterWord++;
        }
    }
    bool solved[counterWord]{0};
        for(bool  flag=0; flag==0;){
        for(int j=0;j<counterWord;j++){
                if(solved[j]==false)
                {
                for(int q=word->words[j].length();q>0;q--)
                {
                    std::cout<<"- ";
                }
                std::cout<<std::endl;
                }
                else{
                    std::cout<<word->words[j]<<"\n";
                }
        }
            std::cout<<"enter the word you want to solve"<<std::endl;
            std::cin>> answer;
            for(int z=0 ; z<counterWord;z++)
            {
                if(answer.compare(word->words[z])==0)
                {
                    if(solved[z]==true)
                    {
                        std::cout<<"you already solved this word"<<std::endl;
                        getch();
                    }
                    else{
                    std::cout<<"you solved the word"<<std::endl;
                    solved[z]=true;
                    getch();
                    }
                    
                }
            }
            for(int h=0 , counter=0;h<word->main;h++){
                if(solved[h]==true){
                    counter++;
                }
                if(counter==word->main){
                    flag=1;
                    break;
                }
            }
            system("CLS");
    std::cout<< "season : "<<season<<"\tlevel : "<<leveltemp<<"\tcoin : "<<coin[i]<<"\textra words: "<<extra[i]<<std::endl<<std::endl;
    std::cout<<"ussername : "<<username<<std::endl<<std::endl;
    std::cout<<"mian words : "<<word->main<<"\t\tsub words : "<<word->sub<<std::endl;
    for(int j=0;word->chars[j];j++)
    {
    std::cout<<word->chars[j]<<"  ";
    }
    std::cout<<std::endl<<std::endl;
    }
}
void challenge(word *word){
    system("cls");
    std::string user1;
    std::string user2;
    int temp=0;
    std::cout<<"enter the username of the first player"<<std::endl;
    std::cin>>user1;
    std::cout<<"enter the username of the second player"<<std::endl;
    std::cin>>user2;
    system("CLS");
    int user1score=0;
    int user2score=0;
    int usernum =-1;
    std::cout<<user1<<" : "<<user1score<<"\t"<<user2<<" : "<<user2score<<std::endl;
    std::cout<<"turn: "<<user1<<std::endl;
    for(int j=0;word->chars[j];j++)
    {
        std::cout<<word->chars[j]<<"  ";
    }
    std::cout<<std::endl<<std::endl;
    int counterWord=0;
    std::string answer;
    for(int j=0;j<22;j++)
    {
        if(word->words[j][0]!='\0'){
        counterWord++;
        }
    }
    bool solved[counterWord]{0};
        for(bool flag=0; flag==0;){
            if(temp){
            if(usernum==-1){
                std::cout<<"turn: "<<user1<<std::endl;
            }
            else{
                std::cout<<"turn: "<<user2<<std::endl;
            }
            }
        for(int j=0;j<counterWord;j++){
                if(solved[j]==false){
                for(int q=word->words[j].length();q>0;q--){
                    std::cout<<"- ";
                }
                std::cout<<std::endl;
                }
                else{
                    std::cout<<word->words[j]<<"\n";
                }
        }
            std::cout<<"enter * to give up"<<std::endl;
            std::cout<<"enter the word you want to solve"<<std::endl;
            std::cin>> answer;
            if(answer.compare("*")!=0){
            for(int z=0 ; z<counterWord;z++){
                if(answer.compare(word->words[z])==0){
                    if(solved[z]==true){
                        std::cout<<"this word is already solved "<<std::endl;
                        getch();
                    }
                    else{
                        if(usernum==-1){
                            user1score+=answer.size();
                    std::cout<<user1<<" solved the word"<<std::endl;
                    }
                        else{
                            user2score+=answer.size();
                    std::cout<<user2<<" solved the word"<<std::endl;
                    }
                    solved[z]=true;
                    getch();
                    }
                    
                }
            }
            for(int h=0 , counter=0;h<counterWord;h++){
                if(solved[h]==true){
                    counter++;
                }
                if(counter==counterWord){
                    flag=1;
                    break;
                }
            }
            system("CLS");
    std::cout<<user1<<" : "<<user1score<<"\t"<<user2<<" : "<<user2score<<std::endl;
    if(flag==0){
    for(int j=0;word->chars[j];j++)
    {
    std::cout<<word->chars[j]<<"  ";
    }
    std::cout<<std::endl<<std::endl;
    usernum*=-1;
    temp++;
    }
}
else{
    flag=1;
    system("CLS");
}
}
    if(user1score>user2score){
        std::cout<<user1<<" won the game"<<std::endl;
    }
    else if(user1score<user2score){
        std::cout<<user2<<" won the game"<<std::endl;
    }
    else{
        std::cout<<"the game is draw"<<std::endl;
    }
    getch();
    system("CLS");
}