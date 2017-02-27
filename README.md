# Hanoi Towers (C)

Implementation of the Hanoi Towers game in C. 

<img src="http://i.imgur.com/XAJimpd.png" />

## Supported outputs:

* Console
* File (requires file name and optional file writing mode)

## Program parameters

All parameters are optional and can be entered at any order. Repeating parameters will result in the latest parameter.

* "-d x" to specify the amount of discs on the starting tower. (4 by default)
* "-f x" to specify the name of the file where the output will be written. (Prints to console if empty)
* "-o w/ap" to specify the file writing mode. "w" will clear any previous contents on the file. "ap" will append to the end of the file. ("ap" by default)

## Algorithm

The algorithm implemented to solve the game is based on the recursive complexity of the problem.

The key to solving the game recursively is to recognize that it can be broken down into a collection of smaller sub-problems to each of which that same general solving procedure that we are seeking applies, and the total solution is then found in some simple way from those sub-problems' solutions. Therefore, each of those sub-problems being "smaller" guarantees the base case will eventually be reached.

The main recursive function is defined as : `Hanoi(amount, originTower, destinationTower, auxiliarTower)`

### Recursivity

Whenever there's only 1 disc to move, a basic operation is realized to move it from the original tower to the destination tower.
* Move(origin, destination)

If the amount of discs to move is greater than 1, the function recursively calls itself on a smaller sub-problem (n-1).
* Hanoi(n - 1, origin, destination, auxiliar)
* Move(origin, destination)
* Hanoi(n - 1, auxiliar, destination, origin)

## Visualization

The program prints the three towers and the discs they contain using only text.

A text line is printed before displaying the towers containing the next information :
* Move count
* Depth of recursion
* Size of the moved disc
* Origin tower
* Destination tower

Next are the three towers, separated by spaces. The center of the tower is marked by the symbol `|`.
Dots represent empty spaces, letters represent the size of the disc in alphabetic order. The amount of letters also represent the size of the disc (example, 'BB|BB' means the size of the disc is 2, because there's 2 'B's on each side and also because B corresponds to the 2nd letter of the alphabet.

Lastly, a base line is printed that holds together all 3 towers and marks the end of the movement.

## Memory management

Dynamic memory is allocated at the start of the game to hold all levels of the three towers and also allocated during the game to save each movement without previously knowing the total amount of moves.

Each tower holds a pointer to an array of `int`s that represent the tower levels. The size of the array is the starting amount of discs.

A pointer to an array of Movements is defined and the memory space of such array is reallocated and enlarged by each movement. Each movement struct holds all the information of a specified movement, including the move count, recursion depth, message printed, status of the three towers and their levels and a pair of pointers to the previous and next movements.

## Modularity

The project is separated in several files, all of them with their own header file which includes all function prototypes and a brief explanation of it, the parameters it takes as input (if any) and the returned output (if any).

A global header file includes all the project header files and also the standard headers (stdlib, stdio, time, string, etc...), with some extra stuff and typedefs such as `bool` which make the project more readable.

* Main.c : Starting point for the application and main algorithm definition
* IO.c : Handles user input and the specificed output (console or file)
* Towers.c : Handles the towers and the movement of discs
* Historial.c : Handles the saving of movements and the dynamic memory allocation of the historial

An extra pair of header files define the Tower and Movement structures.

### Tower

The Tower structure holds all the information of a single tower, including :
* Height
* Role (start, destination or auxiliar)
* Levels

### Movement

The Movement structure holds all the information of a single move, including :
* Move count
* Message
* All 3 towers
* Pointers to Next and Previous movements (NULL if none)
