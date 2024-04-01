#include <iostream>
#include "shopping.h"
#include "file_handler.h"

using namespace std;

// Function to display the main menu
void Shopping::menu() {
    string email;
    string password;
    int choice;
    do {
        // Displaying main menu options
        cout << "\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t           Supermarket Main menu          \n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t|         (1 Administrator                |\n";
        cout << "\t\t\t\t|                                         |\n";
        cout << "\t\t\t\t|         (2 Buyer                        |\n";
        cout << "\t\t\t\t|                                         |\n";
        cout << "\t\t\t\t|         (3 Exit                         |\n";
        cout << "\t\t\t\t|                                         |\n";
        cout << "\n\t\t\t Please select! ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Administrator login
                cout << "\t\t\t Please Login \n";
                cout << "\t\t\t Enter Email  \n";
                cin >> email;
                cout << "\t\t\t Enter Password  \n";
                cin >> password;

                if (email == "chris@email.com" && password == "chris@123") {
                    administrator();
                } else {
                    cout << "Invalid email/password";
                }
                break;

            case 2:
                // Buyer menu
                buyer();
                break;

            case 3:
                exit(0); // Exit program

            default:
                cout << "Please select from the given options ";
        }
    } while (choice != 3);
}

// Function to handle administrator actions
void Shopping::administrator() {
    int choice;
    do {
        // Displaying administrator menu options
        cout << "\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t           Administrator menu             \n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t|         (1 Add the product              |\n";
        cout << "\t\t\t\t|                                         |\n";
        cout << "\t\t\t\t|         (2 Modify the product           |\n";
        cout << "\t\t\t\t|                                         |\n";
        cout << "\t\t\t\t|         (3 Delete the product           |\n";
        cout << "\t\t\t\t|                                         |\n";
        cout << "\t\t\t\t|         (4 Return to main menu          |\n";
        cout << "\t\t\t\t|                                         |\n";
        cout << "\n\t\t\t Please enter your choice ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                editProduct();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                menu(); // Return to main menu
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 4);
}

// Function to handle buyer actions
void Shopping::buyer() {
    int choice;
    do {
        // Displaying buyer menu options
        cout << "\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t           Buyer menu                     \n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t|         (1 Buy product                  |\n";
        cout << "\t\t\t\t|                                         |\n";
        cout << "\t\t\t\t|         (2 return to previous menu      |\n";
        cout << "\t\t\t\t|                                         |\n";
        cout << "\n\t\t\t Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                generateReceipt();
                break;
            case 2:
                menu(); // Return to main menu
                break;
            default:
                cout << "Invalid choice!";
                break;
        }
    } while (choice != 2);
}

// Function to add a product
void Shopping::addProduct() {
    Product product;
    cout << "\n\n\t\t\t Add a new product";
    cout << "\n\n\t Enter product code: ";
    cin >> product.code;
    cout << "\n\n\t Enter Name of the product: ";
    cin >> product.name;
    cout << "\n\n\t Enter Price of the product: ";
    cin >> product.price;
    cout << "\n\n\t Enter Discount on product: ";
    cin >> product.discount;

    FileHandler::writeProduct(product);
    cout << "\n\n\t\t Record inserted!";
}

// Function to edit a product
void Shopping::editProduct() {
    int pkey;
    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code: ";
    cin >> pkey;

    Product product = FileHandler::getProduct(pkey);

    if (product.code == 0) {
        cout << "\n\n Record not found!";
        return;
    }

    cout << "\n\t\t Name of the product: ";
    cin >> product.name;
    cout << "\n\t\t Price: ";
    cin >> product.price;
    cout << "\n\t\t Discount: ";
    cin >> product.discount;

    FileHandler::editProduct(product);
    cout << "\n\n\t\t Product edited successfully!\n";
}

// Function to remove a product
void Shopping::removeProduct() {
    int pkey;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code: ";
    cin >> pkey;

    FileHandler::removeProduct(pkey);
    cout << "\n\n\t\t Product deleted successfully!\n";
}

// Function to list all products
void Shopping::listProducts() {
    cout << "\n\n|_____________________________________________________|\n";
    cout << "\tProNo\t\tName\t\tPrice\n";
    cout << "\n\n|_____________________________________________________|\n";

    ifstream file("database.txt");
    if (!file.is_open()) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    int code;
    string name;
    float price, discount;

    while (file >> code >> name >> price >> discount) {
        cout << "\t" << code << "\t\t" << name << "\t\t" << price << "\n";
    }

    file.close();
}

// Function to generate a receipt
void Shopping::generateReceipt() {
    int arr_codes[100]; // Array to store product codes
    int arr_qty[100];   // Array to store product quantities
    char choice;        // Variable to store user choice for continuing or stopping product entry
    int c = 0;          // Counter for number of products
    float amount = 0;   // Variable to store the total amount for each product
    float disc = 0;     // Variable to store the discounted amount for each product
    float total = 0;    // Variable to store the total amount for all products

    // Display list of products available
    cout << "\n\n\t\t LIST OF PRODUCTS  ";
    listProducts(); // Function to list products
    cout << "\n_________________________________________________\n";
    cout << "\n|                                               |\n";
    cout << "\n|          Please place the order               |\n";
    cout << "\n|                                               |\n";
    cout << "\n_________________________________________________\n";

    // Loop to enter product codes and quantities
    do {
        cout << "\n\nEnter Product code: ";
        cin >> arr_codes[c];
        cout << "\n\nEnter the product quantity: ";
        cin >> arr_qty[c];

        // Check for duplicate product codes
        for (int i = 0; i < c; i++) {
            if (arr_codes[c] == arr_codes[i]) {
                cout << "\n\n Duplicate product code. Please try again!";
                return;
            }
        }
        c++; // Increment the counter for next product entry

        cout << "\n\n Do you want to buy another product? enter 'y' for yes or 'n' for no";
        cin >> choice;

    } while (choice == 'y');

    // Display the receipt header
    cout << "\n\n\t\t___________________________________RECEIPT___________________________________\n";
    cout << "\nProduct No\tProduct Name\tProduct Qty\tPrice\tAmount\tAmount with discount\n";

    // Loop through the products entered to generate the receipt
    for (int i = 0; i < c; i++) {
        // Get product information from the database
        Product product = FileHandler::getProduct(arr_codes[i]);
        // Check if product exists
        if (product.code == 0) {
            cout << "Product with code " << arr_codes[i] << " not found.\n";
            continue;
        }

        // Calculate the total amount for the product
        amount = product.price * arr_qty[i];
        // Calculate the discounted amount for the product
        disc = amount - (amount * product.discount / 100);
        // Increment the total amount for all products
        total += disc;

        // Display product details in the receipt
        cout << product.code << "\t\t" << product.name << "\t\t" << arr_qty[i] << "\t\t" << product.price << "\t" << amount << "\t\t" << disc << "\n";
    }

    // Display total amount in the receipt footer
    cout << "\n\n_______________________________________________________________________";
    cout << "\n Total Amount: " << total << "\n\n";
}
