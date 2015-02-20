# Arabian Nights Problem

### Class MagicLamp

File '''MagicLamp.h''' contains the interface and a few small functions.

File '''MagicLamp.cpp''' contains the implementations of the functions not defined in the header '''.h''' file. Note how the destructor destroys all the genies and the demon when the lamp itself is destroyed (the only magic lamp is created in the stack of the '''main''' function - below - and its destructor is called at the end of the '''main''' function, when its stack is released).

### Class Genie

Class Genie defines the basic behaviour for all genies. The whole class is defined in the header file '''Genie.h'''. Notice the two versions (one is commented out) of the output operator.
Note that the output operator by itself if not capable of handling the polymorphic access used in the '''main''' function (because it is used as an argument). For it to work correctly, we defined an abstract method '''dumpTo''' that each class must implement. This method will be correctly called in polymorphic situations.
Note also that, since Genie is a class whose methods are to be redefined by subclasses and whose pointers will only point to subclass instances, needs a virtual destructor: in this was, the delete operator will look at the actual type of the object (instead of using the type of the pointer), allowing the correct destructor (that of the object's class and not the pointer's) to be called.

### Class FriendlyGenie

A friendly genie is almost like a general genie (it differs in the output messages). Since it is a small class, it is completely defined in the header file '''FriendlyGenie.h'''.

### Class GrumpyGenie

Like the other previous genie classes, this one is also very small and completely defined in the header file '''GrumpyGenie.h'''.

### Class RecyclableDemon

The '''RecyclableDemon''' is a genie that implements some of the control methods in a special way (but still adheres to the template method defined by class Genie). Like the other small classes, it is completely define in '''RecyclableDemon.h'''.

### Main Function

In this case, the '''main''' is, straightforward. Some aspects merit attention: since the magic lamp will not be used anywhere else, it is a good ideia to create in within the context of the '''main''' function, i.e., on its stack, and not on the heap (as would be the case if it were created with the "new" operator).

## Compiling and Running

The following commands are needed to compile the application (note that it suffices to compile the '''.cpp''' files).

'''
g++ -ansi -pedantic -Wall -c MagicLamp.cpp
g++ -ansi -pedantic -Wall -c main.cpp
g++ -o an MagicLamp.o main.o
 '''
 
 The result of running the an application is the following:
 
 '''
 Grumpy genie has a wish to grant.
 Friendly genie has granted 0 wishes and still has 3 to grant.
 Grumpy genie has a wish to grant.
 Friendly genie has granted 0 wishes and still has 5 to grant.
 Recyclable demon has granted 0 wishes.
 Grumpy genie has granted a wish.
 Friendly genie has granted 1 wishes and still has 2 to grant.
 Grumpy genie has granted a wish.
 Friendly genie has granted 1 wishes and still has 4 to grant.
 Recyclable demon has granted 1 wishes.
 Grumpy genie has granted a wish.
 Friendly genie has granted 2 wishes and still has 1 to grant.
 Grumpy genie has granted a wish.
 Friendly genie has granted 2 wishes and still has 3 to grant.
 Recyclable demon has granted 2 wishes.
 Grumpy genie has a wish to grant.
 '''
