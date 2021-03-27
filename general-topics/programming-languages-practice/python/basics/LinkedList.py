import collections


class Node:
    def __init__(self, data = None):
        self.data = data;
        self.next = None
class LinkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        temp = self.head;
        while temp is not None:
            print temp.data
            temp = temp.next

    def insert(self,data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

def method():
    ll = LinkedList()
    ll.head = Node("Mon")

    e2 = Node("Tue")
    e3 = Node("Thurs")

    ll.head.next = e2
    e2.next = e3

    ll.printList()
    print("====================")
    ll.insert("Wed")
    ll.printList()

    print("====================")

    # print(LinkedList.__doc__)
    # LinkedList.__doc__

    a = [1, 2, "hello", "forhad"]
# print a
    while a:
        print a
        a.pop()
if __name__ == '__main__':
    # method()
    l = []
    l.append(1)
    l.append(5)
    l.append(7)
    l.append(5)

    l.sort()

    print l
    print "================="
    dic = {"1": {"forhad": "great"}, }
    print dic

    collections.ChainMap();




