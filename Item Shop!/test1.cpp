#include <iostream>
#include <string>
#include "Shop.h"
#include <cstdlib>
#include "Player.h"
using namespace std;


void initShops(list<Shop> &shops);
void initPlayers(Player &player);
void enterShop(Player &player,Shop &shop);
void printInventory(Player &player);

int main()
{
    //Tells us when the game is over
    list<Shop> shops;
    list<Shop>::iterator lit;
    Player player;
    string shopName;


    initPlayers(player);
    initShops(shops);
    bool isDone=false;
    while(isDone==false){
        cout<<"Shops: \n";
        int i=1;
        for(lit=shops.begin();lit!=shops.end();lit++){
            cout << i <<". "<<(*lit).getName()<<endl;
            i++;
        }
        cout << "What shop would you like to enter: ?Q to quit"<<endl;

        getline(cin,shopName);

if (shopName == "Q" || shopName == "q") {
            isDone = true;
        } else {

            cout << endl;

            bool validShop = false;
            //check to see if the user entered a valid shop
            for (lit = shops.begin(); lit != shops.end(); lit++) {
                if ((*lit).getName() == shopName) {
                    enterShop(player, (*lit));
                    validShop = true;
                }
            }

            if (validShop == false) {
                cout << "Invalid Shop!\n";
                system("PAUSE");
            }
        }

    }

    system("PAUSE");
    return 0;
}
void initPlayers(Player &player){
cout<<"Enter thy name sir knight: ";
string name;
getline(cin,name);
player.init(name,100);

player.addItem(Items("Bronze Sword",5,1));
cout<<"\n";
}

void initShops(list<Shop> &shops){    //we createed a list so that we create locations in memory of Shop::shops
    shops.push_back(Shop("Bill's Leather Works",500)); //what are we doing here? creating many shops objects?

    shops.back().addItem(Items("Leather Boots",100,3));
    shops.back().addItem(Items("Leather Belt",150,3));
    shops.back().addItem(Items("Leather Hat",100,2));
    shops.back().addItem(Items("Leather ChestPiece",75,3));
    shops.back().addItem(Items("Leather Gauntlets",200,1));

    shops.push_back(Shop("The Blacksmith", 1500));

    shops.back().addItem(Items("Iron Boots", 100, 2));
    shops.back().addItem(Items("Iron Hat", 100, 3));
    shops.back().addItem(Items("Iron Gloves", 100, 2));
    shops.back().addItem(Items("Iron Gauntlets", 100, 2));
    shops.back().addItem(Items("Iron Chestpiece", 200, 1));
    shops.back().addItem(Items("Iron Sword", 150, 2));
    shops.back().addItem(Items("Iron Shield", 150, 1));

    shops.push_back(Shop("Beverly's fruity fruit shop", 250));
    shops.back().addItem(Items("Grapes", 5, 10));
    shops.back().addItem(Items("Apple", 5, 5));
    shops.back().addItem(Items("Orange", 5, 20));
    shops.back().addItem(Items("Watermelon", 10, 3));
    shops.back().addItem(Items("Tomato", 3, 10));

}
void enterShop(Player &player,Shop &shop){
    bool isDone=false;
    string itemName;
    char input;
    Items newItem("NOITEM",0,0);
    while(isDone==false){
        shop.printShop();
        player.printInventory();
        cout<<"Would you like to buy or sell? (B|S)";
        cin>>input;
        if(input=='Q'){return;}
        if(input=='B'){
        cout<<"Enter the item you wish to Buy: \n";
        cin.ignore(65,'\n');
        cin.clear();
        getline(cin,itemName);
        if(shop.canAffordItem(itemName,player.getMoney())==true){
            if(shop.purchaseItem(itemName,newItem)==true){
                player.addItem(newItem);
                player.subtractMoney(newItem.getValue());
                shop.addMoney(newItem.getValue());
                }else{cout<<"That is an invalid item\n";

                system("PAUSE");}
            }
            else{cout<<"You dont have enough money\n";}
            }
        else{
        cout<<"Enter the item you wish to sell\n";
        cin.ignore(65,'\n');
        cin.clear();
        getline(cin,itemName);
        if(player.canAffordItem(itemName,shop.getMoney())==true){

            if(player.removeItem(itemName,newItem)==true){
                shop.addItem(newItem);
                shop.addMoney(newItem.getValue());
                player.subtractMoney(-newItem.getValue());
            }
        else{cout<<"That is an invalid item\n";
            system("PAUSE");}
        }else{cout<<"The shop doesn't have enough money\n";}
        }
    }
}
