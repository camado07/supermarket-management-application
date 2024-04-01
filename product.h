#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

// Define a structure for representing a product
struct Product {
    int code;           // Unique identifier for the product
    float price;        // Price of the product
    float discount;     // Discount percentage applicable to the product
    std::string name;   // Name of the product
};

#endif // PRODUCT_H
