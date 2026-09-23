# Database Generator in C

## Project Description

It is a command-line synthetic data generator written in C.

The program generates realistic-looking user records for testing and development purposes. The user can specify the number of records to generate, and it automatically creates information such as names, ages, genders, countries, email addresses, and phone numbers.

The generated data is exported to a CSV file that can be opened, inspected, or used as sample data for other applications.

This project is designed as a learning project to practice C programming concepts such as structures, functions, arrays, pointers, random number generation, file handling, modular programming, and Makefiles.

## Problem Statement

Developers often need sample data when testing applications or working with databases.

Creating a large number of records manually is time-consuming and repetitive. This project provides a simple way to automatically generate synthetic user records so that developers can quickly obtain sample data for testing and experimentation.

## Project Goals

The main goals are:

- Generate synthetic user data automatically.
- Allow the user to choose the number of records to generate.
- Generate different types of user information.
- Export generated records to a CSV file.
- Practice structures and functions in C.
- Practice file handling in C.
- Practice random number generation.
- Learn how to organize a C project into multiple source and header files.
- Use a Makefile to build the project.
- Maintain a clean and understandable project structure.

## Current Features

- User-defined number of records.
- Random first and last names.
- Random age generation.
- Random gender selection.
- Random country selection.
- Automatic email generation.
- Random phone number generation.
- Automatically assigned record IDs.
- CSV file generation.
- Modular source code using separate `.c` and `.h` files.
- Building the project using a Makefile.

## How It Works

The program follows a simple process:

1. The user starts `db_generator`.
2. The program asks how many records should be generated.
3. A user record is created for each requested record.
4. Random values are selected for the user fields.
5. The generated record is written to a CSV file.
6. After all records are generated, the program reports the output file.

The generated CSV contains the following fields:

```text
id
name
age
gender
country
email
phone
```

## Project Design

The project is divided into separate modules so that each part of the program has a clear responsibility.

### `main.c`

Responsible for the main program flow.

- Takes the number of records from the user.
- Opens the CSV file.
- Calls the data generation function.
- Calls the CSV export function.
- Closes the file after generation is complete.

### `generator.c`

Responsible for generating synthetic user data.

It generates:

- Names
- Ages
- Genders
- Countries
- Email addresses
- Phone numbers
- Record IDs

### `exporter.c`

Responsible for writing the generated data to the CSV file.

It handles:

- Writing the CSV header.
- Writing individual user records.

### Header Files

The header files in the `include/` directory contain the shared `User` structure and function declarations used by the source files.

## Project Structure

```text
db_generator/
├── src/
│   ├── main.c
│   ├── generator.c
│   └── exporter.c
├── include/
│   ├── generator.h
│   └── exporter.h
├── examples/
├── tests/
├── Makefile
├── README.md
└── .gitignore
```

## Requirements

To build and run DBForge, you need:

- GCC
- GNU Make
- Linux, WSL, or another Unix-like environment

The project is written entirely in C.

## Building the Project

The project uses a Makefile to simplify compilation.

To build the project, run:

```bash
make
```

If the build is successful, an executable named `db_generator` will be created.

To remove the generated executable and object files, run:

```bash
make clean
```

## Running the Program

After building the project, run:

```bash
./db_generator
```

The program will ask how many records you want to generate.

For example:

```text
Database Generator
Enter number of records to generate: 5

Successfully generated 5 records.
Data saved to users.csv
```

The generated data will be saved in:

```text
users.csv
```

## Example Output

Example contents of the generated CSV file:

```csv
id,name,age,gender,country,email,phone
1,Kiara Jain,18,Male,India,kiara.jain1@example.com,7315492202
2,Ananya Verma,28,Female,Japan,ananya.verma2@example.com,7135328306
3,Arjun Kumar,21,Female,Canada,arjun.kumar3@example.com,7769295546
```

The generated values may be different each time the program is executed.

## Future Improvements

Possible future improvements include:

- SQL output support.
- More types of synthetic data.
- Optional random seed support.
- Command-line options.
- Additional validation of generated data.

These features are not part of the current version.

## License

This project is licensed under the MIT License.
