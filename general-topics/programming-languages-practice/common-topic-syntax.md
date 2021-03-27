## printing
```python
print("hello world!")
```
```cpp
//using namespace std;
cout << "hello world!" << endl;
```

```c 
printf("hello world!);
```

```java 
System.out.println("hello world!");
```

```javascript
document.write("hello world!"); 
```



## Data Container

#### Array / List 
```cpp
//array
int adjMat[100][100];

//vector
int array[] = {1, 2, 5,9, 15};
vector<int> vec; 
vector< vector<int> > vvi; 
//methods - 
//push_back(), size(), assign(),
``` 

```java

```
```python
list = []

#methods - 
#append(), insert(), remove(), pop(), clear(), count(), sort(), reverse(), copy(), filter(), map()

dict =	{
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}

thisset = {"apple", "banana", "cherry"}
thistuple = ("apple", "banana", "cherry")

```

#### Stack


#### Queue / Priority Queue
```java 
//import java.util.Queue
//import java.util.LinkedList

Queue<Integer> q = new LinkedList<>(); 
PriorityQueue<Integer> qp = new PriorityQueue<>(); 
//methods - 
//add(), peek(), element(), remove(), poll(), size()
```

```python
# from collections import deque
list = ["a","b","c"]
deq = deque(list)
print(deq)
#methods-
#append(), appendleft(), pop(), popleft(), clear(), count(), 

```

```cpp
  priority_queue< pair<int, pair<int, int> > edgeList; 
  edgeList.push(make_pair(-w, pair<int,int>(u,v)));

  //methods - 
  // top(), pop() 
    
  queue<int> q;
  //methods - empty(), front(), push(), pop()
  // 
```

#### Linked List 


## Collection/ Library 
#### sorting 

#### searching


## Constants

## Enum 
```python
from enum import Enum
class Color(Enum):
    RED = 1
    BLUE = 2
    GREEN = 3
print(Color.RED)
#run with /usr/bin/python2.7

```
## Iterate 

```cpp 
for (auto i = vec.begin(); i!= vec.end() ; i++){
    cout << *i << endl;
    // i-> first, i->second ( for pair)
}
```

## Comon Data Type 
----------------------------------------------------------------------------------------------
cpp                             |            java                             | python
----------------------------------------------------------------------------------------------
int, double, float,             |             same as cpp                     |   no type   
char                            |
----------------------------------------------------------------------------------------------
                                |    Integer, Float, Double, Character        |
-----------------------------------------------------------------------------------------------
pair<int, int>                  |                                             |
-----------------------------------------------------------------------------------------------
priority_queue<int, int>        | PriorityQueue<Integer> pq                         
--------------------------------------------------------------------------------------------------
template <class T>              |   class Test<T>{ 
T Large(T n1, T n2)             |     T Large(T n1, Tn2){ 
{                               |
	return (n1 > n2) ? n1 : n2;   |         return (n1>n2)? n1: n2;
}                               |  
                                |    }}
template<class T>
class Graph{}  
------------------------------------------------------------------------
(map)                           |
methods -                       |  
at(), find(), count(), erase(), |get(), getOrDefault(), clear() 
size(), empty(), begin(),end(), |size(),isEmpty(), remove(), 
// map::insert({key, element})  |put(),
//if exisits
if(visited.find(r) != 
          visited.end()){}
------------------------------------------------------------------------
                                |
priority_queue                    PriorityQueue                                
//3 parameters
//<pair<int,T>,vector<T>,
//greater<pair<int,T>>>pq;
----------------------------------------------------------------------------------------------------------------------------
set                                |
                             |
                                |
                                |
                                |
                                |
                          
------------------------------------------------------------------------


