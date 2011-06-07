/*
 * ItemCreator.h
 *
 *  Created on: Jun 7, 2011
 *      Author: som
 */

#ifndef ITEMCREATOR_H_
#define ITEMCREATOR_H_
#include "Item.h"

const int ITEM_WITH_NOSALESTAX_AND_IMPORTDUTY = 1;
const int ITEM_WITH_NOSALESTAX_ONLY_IMPORTDUTY = 2;
const int ITEM_WITH_ONLY_SALESTAX_AND_NOIMPORTDUTY = 3;
const int ITEM_WITH_BOTH_SALESTAX_AND_IMPORTDUTY = 4;

const double SALES_TAX_RATE = 10;
const double IMPORT_DUTY_RATE = 5;

class Not_A_Standard_Item_Type_Exception
{
public:
void printerrormsg();
};
class ItemCreator
{
public:
virtual Item* Create(int aItemId);

};

#endif /* ITEMCREATOR_H_ */
