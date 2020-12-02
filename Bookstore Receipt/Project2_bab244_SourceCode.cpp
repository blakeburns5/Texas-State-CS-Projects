/*
Blake Burns
Project2_bab244_SourceCode.cpp
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    string heading;
    string fullName;
    string number;
    string address;
    string bookNumber;
    string bookTitle;
    string bookAuthor;
    string ending;
    int aisleNumber;
    double bookPrice1, bookPrice2, bookPrice3;
    double subTotal;
    double priceDiscount1, priceDiscount2, priceDiscount3;
    double salesTax = 0.08;
    double discount = 0.05;
    double totalDiscount;
    double totalAmountPaid;
    double subAfterDiscount;
    double salesTaxAmount;
    //open the input file
    ifstream fin;
    fin.open("Project2_bab244_Input.txt");
    //open the output file
    ofstream fout;
    fout.open("Project2_bab244_Output.txt");
//---------------------------------------------------------------------------------------------------------
    //get the heading line from input file and print it to output file
    getline(fin, heading);
    fout << setw(73) << heading;
    fout << endl;
    getline(fin, heading);
    fout << setw(68) << heading;
    fout << endl;
    fout << endl;

    //get customers name from input file and print to output file
    getline(fin, fullName);
    fout << "Customer Name: " << fullName << endl;

    //get customers number from input file and print to output file
    getline(fin, number);
    fout << "Customer Telephone Number: " << number << endl;

    //get customers address from input file and print to output file
    getline(fin, address);
    fout << "Customer Address: " << address << endl;
    fout << endl;
//----------------------------------------------------------------------------------------------------------
    //get book number, title, author, aisle number, and price
    //from input file and print to output file
    getline(fin, bookNumber);
    fout << "Book Number: " << bookNumber << endl;
    getline(fin, bookTitle);
    fout << "Book Title: " << bookTitle << endl;
    getline(fin, bookAuthor);
    fout << "Book Author: " << bookAuthor << endl;
    fin >> aisleNumber;
    fout << "Aisle Number: " << aisleNumber << endl;
    fin >> bookPrice1;
    fout << "Price of Book: $" << bookPrice1 << endl;

    //calculate price discount if book price is greater than $90
    if(bookPrice1 > 90)
        priceDiscount1 = bookPrice1 * discount;
    else
        priceDiscount1 = 0.0;

    //print discount
    fout << "Cost Discount: $" << fixed << setprecision(2) << priceDiscount1 << endl;
    fout << endl;
    fin.ignore();
//-----------------------------------------------------------------------------------------------------------
    //get book number, title, author, aisle number, and price
    //from input file and print to output file
    getline(fin, bookNumber);
    fout << "Book Number: " << bookNumber << endl;
    getline(fin, bookTitle);
    fout << "Book Title: " << bookTitle << endl;
    getline(fin, bookAuthor);
    fout << "Book Author: " << bookAuthor << endl;
    fin >> aisleNumber;
    fout << "Aisle Number: " << aisleNumber << endl;
    fin >> bookPrice2;
    fout << "Price of Book: $" << bookPrice2 << endl;

    //calculate price discount if book price is greater than $90
     if(bookPrice2 > 90)
        priceDiscount2 = bookPrice1 * discount;
    else
        priceDiscount2 = 0.0;

    //print discount
    fout << "Cost Discount: $" << fixed << setprecision(2) << priceDiscount2 << endl;
    fout << endl;
    fin.ignore();
//------------------------------------------------------------------------------------------------------------
    //get book number, title, author, aisle number, and price
    //from input file and print to output file
    getline(fin, bookNumber);
    fout << "Book Number: " << bookNumber << endl;
    getline(fin, bookTitle);
    fout << "Book Title: " << bookTitle << endl;
    getline(fin, bookAuthor);
    fout << "Book Author: " << bookAuthor << endl;
    fin >> aisleNumber;
    fout << "Aisle Number: " << aisleNumber << endl;
    fin >> bookPrice3;
    fout << "Price of Book: $" << bookPrice3 << endl;

    //calculate price discount if book is greater than $90
     if(bookPrice3 > 90)
        priceDiscount3 = bookPrice3 * discount;
    else
        priceDiscount3 = 0.0;

    //print discount
    fout << "Cost Discount: $" << fixed << setprecision(2) << priceDiscount3 << endl;
    fout << endl;
//------------------------------------------------------------------------------------------------------------
    //calculate subtotal
    subTotal = bookPrice1 + bookPrice2 + bookPrice3;
    //print subtotal to output file
    fout << "Sub Total of Three Books: $" << fixed << setprecision(2) << subTotal << endl;
    //calculate the total discount
    totalDiscount = priceDiscount1 + priceDiscount2 + priceDiscount3;
    //print total discount to output file
    fout << "Total Discount: $" << fixed << setprecision(2) << totalDiscount << endl;
    //calculate subtotal after discount
    subAfterDiscount = subTotal - totalDiscount;
    //print subtotal after discount to output file
    fout << "Subtotal after Discount: $" << fixed << setprecision(2) << subAfterDiscount << endl;
    fout << endl;
    //calculate sales tax
    salesTaxAmount = subAfterDiscount * salesTax;
    //print sales tax to output file
    fout << "Sales Tax Amount: $" << fixed << setprecision(2) << salesTaxAmount << endl;
    fout << endl;
    //calculate total amount paid
    totalAmountPaid = subAfterDiscount + (subAfterDiscount * salesTax);
    //print total amount paid to output file
    fout << "Total Amount Paid: $" << fixed << setprecision(2) << totalAmountPaid << endl;
    fout << endl;
    fin.ignore();

    //get the ending header and print to output file
    getline(fin, ending);
    fout << setw(73) << ending;
    //close the input file
    fin.close();
    //close the output file
    fout.close();

    return 0;


}
