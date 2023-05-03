#include "Heap.cpp"
#include "std_headers.h"
int main(int argc, char **argv) {
Heap<int> h =  Heap<int>();
h.insert(3);
h.printBST(" ");
h.insert(15);
h.printBST(" ");
h.insert(8);
h.printBST(" ");
h.insert(45);
h.printBST(" ");
h.insert(30);
h.printBST(" ");
h.insert(12);
h.printBST(" ");
h.insert(1);
h.printBST(" ");
h.insert(20);
h.printBST(" ");
h.delMax();
h.printBST(" ");
h.delMax();
h.printBST(" ");
h.delMax();
h.printBST(" ");
h.delMax();
h.printBST(" ");
h.delMax();
h.printBST(" ");
h.delMax();
h.printBST(" ");
h.delMax();
h.printBST(" ");
h.delMax();
h.printBST(" ");
}