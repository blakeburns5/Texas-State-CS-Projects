/*
Blake Burns
Project4_bab244_SourceCode.cpp
Nov 2, 2017
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

int main()
{

    ifstream fin;
    fin.open("Project4_bab244_Input.txt");
    ofstream fout;
    fout.open("Project4_bab244_Output.txt");

    string customers_NonNumeric[5][2]; //to store receipt title, customer name and address.
    int customers_Numeric1[5][2]; //to store customer age and number of books customer is buying.
    double customers_Numeric2[5][5]; //to store two subtotals, amounts of discounts and tax, and total amount paid.
    string books_NonNumeric[5][3][4]; //to store book numbers, titles, authors and Aisle numbers for all three books of five customers.
    double books_Numeric[5][3][2]; //to store prices and cost discounts for all three books of five customers


    int numUsers = 5;

     fout << "\t\t\tThe University Book Store, San Marcos, Texas 78666" << endl;
     fout << "\t\t\t\tRECEIPT #95, Sept. 17, 2017, 9:00 PM" << endl;
     fout << endl;


    for(int i = 0; i < numUsers; i++)
    {

        for(int j = 0; j < 2; j++)
        {
            getline(fin, customers_NonNumeric[i][j]); //
        }
        fin >> customers_Numeric1[i][0];
        fin >> customers_Numeric1[i][1];
        fout << "Customer Name: " << customers_NonNumeric[i][0] << endl;
        fout << "Customer Address: " << customers_NonNumeric[i][1] << endl;
        fout << "Customer Age: " << customers_Numeric1[i][0] << endl;
        fout << "Number of Books Customer is buying: " << customers_Numeric1[i][1] << endl;
        fout << endl;
    fin.ignore();

        for(int k = 0; k < 3; k++)
        {
            getline(fin, books_NonNumeric[i][k][0]); // read in book number
            getline(fin, books_NonNumeric[i][k][1]); // read in book title
            getline(fin, books_NonNumeric[i][k][2]); // read in book author
            getline(fin, books_NonNumeric[i][k][3]); // read in aisle number

            fin >> books_Numeric[i][k][0]; // read in book price
            fin >> books_Numeric[i][k][1]; // read in book discount

            fout << "Book Number: " << books_NonNumeric[i][k][0] << endl;
            fout << "Book Title: " << books_NonNumeric[i][k][1] << endl;
            fout << "Book Author: " << books_NonNumeric[i][k][2] << endl;
            fout << "Aisle Number: " << books_NonNumeric[i][k][3] << endl;
           fin.ignore();
            fout << "Book Price: $" << books_Numeric[i][k][0] << endl;
            fout << "Book Discount: $" << books_Numeric[i][k][1] << endl;
            fout << endl;

        }
        //for(int m = 0; m < 4; m++)
        //{
            fin >> customers_Numeric2[i][0];
            fin >> customers_Numeric2[i][1];
            fin >> customers_Numeric2[i][2];
            fin >> customers_Numeric2[i][3];
            fin >> customers_Numeric2[i][4];
        fin.ignore();

            fout << "Sub Total of Three Books: $" << fixed << setprecision(2)<< customers_Numeric2[i][0] << endl;
            fout << "Total Discount: $" << fixed << setprecision(2)<< customers_Numeric2[i][1] << endl;
            fout << "Subtotal after Discount: $" << fixed << setprecision(2)<< customers_Numeric2[i][2] << endl;
            fout << endl;
            fout << "Sales Tax Amount: $" << fixed << setprecision(2)<< customers_Numeric2[i][3] << endl;
            fout << endl;
            fout << "Total Amount Paid: $" << fixed << setprecision(2)<< customers_Numeric2[i][4] << endl;
            fout << endl;



        //}


    }
    fout << "\t\t\tThank you for shopping at the University Book Store";
    return 0;
}
