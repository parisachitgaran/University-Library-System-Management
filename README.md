# University-Library-System-Management
The program is in C ++ language. This system interacts with the university management system. This project has access to the files of the university management system.



Class Book:
This class, the father class and the book and magazine classes and thesis classes of his child
are . Inside this class, the setter and getter functions are written.
These classes provide information about book, magazine, and dissertation entities
They have.

Class Person:
This class is the father class and the librarian and member classes are the child classes.
Inside this class, the setter and getter functions are written.
These classes contain information about librarian and member entities.
Inside the console, first all the information is read from all the files and dumped into the corresponding vector
May be. After each operation, the information in the vector is updated and written in the file
May be. This feature allows the programmer to easily go anywhere from the console to the whole
Access information .: Menu
At the beginning of the program, the main menu is displayed, which asks the user to specify
Is a librarian or a member. By entering the username and password (national code) permission to enter the program
It will be given.
If the user logs in as a librarian, permission to perform all activities, including adding a member
New and edit and delete and search and report and access the loan field, given to him
May be.
But if he enters as a member, he is only allowed to register a loan and search and report articles
(Books, magazines, dissertations) are given.
 
 
Getdata:
A unique function is written for each entity to get information from the user
And have write in the corresponding file.
: Edit
A unique function is written for each entity to get information from the user
Edit it specifically and then write it in the file.
: Delete
A unique function is written for each entity to get the desired ID from the user
Delete all relevant information from the file.
 
 Report:
For each entity a unique function is written to read the information from the file and to
Display the categorized form to the user .: Search
A unique function is written for each entity to get the desired ID from the user
All relevant information is read from the file and displayed to the user in a categorized manner
to be given.
 
 Borrow:
 Borrow is a separate class that has the fields of text ID, member ID, and loan date
Has a delivery date.
Define the functions of registration, editing, deletion, search and reporting for the existence of the loan
Has been.
By registering a loan, the text balance is reduced and added to the text balance by deleting.
The edit function allows the user to extend the delivery date. In the search function by grabbing
The text ID or member ID of the loan information is displayed.
Reporting also by taking the delivery date from the user of all loans whose delivery date is with
The date entered is displayed
