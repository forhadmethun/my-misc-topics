enum Permissions{
  case READ, WRITE, EXECUTE, NONE

  def openDocument(): Unit = {
    if (this == READ) println("Allowed to read")
    else println("Reading not allowed")
  }
}

val permission = Permissions.READ
val readPermission = Permissions.valueOf("READ")

permission.openDocument()
permission.ordinal
Permissions.values


// constructor args
enum PermissionWithBits(bits: Int) {
  case READ extends PermissionWithBits(4)
  case WRITE extends PermissionWithBits(2)
  case EXECUTE extends PermissionWithBits(1)
  case NONE extends PermissionWithBits(0)
}


object PermissionWithBits {
//  def fromBits(bits: Int): PermissionWithBits = //
//  PermissionWithBits.NONE
}
