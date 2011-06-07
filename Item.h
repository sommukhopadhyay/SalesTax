/*
 * Item.h
 *
 *  Created on: Jun 7, 2011
 *      Author: som
 */

#ifndef ITEM_H_
#define ITEM_H_

class SalesTax;

//This represents the Items which don't have an Import duty or any sales tax
class Item
{
public:

//Constructors
Item();
Item (SalesTax* aSalesTax);

//Interface Functions for Item

//To calculate the price after tax and import duty
virtual void CalculateTotalPrice();

//To calculate the total tax and import duty
virtual void CalculateTotalTax();

//To set the price of the Items
void SetPrice(double aPrice);

//To get the price of the Items before tax
double getPrice();

//To get the price of the items after tax
double getTotalPrice();

//To get the total tax and import duty of the items
double getTax();

//Data
protected:
//Works as the Strategy of the Sales Tax problem.
//If in future the tax calculation becomes more complicated for different Items
//we will just have to change this Strategy. We can also subclass this Strategy class
//for future expansion of the tax calculation strategy
SalesTax* iSalesTax;
//Data
protected:

//These are the basic properties of any Item.
//Hence these are made protected members so that the subclasses of Item can inherit
//these properties
double iPrice;
double iTotalPrice;
double iTotalTax;
};

//This class represents the Items which have only Import Duty
class ImportedItem : virtual public Item
{
public:
//Constructors
ImportedItem();

//This constructor helps to create Items having only Import duty
ImportedItem(SalesTax* aSalesTax, double aImportDuty);

//Override
virtual void CalculateTotalTax();

protected:
double iImportDuty;
};

//This class represents the Items which have only Sales Tax but no Import Duty
class NonFoodBookMedicalItem : virtual public Item
{
public:
//Constructors
NonFoodBookMedicalItem();

//This constructor helps to create Items having only Sales tax
NonFoodBookMedicalItem(SalesTax* aSalesTax, double aRate);
//Override
virtual void CalculateTotalTax();

protected:
double iRate;
};

//This class represents the Items which have got both Import Duty as well as sales Tax
class NormalItem: public ImportedItem, public NonFoodBookMedicalItem
{
public:
NormalItem();
//This constructor helps to create Items having both Sales tax and Import duty
NormalItem(SalesTax* aSalesTax, double aRate, double aImportDuty);

//Override
virtual void CalculateTotalTax();
};

#endif /* ITEM_H_ */
