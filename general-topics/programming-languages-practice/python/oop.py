import random


class Car:
    # protected wheel = 1;
    wheel = 4
    engine = "china"
    steering = True
    drivingTye = "Auto"
    color = "red"
    def __init__(self):
        print("inside Car class")
        self.__updateSoftware()
        self.__password = 1234

    def drive(self):
        print('driving')
    def __updateSoftware(self):
        print('updating software')
    def getPassword(self):
        return self.__password

    def setPassword(self, password):
        self.__password = password
    def horn(self):
        print("horn from Car class")
    def horn(self, noOfHorns):
        print("horn called " + noOfHorns)
class Zeep(Car):
    # self.wheel = 2;
    def __init__(self):
        print("inside Zeep class")
        self.drive()

    def printSqurateOfHundradeNumbers(self):
        for i in range(0,100):
            print(i*i)
    def validateUser(self, username, passwod):
        # we need to call database if user exists or not
        # if(bool(random.getrandbits(1))):
        #     print("valid user")
        # else:
        #     print("not valid")
        if(username == "admin" and passwod=="123"):
            return True
        else:
            return False
    def horn(self):
        print("horn from Zeep")

class BMW(Car):
    def __init__(self):
        print("from bmw")
        self.color = "black"
    def horn(self):
        print("horn from BMW")

redcar = Car()
redcar.drive()

blueCar = Car()
blueCar.drive()

#blueCar.__password
print(blueCar.getPassword())

#blueCar.__password = "myPassword"


blueCar.setPassword("myPassword")
print(blueCar.getPassword())
print("---Zip----")

myZeep = Zeep()
# myZeep.printSqurateOfHundradeNumbers()
#user: admin
#password: 123
print(myZeep.validateUser("admin", "123"))

# myZeep.color = "red"
print(myZeep.color)
print(myZeep.color)
myBMW = BMW()
print(myBMW.color)

print("=====================")
# car -> horn
myZeep.horn()
myBMW.horn()
# myBMW.horn(2)


#redcar.__updateSoftware() #  not accesible from object.





# Car zeep = new Zeep()
# zeep.horn()
#
# Car bmw = new BMW()
# bmw.horn()








class Bike:
    wheel = 2
    color = ""
    gears = 2

    # def method1(self):
class Bike100CC(Bike):
    def __init__(self):
        self.color  = "blue"

# class Bike100CCElectric(Bike100CC):
    # def





