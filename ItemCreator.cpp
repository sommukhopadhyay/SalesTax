/*
 * ItemCreator.cpp
 *
 *  Created on: Jun 7, 2011
 *      Author: som
 */

#include "ItemCreator.h"
#include "Item.h"
#include "SalesTax.h"

#include <iostream>

using namespace std;

void Not_A_Standard_Item_Type_Exception::printerrormsg()
{
cout<<"Not the right Item Type..."<<endl;
}

Item* ItemCreator::Create(int aItemId)
{
SalesTax* st = new SalesTax();

switch(aItemId)
{
case ITEM_WITH_NOSALESTAX_AND_IMPORTDUTY:
return new Item(st);
break;

case ITEM_WITH_NOSALESTAX_ONLY_IMPORTDUTY:
return new ImportedItem(st,IMPORT_DUTY_RATE);
break;

case ITEM_WITH_ONLY_SALESTAX_AND_NOIMPORTDUTY:
return new NonFoodBookMedicalItem(st,SALES_TAX_RATE);
break;

case ITEM_WITH_BOTH_SALESTAX_AND_IMPORTDUTY:
return new NormalItem(st,SALES_TAX_RATE,IMPORT_DUTY_RATE);
break;

default:
throw Not_A_Standard_Item_Type_Exception();
}
}
