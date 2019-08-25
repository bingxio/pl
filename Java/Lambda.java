import java.util.Arrays;
import java.util.Comparator;

interface ClickListener {
  void onClick(int view);
}

class TextView {
  void setOnClickListener(int view, ClickListener clickListener) {
    clickListener.onClick(view);
  }
}

public class Lambda {
  /**
   * (params) -> expression
   * (params) -> statement
   * (params) -> { statements }
   */
  public static void main(String[] args) {
    var textView = new TextView();

    textView.setOnClickListener(100, new ClickListener() {

      @Override
      public void onClick(int view) {
        System.out.format("%d call click listener before Java 8 \n", view);
      }
    });

    textView.setOnClickListener(200, view ->
      System.out.format("%d call click listener after Java 8 \n", view));

    var list = Arrays.asList(12, "hello", 4.5, false, 666);

    list.forEach(System.out::println);
    list.forEach(i -> {
      if (i instanceof Integer) {
        System.out.format("%d\t", i);
      }
    });

    Greeting greeting = (int a, int b) -> System.out.println(a + b);

    greeting.add(12, 32);

    new Thread(() -> {
      System.out.println("Call on thread...");
    }).start();

    class User {
      private String name;

      private User(String name) {
        this.name = name;
      }

      @Override
      public String toString() {
        return "[ name = " + this.name + " ]";
      }
    }

    var users = Arrays.asList(
      new User("a"),
      new User("c"),
      new User("g"),
      new User("e")
    );

    users.sort((Comparator.comparing(o -> o.name)));

    System.out.println(users);

    int a = 20;
    int b = 30;

    doProcess(a, i -> System.out.println(i + b));

    new Thread(Lambda::printMessage).start();
  }

  @FunctionalInterface
  interface Greeting {
    void add(int a, int b);
  }

  interface Process {
    void process(int i);
  }

  private static void doProcess(int i, Process process) {
    process.process(i);
  }

  private static void printMessage() {
    System.out.println("Hello Lambda In Java !");
  }
}
