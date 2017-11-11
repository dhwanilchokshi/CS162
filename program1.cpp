//Dhwanil Chokshi
//CS162
//Program 1
/*
The purpose of this program is to use the currency rate to exchange
between Dollars and Yuan. Also if the user has a certain amount of
dollars, then what denomination they will need in Yuan to match the
amount.
*/

#include <iostream>
using namespace std;


int main ()
{
  double yuan_rate = 6.50824;
  char inst_response;
  char convert_choice;
  double dollar_input, yuan_input;
  double dollar2yuan, yuan2dollar;
  char end_choice;
  double dollar_amount;
  double amount;
  int hundred_bill, fifty_bill, twenty_bill, ten_bill, five_bill, one_bill;
  double left_amount, left_amount2, left_amount3, left_amount4, left_amount5;
  double cents;
  int user_hundred, user_fifty, user_twenty, user_ten, user_five, user_one;
  int yuan_sum;
  double dollar_sum;

    cout << "\nWelcome to the China trip Exchange Rate Program!!" << endl;
    cout << "This program is helpful for conversion of Yuan and Dollars only!" << endl;

    do
    {
      cout << "\nWould you like instructions on how this program works? (Y/y for yes, N/n for no): ";
      cin >> inst_response;
      if (inst_response != 'Y' && inst_response != 'y' && inst_response != 'N' && inst_response != 'n')
        cout << "OOPS! You entered an invalid choice!" << endl;
    }while (inst_response != 'Y' && inst_response != 'y' && inst_response != 'N' && inst_response !='n');

    if (inst_response == 'Y' || inst_response == 'y')
    {
      cout << "\n(1) -- This program is to help you convert dollars to yuan and yuan to dollars." << endl;
      cout << "(2) -- The first part of this program is where you can pick which value you want to convert into the other (Dollars or Yuan)." << endl;
      cout << "(3) -- The second part of the program will help you with getting denomination of each Yuan note from your Dollar balance." << endl;
      cout << "(4) -- The last part of the program will convert your leftover Yuan to Dollars so you know how much money you have." << endl;
      cout << "(5) -- You can repeat the three parts of the program as many times as you wish! Good Luck!" << endl;
    }

    else if (inst_response == 'N' || inst_response == 'n')
    {
      cout << "\nYou are ready to move on!" << endl;
    }
//PHASE 1 of the program
//Basic conversion of Yuan to Dollar or vice versa
//Display it back to the user
    do
    {
      cout << "\nWelcome to PHASE 1!" << endl;
      cout << "Please choose if you want to convert from Dollars to Yuan or Yuan to Dollar." << endl;
      cout << "If you choose to convert from Dollar to Yuan, please type the letter 'A/a'." << endl;
      cout << "If you choose to convert from Yuan to Dollar, please type the letter 'B/b'." << endl;

      do
      {
        cout << "CHOICE: ";
        cin >> convert_choice;
        if (convert_choice != 'A' && convert_choice != 'a' && convert_choice != 'B' && convert_choice != 'b')
          cout << "OOPS! You entered an invalid choice!" << endl;
      }while (convert_choice != 'A' && convert_choice != 'a' && convert_choice != 'B' && convert_choice != 'b');

      if (convert_choice == 'A' || convert_choice == 'a')
      {
        do
        {
      	  cout << "\nPlease enter in the amount of Dollars you would like to convert to Yuan: $";
          cin >> dollar_input;
          if (dollar_input < 0)
            cout << "OOPS! Enter a POSITIVE value!" << endl;
        }while (dollar_input < 0);
        dollar2yuan = dollar_input * yuan_rate;
        cout << "The Yuan amount you have at hand is: " << dollar2yuan << endl;
      }

      else if (convert_choice == 'B' || convert_choice == 'b')
      {
        do
        {
          cout << "\nPlease enter in the amount of Yuan you would like to convert to Dollars: ";
          cin >> yuan_input;
          if (yuan_input < 0)
            cout << "OOPS! Enter a POSITIVE value!" << endl;
        }while (yuan_input < 0);
        yuan2dollar = yuan_input / yuan_rate;
        cout << "The Dollar amount you have at hand is: " << yuan2dollar << endl;
      }

    cout << "\nWould you like to end PHASE 1? (type 'Y/y' to end, press any other letter to repeat PHASE 1): ";
    cin >> end_choice;
    }while (end_choice != 'Y' && end_choice != 'y');

//PHASE 2 - ask user for the dollar amount they have
//convert the amount to Yuan
//display the amount of each note denomination they will need

    cout << "\nWelcome to the PHASE 2 of this program!" << endl;
    do
    {
      do
      {
        cout << "\nPlease enter in the amount of Dollars you have at hand: $";
        cin >> dollar_amount;
        if (dollar_amount < 0)
        cout << "OOPS! Enter a POSITIVE value!" << endl;
      }while (dollar_amount < 0);
      amount = dollar_amount * yuan_rate;
      cout << "Your amount in Yuan is: " << amount << endl;

      hundred_bill = amount/100;
      cout << "\nYou will need " << hundred_bill << " hundred(s)" << endl;
      left_amount = amount - (hundred_bill * 100);

      fifty_bill = left_amount/50;
      cout << "You will need " << fifty_bill << " fifty(s)" << endl;
      left_amount2 = left_amount - (fifty_bill * 50);

      twenty_bill = left_amount2/20;
      cout << "You will need " << twenty_bill << " twenty(s)" << endl;
      left_amount3 = left_amount2 - (twenty_bill * 20);

      ten_bill = left_amount3/10;
      cout << "You will need " << ten_bill << " ten(s)" << endl;
      left_amount4 = left_amount3 - (ten_bill * 10);

      five_bill = left_amount4/5;
      cout << "You will need " << five_bill << " five(s)" << endl;
      left_amount5 = left_amount4 - (five_bill * 5);

      one_bill = left_amount5/1;
      cents = left_amount5 - (one_bill * 1);
      cout << "You will need " << one_bill << " one(s) and " << cents << " cents" << endl;

      cout << "\nWould you like to end PHASE 2? (Type 'Y/y' to end, press any other letter to repeat PHASE 2): ";
      cin >> end_choice;
    }while (end_choice != 'Y' && end_choice != 'y');

//PHASE 3 - Ask the user for the amount of each Yuan note denomination they have leftover
//Add the denomination together
//Output total and convert to dollars

    cout << "\nWelcome to PHASE 3 of this program!" << endl;
    do
    {
      cout << "Please enter in the amount of each Yuan note you have!" << endl;
      do
      {
        cout << "\nHow many hundred(s) note(s) do you have? ";
        cin >>  user_hundred;
        cout << endl;
        if (user_hundred < 0)
          cout << "OOPS! Enter a POSITIVE value!" << endl;
      }while (user_hundred < 0);

      do
      {
        cout << "How many fifty(s) note(s) do you have? ";
        cin >> user_fifty;
        cout << endl;
        if (user_fifty < 0)
          cout << "OOPS! Enter a POSITIVE value!" << endl;
      }while (user_fifty < 0);

      do
      {
        cout << "How many twenty(s) note(s) do you have? ";
        cin >> user_twenty;
        cout << endl;
        if (user_twenty < 0)
          cout << "OOPS! Enter a POSITIVE value!" << endl;
      }while (user_twenty < 0);

      do
      {
        cout << "How many ten(s) note(s) do you have? ";
        cin >> user_ten;
        cout << endl;
        if (user_ten < 0)
          cout << "OOPS! Enter a POSITIVE value!" << endl;
      }while (user_ten < 0);

      do
      {
        cout << "How many five(s) note(s) do you have? ";
        cin >> user_five;
        cout << endl;
        if (user_five < 0)
          cout << "OOPS! Enter a POSITIVE value!" <<endl;
      }while (user_five < 0);

      do
      {
        cout << "How many one(s) note(s) do you have? ";
        cin >> user_one;
        cout << endl;
        if (user_one < 0)
          cout << "OOPS! Enter a POSITIVE value!" << endl;
      }while (user_one < 0);

      yuan_sum = (user_hundred * 100) + (user_fifty * 50) + (user_twenty * 20) + (user_ten * 10) + (user_five * 5) + (user_one * 1);
      cout << "The total amount of Yuan you have is: " << yuan_sum << endl;

      dollar_sum = yuan_sum/yuan_rate;
      cout << "\nThe amount of Dollars you have at hand is: $" << dollar_sum << endl;
      cout << "\nWould you like to end PHASE 3? (Press 'Y/y' to end, press any other letter to repeat PHASE 3): ";
      cin >> end_choice;
    }while (end_choice!= 'Y' && end_choice != 'y');

    cout << "\nYOU HAVE REACHED THE END! HOPE YOU ENJOYED!" << endl;
return 0;
}
