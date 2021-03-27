"""
Four Collection data types in Python.
1. List
2. Tuple(immutable)
3. Set(unordered, unindexed)
4. Dictionary(unordered, changeable & indexed)
"""
thelist = ["apple","banana","cherry"]
print(thelist)
print("======================")
for x in thelist:
    print(x)
print("========================")
if "apple" in thelist:
    print("Apple is in fruit list")    
#thelist.append("element")
#thelist.insert(1,"orange")
#thelist.remove("banana")
#thelist.pop()
# pop(pos) - here position is optional...
#del thelist
#thelist.clear()
#thelist = list((list items))

thetuple = ("apple","banana","cherry")
#almost everything like list except that tupe is immutable


thelist.remove("banana")
print("========================")

print(thelist)

print("========================")

print(thelist.index("cherry"))
# thelist.


def my_func(e):
    return len(e)
def list_methods_test():
    cars = [ "forad", "bmw", "volvo"]
    #sort method
    #list.sort(reverse = True|False, key = myFunc)
    cars.sort()
    cars.sort(reverse = True, key = my_func)
    print(cars)

    #reverse method
    cars.reverse() 

    #extend an array with annother array
    oldcars = ["zeep", "oldzeep"]
    cars.extend(oldcars)
    #can be extend with tuple

    #count - how many times a value exists
    print(cars.count("zeep"))

    #copy one array to another value
    my_facinating_cars = cars.copy()





    

# if __name__ == "__main__":
list_methods_test()
