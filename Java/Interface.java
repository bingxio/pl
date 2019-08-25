
interface UserModel {
  User login(User user);
  User create(User user);
}

class UserModelImp implements UserModel {

  @Override
  public User login(User user) {
    return user;
  }

  @Override
  public User create(User user) {
    return user;
  }
}

public class Interface {

  public static void main(String[] args) {
    var userModelImp = new UserModelImp();

    var lily = new User("lily", "12345678");
    var frank = new User("frank", "12345678");

    System.out.println(userModelImp.login(lily));
    System.out.println(userModelImp.create(frank));
  }
}
