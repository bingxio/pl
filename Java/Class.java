
class User {

    private String username;
    private String password;

    static String SEX = "BOY";

    User(String username, String password) {
        this.username = username;
        this.password = password;

        System.out.println("call User class");
    }

    @Override
    public String toString() {
        return "[ username = " + username + ", password = " + password + "]";
    }

    final String getUsername() {
        return username;
    }
}

class People extends User {

    People(String username, String password) {
        super(username, password);

        System.out.println("call people class");
    }
}

public class Class {

    public static void main(String[] args) {

        People people = new People("turaiiao", "12345678");

        System.out.println(people.toString());
        System.out.println(User.SEX);
        System.out.println(people.getUsername());
    }
}
