#include <iostream>
#include <string>
#include<ctime>
using namespace std;

class card{
    public:
        card(string in_name,string in_color,string in_rarity);
        friend ostream &operator<<(ostream &left, card &right);
    
    
    protected:
        string name;
        string color;
        string rarity;
        
};

class creature:public card{
    
    public:
        creature(string in_name,string in_color,string in_rarity,int in_attack,int in_defence,string in_kind);
        friend ostream &operator<<(ostream &left,creature &right);
    
    private:
        int attack;
        int defence;
        string kind;
        
    
    
};

class land:public card{
    public:
        land(string in_name,string in_color,string in_rarity,int in_mana,string in_description,bool in_tap);
        friend ostream &operator<<(ostream &left,land &right);
        void set_x(int in_mana);
    
    private:
        int mana;
        string description;
        bool tap;
};

int main(){
    srand(time(0));
    card c("wizard","blue","rare");
    cout<<c;
    creature fou("sphinx","black","common",10,20,"monster");
    cout<<fou;
    land la("earth","pink","uncommon",1,"des",false);
    cout<<la<<endl;
    la.set_x(15);
    cout<<la;
}

card::card(string in_name,string in_color,string in_rarity){
    name=in_name;
    color=in_color;
    rarity=in_rarity;
}

ostream &operator<<(ostream &left, card &right){
    left<<"("<<right.name<<","<<right.color<<","<<right.rarity<<")"<<endl;
    return left;
}


creature::creature(string in_name,string in_color,string in_rarity,int in_attack,int in_defence,string in_kind):
    card(in_name,in_color,in_rarity)
    {
        attack=in_attack;
        defence=in_defence;
        kind=in_kind;
    }

ostream &operator<<(ostream &left,creature &right){
    left<<"("<<right.name<<","<<right.color<<","<<right.rarity<<","<<right.attack<<","<<right.defence<<","<<right.kind<<")"<<endl;
    return left;
    
}

land::land(string in_name,string in_color,string in_rarity,int in_mana,string in_description,bool in_tap):
    card(in_name,in_color,in_rarity)
    {
        mana=in_mana;
        description=in_description;
        tap=in_tap;
    }
    
ostream &operator<<(ostream &left,land &right){
    left<<"("<<right.name<<","<<right.color<<","<<right.rarity<<","<<right.mana<<","<<right.description<<",";
    if (right.tap==true)
        left<<"tapped"<<")";
    else
        left<<"not tapped"<<")";
    return left;
}

void land::set_x(int in_mana){
    mana=in_mana;
}
