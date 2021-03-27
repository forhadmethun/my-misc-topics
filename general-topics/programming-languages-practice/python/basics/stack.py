class Stack:
    def __init__(self):
        self.stack = []
    def push(self,data):
        self.stack.append(data)
    def peek(self):
        if(self.stack.len > 0):
            return self.stack(0)
    def pop(self):
        return self.stack.pop()
    def printStack(self):
        print (self.stack)

if __name__ == '__main__':
    stack = Stack()
    stack.push(1);
    stack.push("forhad")
    stack.push('A')
    stack.push(99)

    stack.printStack()

    stack.pop()

    stack.printStack()
