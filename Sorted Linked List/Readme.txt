Name: George Herrmann
UGA ID: 811-269-387
UGA Email: gvh12771@uga.edu

To compile:
    - Type make into standard input
To run:
    - Type ./main [FILENAME] where [FILENAME] is the text file you'd like to input.
To clean:
    - Type make clean into standard input

MergeFunction:

My MergeFunction uses my currently existing searchItem and insertItem functions.

Pseudocode:
bool duplicate = false;
list2 = the second list that is being merged with the current one
for (all elements in list2) //this is checking for duplicates
    search(all elements in this list)
    if (search != -1) //signifies a duplicate was found
        duplicate = true
if (!duplicate)
    for (all elements in list2) //this is now adding all elements of list2 to this list
        insert(list2 elements)

Because my search and insert functions are O(n) and they are each nested in a for loop of O(n)
the complexity of my MergeFunction is O(n^2). Though I likely could've gotten it to O(nlogn),
I didn't have the time.

DeleteAlternateNodes:

Pseudocode:

for (int i; i < length(); i++)
    if (i%2==0) // meaning alternate node
        delete(the node at this spot)

My delete function is O(n) (or sometimes O(1) under special cases and the for loop surrounding it is O(n)
the complexity of my DeleteAlternateNodes function is O(n^2). I am just including the overall aspects of my functions
complexity, though there is more code involved.

FindCommonElements:

Pseudocode

for (All items in list 2)
    search(all elements in this list)
    if (search != -1) //signifies a duplicate found
         delete(node at this index)

My delete function is generally O(n) and the outer loop is also O(n) so the complexity of this function is O(n^2).
Again there is more code, but I am just including baseline stuff.
