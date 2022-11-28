#include <iostream>
class Musician {
private:
    std::string name;
    int price;
public:
    Musician(std::string name1,int price1){
        name=name1;
        price=price1;
    }
    std::string get_name() {return name;};
    int get_price(){return price;};
};
class Music_Festival {
private:
    int budjet;
    std::string musicians[10];
    int prices[10];
public:
    std::string get_musicians(){return musicians[10];};
    int get_budjet(){return budjet;};
    int get_prices(){return prices[10];};
    Music_Festival(int budjet1){
        budjet=budjet1;
    }
    Music_Festival() {
        budjet = 5;
    }
    friend void add_musician();
};
void add_musician() {
    int sum=0;
    int i=0;
    Music_Festival music_festival1(5);
    for (int j=0; j<=5; j++) {
        int price[10];
        std::cin >> price[j];
        std::string name[5];
        std::cin >> name[j];
        Musician musician1(name[j], price[j]);
        if (musician1.get_price() <= music_festival1.get_budjet()) {
            music_festival1.musicians[j] = musician1.get_name();
            music_festival1.prices[j]= musician1.get_price();
        } else if (musician1.get_price() > music_festival1.get_budjet())
        {
            std::cout<<musician1.get_name()<<" is too expensive for our concert"<<std::endl;
            continue;
        }
    }
    for (;i<=5;i++){
        if ((music_festival1.prices[i]+sum<=music_festival1.get_budjet())) {
            std::cout << "we can afford " << music_festival1.musicians[i] << " for our concert," << std::endl;
        }
        else if ((music_festival1.musicians[i]!="")&&(music_festival1.musicians[i+1]=="")&&(music_festival1.prices[i]+sum<=music_festival1.get_budjet())&&(music_festival1.prices[i+1]+sum<=music_festival1.get_budjet())){
            std::cout << "we can afford " << music_festival1.musicians[i] << " for our concert.";
        }
        else
            continue;
        sum+=music_festival1.prices[i];
    }
}
int main(){
    add_musician();
    return 0;
}



