/* Final Project Milestone 5:
Module: Main
Filename: main.cpp
Version 1.0
Author: Zeyi Cai, StNo: 124719253,
Email: zcai25@myseneca.ca

Revision History
-----------------------------------------------------------
Date       Reason
2026/08/03 Initial implementation
2026/08/03 Revision
-----------------------------------------------------------
I wrote the program based on the official project instructions. 
I used ChatGPT to clarify the menu flow and assist with debugging.
-----------------------------------------------------------*/
#include <iostream>
#include "Menu.h"
#include "Ordering.h"

using namespace std;
using namespace seneca;

int main() {
   // Initialization 
   Ordering ordering("drinks.csv", "foods.csv");
   // Validation
   if (!ordering) {
      cout << "Failed to open data files or the data files are corrupted!"
           << endl;
      return 1;
   }
 // Main Menu
   Menu mainMenu("Seneca Restaurant", "End Program");

   mainMenu << "Order"
            << "Print Bill"
            << "Start a New Bill"
            << "List Foods"
            << "List Drinks";

   // Sub-Menu for Ordering
   Menu orderMenu("Order Menu", "Back to main menu", 1, 3); 
   
   orderMenu << "Food" << "Drink";
   // Confirmation Menu
   Menu confirmMenu(
      "You have bills that are not saved. Are you sue you want to exit?",
      "No"); 

   confirmMenu << "Yes";
   // program status
   bool done = false;
   while (!done) {
      // Menu Functionality
      size_t selection = mainMenu.select();
      // order
      if (selection == 1) {
         bool backToMain = false;

         while (!backToMain) {
            size_t orderSelection = orderMenu.select();
            // order food
            if (orderSelection == 1) {
               ordering.orderFood();
            }
            // order drink 
            else if (orderSelection == 2) {
               ordering.orderDrink();
            }
            else {
               backToMain = true;
            }
         }
      }
      // print bill
      else if (selection == 2) {
         ordering.printBill();
      }
      // start a new bill
      else if (selection == 3) {
         ordering.resetBill();
      }
      // list foods
      else if (selection == 4) {
         ordering.listFoods();
      }
      // list drinks
      else if (selection == 5) {
         ordering.listDrinks();
      }
      else {
         // Program Exit
         if (ordering.hasUnsavedBill()) {
            size_t confirmSelection = confirmMenu.select();

            if (confirmSelection == 1) { // Yes
               done = true;  // terminate the program
            }
         }
         else {
            done = true; // no unsaved bill, just terminate the program
         }
      }
   }

   return 0;
}