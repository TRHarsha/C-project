**HOSPITAL DATA BASE PROJECT**
I made a program to take symptoms and give the common disease as output.

This code is written in C++ and is for a medical database system that allows users to add, edit, and delete patient information, including the patient's name, blood group, age.
The last 4 digits of their Aadhaar number acts as a Password to confirm whether he is the owner of the Data. 
It also has a search function to search for a specific patient by their mobile number, and a print function to display all the stored patient information. 
The code uses structures and functions to implement these functionalities.

The program stores the details of the patients in an array of structures named "details". Each structure has the following fields - name, blood group, mobile number, age, and Aadhaar number. 
The program also includes a nested structure "medical_report". I have declared this but have'nt used I have kept it to record the old patient details.

The program has various functions to perform the following tasks:

1. new_patient() function - Adds a new patient to the list by taking the input of details like name, mobile number, blood group, age, and Aadhaar number.
2. search_patient() function - Searches for a patient based on the mobile number and prints their details. It also asks if the user wants to edit or delete the record.
3. edit_opt() function - Edits the details of a patient after confirming their identity using their Aadhaar number.
4. delete_info() function - Deletes the record of a patient after confirming their identity using their Aadhaar number.
5. print_all() function - Prints all the details of patients stored in the program.

