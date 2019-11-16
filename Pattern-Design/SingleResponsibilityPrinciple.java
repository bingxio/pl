package app;

/**
 * 单一职责原则 (SRP -> Single Responsibility Principle)
 * 
 * 一个类只负责一个功能领域中的相应职责，或者可以定义为：就一个类而言，应该只有一个引起它变化的原因
 */
public class App {

  public static void main(String args[]) throws Exception {
    /**
     * User
     */
    IUserInformation userInfo = new UserInformationImplement();

    IUserBusinessObject iUserBusinessObject = (IUserBusinessObject) userInfo;
    iUserBusinessObject.setUserId("2389426034382634");

    IUserBusinessLogic iUserBusinessLogic = (IUserBusinessLogic) userInfo;

    System.out.println(iUserBusinessObject.getUserId());

    if (iUserBusinessLogic.deleteUser(iUserBusinessObject)) {
      System.out.println("Delete Success.");
    }
    /**
     * Phone
     */
    PhoneImplement phoneImplement = new PhoneImplement();

    phoneImplement.dial("12345678998");
  }
}

/**
 * User
 */
interface IUserBusinessObject {
  boolean setUserId(String userId);
  String getUserId();
}

interface IUserBusinessLogic {
  boolean deleteUser(IUserBusinessObject iUserBusinessObject);
}

interface IUserManager {
  boolean changeUserPassword(String userId, String password);
  boolean changeUserId(String userId);
  boolean changeUserOfficeAddress(String userId, String officeAddress);
}

interface IUserInformation extends IUserBusinessObject, IUserBusinessLogic, IUserManager {}

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

  @Override
  public boolean changeUserPassword(String userId, String password) {
    return false;
  }

  @Override
  public boolean changeUserId(String userId) {
    this.userId = userId;
    return true;
  }

  @Override
  public boolean changeUserOfficeAddress(String userId, String officeAddress) {
    return false;
  }
}

/**
 * Phone
 */
interface IConnectionManager {
  void dial(String phoneNumber);
  void hangup();
}

interface IDataTransfer {
  void dataTransfer(IConnectionManager iConnectionManager);
}

class PhoneImplement implements IConnectionManager, IDataTransfer {

  @Override
  public void dataTransfer(IConnectionManager iConnectionManager) {}

  @Override
  public void dial(String phoneNumber) {
    System.out.println("Call phont to: " + phoneNumber);
  }

  @Override
  public void hangup() {
    System.out.println("HangUp..");
  }
}
