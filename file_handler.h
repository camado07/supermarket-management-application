#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
#include <string>
#include "product.h" // Include the Product struct definition

class FileHandler {
public:
    // Functions for handling product data
    static void writeProduct(const Product& product); // Write a product to a file
    static void editProduct(const Product& product); // Edit an existing product in the file
    static void removeProduct(int productCode);       // Remove a product from the file
    static Product getProduct(int productCode);       // Get a product from the file by its code
};

#endif // FILE_HANDLER_H
