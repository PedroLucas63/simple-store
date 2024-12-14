# A Simple Store :shopping_cart:

[![Download](https://img.shields.io/badge/Download-Releases-brightgreen)](https://github.com/PedroLucas63/simple-store/releases)

A simple university project demonstrating basic functionalities of a store system, with a focus on testing and logging.

## Table of Contents
- [Introduction](#introduction-rocket)
- [Features](#features-star)
- [How to Build](#how-to-build-gear)
  - [Clone the Repository](#git-clone)
  - [Build with CMake](#cmake-build)
  - [Run Tests](#cmake-test)
- [Contribution](#contribution-handshake)
- [License](#license-paper)
- [Contact](#contact-mail)

## Introduction :rocket:

This project was developed as a university activity to practice testing and logging. It implements a simple store system consisting of the following main classes:

- **Product**: Represents an item with attributes `id`, `name`, and `price`. The `id` is inherited from the base class `Entity`.
- **Catalog**: Manages a collection of products. It allows adding, removing, updating, and retrieving products (either by ID or as a list).
- **Order**: Represents a customer's purchase. It inherits from `Entity` (and therefore has an `id`) and includes `clientName`, `totalPrice`, and a map where the key is the product and the value is its quantity. Orders receive a **10% discount** for purchases exceeding $100.

To coordinate these components, the `AppController` class was implemented as a **singleton**. It handles:
- Managing the catalog.
- Storing and managing a list of orders.
- Providing operations to add/remove products, search by ID, list all products, and manage orders.

This activity focused on:
1. **Unit and Integration Testing**: Using Google Test to validate `Product`, `Order`, and `Catalog`.
2. **Logging**: Using **spdlog** to log operations performed by the `AppController`.

## Features :star:

- Create and manage a catalog of products.
- Add, update, remove, and search for products by ID.
- Create orders with automatic discounts for eligible purchases.
- Comprehensive logging of store operations.
- Unit and integration testing for core functionalities.

## How to Build :gear:

### Clone the Repository

```bash
git clone https://github.com/PedroLucas63/simple-store.git
cd simple-store
```

### Build with CMake

```bash
cmake -S . -B build
cmake --build build
```

### Run Tests

```bash
ctest --test-dir build --output-on-failure
```

Unit and integration tests are implemented using **Google Test**.

## Contribution :handshake:

Contributions are welcome! Feel free to fork the project, make your changes, and submit a pull request.

## License :page_facing_up:

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Contact :mail:

Made with ❤️ by Pedro Lucas  
Feel free to reach out via [pedrolucas.jsrn@gmail.com](mailto:pedrolucas.jsrn@gmail.com).