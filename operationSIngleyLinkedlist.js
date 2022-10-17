const SinglyLinkedList = require("./singlyLinkedList");

let sll = new SinglyLinkedList();
sll.insertAtbeginning(5);
sll.insertAtbeginning(6);
sll.insertAtbeginning(10);
sll.insertAtend(3);
sll.insertAtend(7)
sll.insertAtend(9)
sll.printList();
sll.search(5);
sll.search(3)
sll.search(9)
sll.search(7)
sll.showSize()
sll.deletedAtEnd()
sll.deletedAtEnd()
sll.deleteAtbeginning()
sll.deleteAtPosition(4)

sll.printList();