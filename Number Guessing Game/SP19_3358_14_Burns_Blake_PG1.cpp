/*
Authors: Blake Burns
Serial Number:
Due Date: 2.6.2019
Programming Assignment Number: 1
Spring 2019 - CS 3358.252

Instructor: Husain Gholoom

This program will simulate a simple game that you can play with the computer. The
computer will generate a random number and the user will try to guess the number
getting hints along the way.
*/


#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;



void printHeading();

int main()
{
    const int numGuesses = 10;
    int randomNumber1;
    int randomNumber2;
    int randomNumber3;
    int userGuess;
    char again = 'y';

   printHeading();


    while(again == 'y' || again == 'Y')
    {


//**********Random Number Generator*************
        srand(time(0));
        randomNumber1 = rand() % 10;
        randomNumber2 = rand() % 10;
        randomNumber3 = rand() % 10;

        if(randomNumber2 == randomNumber1)
        {
            randomNumber2 = rand() % 10;
        }
        else if(randomNumber3 == randomNumber2)
        {
            randomNumber3 = rand() % 10;
        }
        else if(randomNumber3 == randomNumber1)
        {
            randomNumber3 = rand() % 10;
        }

        int randomArray[3] = {randomNumber1, randomNumber2, randomNumber3};

        cout << randomArray[0] << randomArray[1] << randomArray[2];
        cout << endl << endl;

        int userArray[3];

        for(int i = 1; i < numGuesses + 1; i++)
        {

            cout << "Guess #" << i << ": ";
            cin >> userGuess;

            userArray[2] = userGuess % 10;
            userArray[1] = (userGuess / 10) % 10;
            userArray[0] = userGuess / 100;

            if(i > 9)
                {
                    cout << "Sorry, You exceeded the max number of guesses." << endl;
                    cout << "The secret number was: " << randomNumber1 << randomNumber2 << randomNumber3 << endl;
                    cout << endl;
                    break;
                }

            if(userArray[0] == randomArray[0] && userArray[1] == randomArray[1] && userArray[2] == randomArray[2])
            {
                cout << "You Guessed It!!!" << endl;
                break;

                if(again == 'n' || again == 'N')
                {
                    cout << endl;
                    cout << "Implemented by Blake Burns and Max Rios" << endl;
                    cout << "2.6.2019" << endl;
                    return 0;
                }


            }
            else if(userArray[0] == randomArray[0] || userArray[1] == randomArray[1] || userArray[2] == randomArray[2])
            {
                cout << "F" << endl;
            }
            else if(userArray[0] == randomArray[0] || userArray[0] == randomArray[1] || userArray[0] == randomArray[2])
            {
                cout << "P" << endl;
            }
            else if(userArray[1] == randomArray[0] || userArray[1] == randomArray[1] || userArray[1] == randomArray[2])
            {
                cout << "P" << endl;
            }
            else if(userArray[2] == randomArray[0] || userArray[2] == randomArray[1] || userArray[2] == randomArray[2])
            {
                cout << "P" << endl;
            }
            else if(userArray[0] != randomArray[0] || userArray[0] != randomArray[1] || userArray[0] != randomArray[2])
            {
                cout << "B" << endl;
            }
            else if(userArray[1] != randomArray[0] || userArray[1] != randomArray[1] || userArray[1] != randomArray[2])
            {
                cout << "B" << endl;
            }

            srand(time(0));
            randomNumber1 = rand() % 10;
            randomNumber2 = rand() % 10;
            randomNumber3 = rand() % 10;

            if(randomNumber2 == randomNumber1)
            {
                randomNumber2 = rand() % 10;
            }
            else if(randomNumber3 == randomNumber2)
            {
                randomNumber3 = rand() % 10;
            }
            else if(randomNumber3 == randomNumber1)
            {
                randomNumber3 = rand() % 10;
            }

        }



        cout << "Would you like to play again? (Y/N): ";
        cin >> again;
    }


    cout << endl << endl;
    cout << "Implemented by Blake Burns and Max Rios" << endl;
    cout << "2.6.2019" << endl;
    return 0;

}

void printHeading()
{
    cout << "Welcome to my Game Program" << endl;
    cout << endl;
    cout << "I am thinking of a 3-digit number. Try to guess what it is. Here are some clues: " << endl;
    cout << endl;
    cout << "When I say:       It means:" << endl;
    cout << setw(6) << "B" << setw(32) << "No digit is correct." << endl;
    cout << setw(6) << "P" << setw(59) << "One digit is correct but in the wrong position." << endl;
    cout << setw(6) << "F" << setw(59) << "One digit is correct and is in the right place." << endl;
    cout << endl << endl;
    cout << "I have thought of a number. You have 10 guesses to get it." << endl;
    cout << endl;
}



