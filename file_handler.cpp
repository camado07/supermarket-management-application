#include "file_handler.h"
#include <fstream>
#include <iostream>

// Function to write a product to the database file
void FileHandler::writeProduct(const Product& product) {
    std::ofstream file("database.txt", std::ios::app); // Open file for writing (append mode)
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing.\n"; // Error message if file cannot be opened
        return;
    }
    // Write product information to the file
    file << product.code << " " << product.name << " " << product.price << " " << product.discount << "\n";
    file.close(); // Close the file
}

// Function to edit an existing product in the database file
void FileHandler::editProduct(const Product& product) {
    std::ifstream infile("database.txt"); // Open file for reading
    std::ofstream outfile("temp.txt");    // Open temporary file for writing

    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Error opening file for editing.\n"; // Error message if files cannot be opened
        return;
    }

    int code;
    std::string name;
    float price, discount;

    // Read product information from the database file
    while (infile >> code >> name >> price >> discount) {
        if (code == product.code) { // If product code matches, write edited product information
            outfile << product.code << " " << product.name << " " << product.price << " " << product.discount << "\n";
        } else { // Otherwise, write the original product information
            outfile << code << " " << name << " " << price << " " << discount << "\n";
        }
    }

    infile.close();  // Close input file
    outfile.close(); // Close temporary file

    remove("database.txt"); // Remove original file
    rename("temp.txt", "database.txt"); // Rename temporary file to original file
}

// Function to remove a product from the database file
void FileHandler::removeProduct(int productCode) {
    std::ifstream infile("database.txt"); // Open file for reading
    std::ofstream outfile("temp.txt");    // Open temporary file for writing

    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Error opening file for removing.\n"; // Error message if files cannot be opened
        return;
    }

    int code;
    std::string name;
    float price, discount;

    bool found = false;

    // Read product information from the database file
    while (infile >> code >> name >> price >> discount) {
        if (code == productCode) { // If product with specified code is found, skip writing it to temporary file
            found = true;
            continue;
        }
        // Write all other products to temporary file
        outfile << code << " " << name << " " << price << " " << discount << "\n";
    }

    infile.close();  // Close input file
    outfile.close(); // Close temporary file

    if (!found) {
        std::cerr << "Product with code " << productCode << " not found.\n"; // Error message if product not found
        remove("temp.txt"); // Remove temporary file
        return;
    }

    remove("database.txt"); // Remove original file
    rename("temp.txt", "database.txt"); // Rename temporary file to original file
}

// Function to get a product from the database file by its code
Product FileHandler::getProduct(int productCode) {
    Product product;

    std::ifstream file("database.txt"); // Open file for reading
    if (!file.is_open()) {
        std::cerr << "Error opening file for reading.\n"; // Error message if file cannot be opened
        return product;
    }

    int code;
    std::string name;
    float price, discount;

    // Read product information from the database file
    while (file >> code >> name >> price >> discount) {
        if (code == productCode) { // If product code matches, populate the product struct and break loop
            product.code = code;
            product.name = name;
            product.price = price;
            product.discount = discount;
            break;
        }
    }

    file.close(); // Close the file
    return product; // Return the product
}
