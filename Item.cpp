/*
 * Item.cpp
 *
 *  Created on: Jun 7, 2011
 *      Author: som
 */

#include "SalesTax.h"
#include "Item.h"

Item::Item(){}

Item::Item(SalesTax* aSalesTax):iSalesTax(aSalesTax),iPrice(0),iTotalPrice(0),iTotalTax(0)
{
}

void Item::CalculateTotalPrice()
{
iTotalPrice = iPrice + iTotalTax;
}

double Item::getTotalPrice()
{
return iTotalPrice;
}


void Item::CalculateTotalTax()
{
iTotalTax = iSalesTax->ComputeSalesTax(iPrice, 0, 0);
}

void Item::SetPrice(double aPrice)
{
iPrice = aPrice;
}

double Item::getPrice()
{
return iPrice;
}

double Item::getTax()
{
return iTotalTax;
}
ImportedItem::ImportedItem(){}

ImportedItem::ImportedItem(SalesTax* aSalesTax, double aImportDuty):Item(aSalesTax)
{
iImportDuty = aImportDuty;
}
void ImportedItem::CalculateTotalTax()
{
iTotalTax = iSalesTax->ComputeSalesTax(iPrice, 0, iImportDuty);

}
NonFoodBookMedicalItem::NonFoodBookMedicalItem(){}

NonFoodBookMedicalItem::NonFoodBookMedicalItem(SalesTax* aSalesTax, double aRate):Item(aSalesTax)
{
iRate = aRate;
}

void NonFoodBookMedicalItem::CalculateTotalTax()
{
iTotalTax = iSalesTax->ComputeSalesTax(iPrice, iRate, 0);

}
NormalItem::NormalItem() {}

NormalItem::NormalItem(SalesTax* aSalesTax, double aRate, double aImportDuty):Item(aSalesTax)
{
iRate = aRate;
iImportDuty = aImportDuty;
}
void NormalItem::CalculateTotalTax()
{
iTotalTax = iSalesTax->ComputeSalesTax(iPrice, iRate, iImportDuty);
}


