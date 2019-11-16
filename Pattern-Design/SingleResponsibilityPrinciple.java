package app;

/**
 * 单一职责原则 (SRP -> Single Responsibility Principle)
 * 
 * 一个类只负责一个功能领域中的相应职责，或者可以定义为：就一个类而言，应该只有一个引起它变化的原因
 */
public class App {

  public static void main(String args[]) throws Exception {
    IUserInformation userInfo = new UserInformationImplement();

    IUserBusinessObject iUserBusinessObject = (IUserBusinessObject) userInfo;
    iUserBusinessObject.setUserId("2389426034382634");

    IUserBusinessLogic iUserBusinessLogic = (IUserBusinessLogic) userInfo;

    System.out.println(iUserBusinessObject.getUserId());

    if (iUserBusinessLogic.deleteUser(iUserBusinessObject)) {
      System.out.println("Delete Success.");
    }
  }
}

interface IUserBusinessObject {
  boolean setUserId(String userId);
  String getUserId();
}

interface IUserBusinessLogic {
  boolean deleteUser(IUserBusinessObject iUserBusinessObject);
}

interface IUserInformation extends IUserBusinessObject, IUserBusinessLogic {}

class UserInformationImplement implements IUserInformation {
  String userId;

  @Override
  public boolean setUserId(String userId) {
    this.userId = userId;
    return true;
  }

  @Override
  public String getUserId() {
    return userId;
  }

  @Override
  public boolean deleteUser(IUserBusinessObject iUserBo) {
    return true;
  }
}
