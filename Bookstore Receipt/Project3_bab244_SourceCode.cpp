/*
Blake Burns
Project3_bab244_SourceCode.cpp
modified Oct. 11, 2017
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
    int numCustomers;
    int numbooks;
    double bookPrice;
    double subTotal;
    double priceDiscount;
    double salesTax = 0.08;
    double discount = 0.05;
    double totalDiscount;
    double totalAmountPaid;
    double subAfterDiscount;
    double salesTaxAmount;
    //open the input file
    ifstream fin;
    fin.open("Project3_bab244_Input.txt");
    //open the output file
    ofstream fout;
    fout.open("Project3_bab244_Output.txt");
//---------------------------------------------------------------------------------------------------------

    //get the heading line from input file and print it to output file
    getline(fin, heading);
    fout << setw(73) << heading;
    fout << endl;
    getline(fin, heading);
    fout << setw(68) << heading;
    fout << endl;
    fout << endl;

    cout << "How many customers are there? (5-10):";
    cin >> numCustomers;

    if(numCustomers < 5 || numCustomers > 10)
    {
        cout << "ERROR: Number of customers must be from 5-10";
    }
    else

    //get customers name from input file and print to output file
    fout << fixed << setprecision(2);
    for(int i = 0; i < numCustomers; i++)
    {
            getline(fin, fullName);
            fout << "Customer Name: " << fullName << endl;
            //get customers number from input file and print to output file
            getline(fin, number);
            fout << "Customer Telephone Number: " << number << endl;
            //get customers address from input file and print to output file
            getline(fin, address);
            fout << "Customer Address: " << address << endl;
            fout << endl;
            subTotal = 0.0;
            totalDiscount = 0.0;
            subAfterDiscount = 0.0;
            salesTaxAmount = 0.0;
            totalAmountPaid = 0.0;
        // get book information from input file and print to output file
        for(int numBooks = 0; numBooks < 4; numBooks++)
        {
            getline(fin, bookNumber);
            fout << "Book Number: " << bookNumber << endl;
            getline(fin, bookTitle);
            fout << "Book Title: " << bookTitle << endl;
            getline(fin, bookAuthor);
            fout << "Book Author: " << bookAuthor << endl;
            fin >> aisleNumber;
            fout << "Aisle Number: " << aisleNumber << endl;
            fin >> bookPrice;
            fout << "Price of Book: $" << bookPrice << endl;
            fin.ignore();

            //calculate price discount if book price is greater than $90
            if(bookPrice > 90)
                priceDiscount = bookPrice * discount;
            else
                priceDiscount = 0.0;

                fout << "Price Discount: $" << priceDiscount << endl;
                fout << endl;


        subTotal = subTotal + bookPrice;
        totalDiscount = totalDiscount + priceDiscount;
        subAfterDiscount = subTotal - totalDiscount;
        salesTaxAmount = subAfterDiscount * salesTax;
        totalAmountPaid = subAfterDiscount + (subAfterDiscount * salesTax);
        }

    //print subtotal to output file
    fout << "Sub Total of Four Books: $" << fixed << setprecision(2) << subTotal << endl;

    //print total discount to output file
    fout << "Total Discount: $" << fixed << setprecision(2) << totalDiscount << endl;

    //print subtotal after discount to output file
    fout << "Subtotal after Discount: $" << fixed << setprecision(2) << subAfterDiscount << endl;
    fout << endl;

    //print sales tax to output file
    fout << "Sales Tax Amount: $" << fixed << setprecision(2) << salesTaxAmount << endl;
    fout << endl;

    //print total amount paid to output file
    fout << "Total Amount Paid: $" << fixed << setprecision(2) << totalAmountPaid << endl;
    fout << "------------------------------------------------------------------------------------";
    fout << endl;

    }

    //get the ending header and print to output file
    getline(fin, ending);
    fout << setw(73) << ending;
    //close the input file
    fin.close();
    //close the output file
    fout.close();

    return 0;


}
