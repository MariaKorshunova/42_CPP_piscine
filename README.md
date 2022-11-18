# CPP_piscine_42

[Module 00. Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuf](#Module00)
[Module 01.Memory allocation, pointers to members, references, switch statement](#Module01)

<a name="Module00"></a> 
## Module 00. Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuf

### Exercise 00: Megaphone

Just to make sure that everybody is awake, write a program that behaves as follows:

```
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

### Exercise 01: My Awesome PhoneBook

Welcome to the 80s and their unbelievable technology! Write a program that behaves
like a crappy awesome phonebook software.


You have to implement two classes:
* PhoneBook
* It has an array of contacts.
* It can store a maximum of 8 contacts. If the user tries to add a 9th contact,
replace the oldest one by the new one.

* Please note that dynamic allocation is forbidden.
* Contact
* Stands for a phonebook contact.

In your code, the phonebook must be instantiated as an instance of the PhoneBook
class. Same thing for the contacts. Each one of them must be instantiated as an instance
of the Contact class. You’re free to design the classes as you like but keep in mind that
anything that will always be used inside a class is private, and that anything that can be
used outside a class is public.
Don’t forget to watch the intranet videos.


On program start-up, the phonebook is empty and the user is prompted to enter one
of three commands. The program only accepts ADD, SEARCH and EXIT.

**ADD: save a new contact**

* If the user enters this command, they are prompted to input the information
of the new contact one field at a time. Once all the fields have been completed,
add the contact to the phonebook.
* The contact fields are: first name, last name, nickname, phone number, and
darkest secret. A saved contact can’t have empty fields.

**SEARCH: display a specific contact**
* Display the saved contacts as a list of 4 columns: index, first name, last
name and nickname.
* Each column must be 10 characters wide. A pipe character (’|’) separates
them. The text must be right-aligned. If the text is longer than the column,
it must be truncated and the last displayable character must be replaced by a
dot (’.’).
* Then, prompt the user again for the index of the entry to display. If the index
is out of range or wrong, define a relevant behavior. Otherwise, display the
contact information, one field per line.

**EXIT**
* The program quits and the contacts are lost forever!
* Any other input is discarded.
Once a command has been correctly executed, the program waits for another one. It
stops when the user inputs EXIT.
Give a relevant name to your executable.

### Exercise 02: My Awesome PhoneBook

You start to recreate the Account.cpp file. In only a few minutes, you code a few lines of pure awesome C++. After a couple of failed compilations, your program passes
the tests. Its output matches perfectly the one saved in the log file (except for the timestamps which will obviously differ since the tests saved in the log file were run before you were hired).

<a name="Module01"></a> 
## Module 01.Memory allocation, pointers to members, references, switch statement

### Exercise 00: BraiiiiiiinnnzzzZ

First, implement a Zombie class. It has a string private attribute `name`.

Add a member function `void announce( void );` to the Zombie class. Zombies
announce themselves as follows:

```
<name>: BraiiiiiiinnnzzzZ...
```

Don’t print the angle brackets (< and >). For a zombie named Foo, the message
would be:

```
Foo: BraiiiiiiinnnzzzZ...
```

Then, implement the two following functions:
* `Zombie* newZombie( std::string name );`

It creates a zombie, name it, and return it so you can use it outside of the function
scope.

* `void randomChump( std::string name );`

It creates a zombie, name it, and the zombie announces itself.
Now, what is the actual point of the exercise? You have to determine in what case
it’s better to allocate the zombies on the stack or heap.
Zombies must be destroyed when you don’t need them anymore. The destructor must
print a message with the name of the zombie for debugging purposes.