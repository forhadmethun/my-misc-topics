object Employee {
  var employeeId = 0
  def getEmployeeId(): Int = {
    employeeId += 1
    employeeId
  }
}

class Employee(val firstName: String, val lastName: String) {
  var eId = Employee.getEmployeeId();
  override def toString = s"Employee(firstName=$firstName, lastName=$lastName, id = ${eId})"
}

var e: Employee = new Employee("forhad", "Hossain")
println(e)
var e2: Employee = new Employee("forhad2", "Hossain2")
println(e)


case class Person(var name: String) {}

var p = Person("Forhad")
var q = Person("Methun")
for(person <- List(p, q)) {
  person match {
    case Person("Forhad") => println("It's forhad")
    case Person("Methun") => println("It's mmm")
  }
}


object BankAccount {
  var accountNo: Int = 5000
  def getAccountNo() : Int = {
    accountNo = accountNo + 1
    accountNo
  }
}

class BankAccount(var clientName: String, var balance: Double, var accountType: String) {
  override def toString = s"BankAccount($clientName, $balance, $accountType, ${BankAccount.getAccountNo()})"
}

println(new BankAccount("Forhad", 500, "savings"))
println(new BankAccount("Forhad", 500, "debit"))