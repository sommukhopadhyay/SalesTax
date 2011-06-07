/*
 * SalesTax.h
 *
 *  Created on: Jun 7, 2011
 *      Author: som
 */

#ifndef SALESTAX_H_
#define SALESTAX_H_
//This class works as the Strategy of the Sales tax problem
class SalesTax
{
public:

//Default constructor
SalesTax();

//This function helps to compute the Sales Tax
virtual double ComputeSalesTax(double aPrice, double aRate, double aImportduty);

private:
//This is an helper function which will round off the sales tax
double RoundOff(double aTax);
};

#endif /* SALESTAX_H_ */
