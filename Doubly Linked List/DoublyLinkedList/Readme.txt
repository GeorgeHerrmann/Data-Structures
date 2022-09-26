Name: George Herrmann

Provides an implementation of a DoublyLinkedList as well as a driver class and some utility methods for it.

To compile:
    - Type make into the console
To run:
    - Type ./main [FILENAME]
        Where filename is the desired input file
To clean
    - Type make clean into the console

Function Discussions:

DeleteSubsection:

lower = lowerbound, upper = upperbound
NodeType<T> *it = head;
while (*it->data < lower) //O(n)
    it = it->next;

while (*it->data < upper) //O(n)
    deleteItem(it->data) //O(n) (generally)

My DeleteSubsection function is O(n^2) because the second while loop iterates through n number of items
in the list and deleteItem is generally O(n) (except for first or only item cases) and because they are
nested, the function is O(n^2). While the function could have been made linear (O(n)) by manually deleting
the desired node inside of DeleteSubsection, it is far simpler to let deleteItem handle it, even if it
increases the time complexity.

Mode:

NodeType<T> *it = head;
int counter = 0, modeCounter = 0;
T checkVal = it->data, mode = it->data;

for (int i = 0; i < length; i++) { //O(n)
    if (it->data == checkVal) {
        counter++; //O(1)
    }
    if (it->next == NULL || it->data != checkVal) {
        if (counter > modeCounter) {
            modeCounter = counter; //O(1)
            mode = it->back->data; //O(1)
        }
        checkVal = it->data; //O(1)
        counter = 1;
    }
    it = it->next; //O(1)
}

return mode;

My Mode function is linear O(n) because the outer for loop iterates through n number of items in the list
and all other operations are constant time. I needed a way to check all items in the list one at a time,
so an O(n) sorting method worked best. Although a binary sort is O(log(n)), it would have been more complex
to compare the values to get the mode, therefore a linear sort was more practical.

SwapAlternate:

NodeType<T> *it = head;
while (it != NULL && it->next != NULL) { //O(n)
    it->next->back = it->back; //ALL POINTER OPERATIONS ARE O(1) HERE
    it->back = it->next;
    it->next = it->next->next;
    it->back->next = it;
    if (it->back->back == NULL) {
        head = it->back;
    } else {
        it->back->back->next = it->back;
    }
    if (it->next != NULL) {
        it->next->back = it;
    }
    it = it->next;
}

My SwapAlternate function is linear O(n) because the outer while loop will iterate n number of items in the list,
all other operations are constant time. Because I only need to arrange pointer values for each Node, I only need to iterate
through the list once and simply rearrange pointers in the appropriate way. Therefore this function is O(n) in time complexity.
