#include <iostream>
#include <cstdlib>
#include <ctime> //these 2 libraries for random numbers
using namespace std;

class demigorgon{
    public:
        demigorgon();
        int attack();
        
    
    private:
        int height;
        int weight;
        int health;
    
};

class demidog{
    public:
        demidog();
        int attack();
    
    private:
        int health;
};

class hive{
    public:
        hive(bool in_demigorgon);
        int attack();
    
    private:
        demigorgon *demi_ptr; //δυναμικη δεσμευση το πολυ ενας ντεμιγκοργκον
        demidog *array_demidogs;    // το ιδιο για ντεμιντογκσ σε αρραυ
        int n_demidogs; // array demidogs dimension
};


int main(){
    hive h(true);
    int damage;
    damage=h.attack();
    cout<<"total damage: "<<damage;
    
    return 0;
}

demigorgon::demigorgon(){
    height=5;
    weight=500;
    health=10000;
}


int demigorgon::attack(){
    
    srand(time(0));
    return 300+rand()%(200-0+1); //return a random number from 300-500
}

demidog::demidog(){
    health=100;
}

int demidog::attack(){
    
    return 10+rand()%(20-0+1);//return random between 10-30
}

hive::hive(bool in_demigorgon){
    if (in_demigorgon)
    
        demi_ptr=new demigorgon;
        if (!demi_ptr)
            cout<<"Error allocating memory";    
    
    else
        demi_ptr=NULL;
        
    n_demidogs=10+rand()%(41); //10-50 demidogs
        
    array_demidogs=new demidog [n_demidogs]; //initialize demidogs
    if (!array_demidogs)
        cout<<"memory error allocation";
}

int hive::attack(){
    int damage;
    int sum;
    if (demi_ptr!=NULL)
    {
        damage=demi_ptr->attack(); //(*demi_ptr).attack() its the same
        sum+=damage;
        cout<<"Demigorgon attacks"<<damage<<endl;
    }
    for (int i=0; i<n_demidogs;i++)\
    {
        damage=array_demidogs[i].attack();
        sum+=damage;
        cout<<"demidog "<<i<<"attacks: damage"<<damage<<endl;
    }   
    return sum;
    
}


