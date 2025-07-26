#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> //random choice
using namespace std;

#define N 10

int main(){
    
    string words[N]={"bond","neo","borobir","saruman","gandalf","sansha","stark","spiderman","frodo","morpheus"};
    srand(time(0)); //fytra tyxaiwn gia na epilegetai allh lexh kathe fora
    string hidden =words[rand()%10];  //random choice from words index 1-10
    cout<<hidden<<endl;
    
    string game(hidden.length(),'-'); //arxikopoihsh me - to game kai length iso me thn hidden
    cout<<game<<endl;
    
    string bad_guesses;
    string right_guesses;
    
    int MAX=5;
    int wrong_guesses=0;
    //algorithmos
    char letter;
    while (true)
    {
        cout<<game<<endl;
        cout<<"Choose letter: ";
        cin>>letter;
        
        if (bad_guesses.find(letter)!=bad_guesses.npos) //if letter already exist
        {
            cout<<"your letter already exists give another ";
            continue;
        }
        if (right_guesses.find(letter)!=right_guesses.npos) //if letter already exist
        {
            cout<<"your letter already exists give another ";
            continue;
        } 
        if (hidden.find(letter)!=hidden.npos)//yparxei to gramma
        {
            int pos;
            cout<<"letter exists ";
            pos=hidden.find(letter); //save the position of the letter in pos variable
            while (pos<hidden.length()) //means it has find something
            {
                game[pos]=hidden[pos]; //save in game position the letter in hidden position      
                pos=hidden.find(letter,pos+1);//start from the next position that the letter exists
            }
            
            right_guesses.push_back(letter);
            if (game.find("-")==hidden.npos) //if it doesnt find - in the programm
            {
                cout<<"You win congrats"<<endl;
                break;
            }
            
            
            
        }
        else
        {
            cout<<"the letter doesnt exists"<<endl;
            wrong_guesses++;
            cout<<"you still have: "<<MAX-wrong_guesses<<" efforts left"<<endl;
            bad_guesses.push_back(letter);
            if (wrong_guesses==MAX){
                cout<<"Sorry you lost";
                break;
            }
            
            
        }
        
        
        
        
    }
}



