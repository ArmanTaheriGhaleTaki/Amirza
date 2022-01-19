
#include<iostream>
#include "menu.h"


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

