/*
 * main.cpp
 *
 *  Created on: Jun 7, 2011
 *      Author: som
 */

#include "SalesTax.h"
#include "Item.h"
#include "ItemCreator.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
typedef vector<Item*> listOfItem;
listOfItem::iterator theIterator;

listOfItem Basket;
char answer = 'n';

double totalprice = 0;
double totaltax = 0;

do
{
int type_of_item;

cout<<"Enter the type of Item...1,2,3,4"<<endl;

cout<<"1 for ITEM_WITH_NOSALESTAX_AND_NOIMPORTDUTY"<<endl;

cout<<"2 for ITEM_WITH_NOSALESTAX_ONLY_IMPORTDUTY"<<endl;

cout<<"3 for ITEM_WITH_ONLY_SALESTAX_AND_NOIMPORTDUTY"<<endl;

cout<<"4 for ITEM_WITH_BOTH_SALESTAX_AND_IMPORTDUTY"<<endl;

cin>>type_of_item;

ItemCreator* itemCreator = new ItemCreator();

try
{
Item* item = itemCreator->Create(type_of_item);

cout<<"Enter the price of the Item"<<endl;

double price;

cin>>price;

item->SetPrice(price);

Basket.push_back(item);
}

catch(Not_A_Standard_Item_Type_Exception& e)
{
e.printerrormsg();
}

cout<<"Do you want to continue... Y/N"<<endl;
cin>>answer;
}
while (answer =='y');

theIterator = Basket.begin();

int pos = 0;
while (theIterator != Basket.end())
{
Basket.at(pos)->CalculateTotalTax();
totaltax+=Basket.at(pos)->getTax();

Basket.at(pos)->CalculateTotalPrice();

double price = Basket.at(pos)->getPrice();

double price_after_tax = Basket.at(pos)->getTotalPrice();

totalprice+=price_after_tax;

cout<<"Item"<<pos+1<<" price "<<price<<endl;
theIterator++;
pos++;
}
cout<<"------------"<<endl;
cout<<"Toal tax "<<totaltax<<endl;
cout<<"Total price "<<totalprice<<endl;

return 1;
}
