# Supermarket Management Application

This is a simple console-based application for managing a supermarket. It allows administrators to add, edit, and remove products from the inventory, and buyers to purchase products and generate receipts.

---

## Concepts Used

This application utilizes the following programming concepts and techniques:

- **Object-Oriented Programming (OOP):** The code is structured using classes and objects to encapsulate related data and behaviors. Methods within the `Shopping` class represent the actions that can be performed in the supermarket application, such as adding products, generating receipts, etc.

- **File Handling:** The application reads from and writes to a file (`database.txt`) to manage the inventory of products. The `FileHandler` class encapsulates the functionality related to file operations, such as writing, reading, editing, and removing products from the file.

- **Input/Output (I/O):** The application interacts with the user through the console using input/output operations. It prompts the user to input choices, product details, and other relevant information using `cin` and displays messages using `cout`.

- **Control Structures:** The code uses control structures such as loops (`while`, `do-while`) and conditional statements (`if`, `switch`) to control the flow of execution based on different conditions and user choices.

- **Data Structures:** The application uses data structures such as arrays to store and manipulate product codes and quantities entered by the user. Additionally, the `Product` struct is used to represent the details of each product, encapsulating related data into a single entity.

- **Modularity and Encapsulation:** The code is organized into separate files to promote modularity and encapsulation. Each class (`Shopping`, `FileHandler`) encapsulates related functionalities, making the code easier to understand and maintain.

- **Error Handling:** Basic error handling is implemented to handle cases such as file opening errors. The application provides feedback to the user in case of invalid input or errors encountered during file operations.

---

## Features

- **Administrator Functions:**
    - Add new products to the inventory.
    - Modify existing product details.
    - Delete products from the inventory.
    - Return to the main menu.

- **Buyer Functions:**
    - Purchase products and generate receipts.
    - Return to the main menu.

## Usage

- **Main Menu:**
    - Select "Administrator" to login as an administrator.
    - Select "Buyer" to login as a buyer.
    - Select "Exit" to quit the application.

- **Administrator Menu:**
    - Select "Add the product" to add a new product to the inventory.
    - Select "Modify the product" to edit existing product details.
    - Select "Delete the product" to remove a product from the inventory.
    - Select "Return to main menu" to go back to the main menu.

- **Buyer Menu:**
    - Select "Buy product" to purchase products and generate a receipt.
    - Select "Return to previous menu" to go back to the main menu.

## File Structure

- `main.cpp`: Entry point of the application.
- `shopping.h`, `shopping.cpp`: Class and method definitions for shopping functionality.
- `file_handler.h`, `file_handler.cpp`: Class and method definitions for file operations.
- `product.h`: Struct definition for product details.
- `database.txt`: File storing the product inventory.

