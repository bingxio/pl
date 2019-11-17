package app;

import java.util.ArrayList;

/**
 * Lambda tutorial in Java 8.
 * 
 * @author Turaiiao
 */
public class App {

  public static void main(final String[] args) {
    /**
     * Use lambda expression to create new thread.
     */
    new Thread(() -> {
      // There is Runnable body and it have not parameters.
      // We can write as this `() -> <statements...>`.
      System.out.println("Running in a new thread...");
    }).start();
    /**
     * Use lambda expression with interface statement.
     * 
     * Function not have parameters.
     * 
     * (<parameter...>) -> { <statements... | expression...> } | <statement> | <expression>
     */
    final User user = (String username) -> System.out.println("Do login -> " + username);
    // Must call method only one.
    user.login("turaiiao");
    /**
     * A new way to use click listener in android application developer.
     */
    new ButtonView().setOnClickListener(200, view -> {
      if (view != 0) {
        System.out.format("%d called click listener. \n", view);
      }
    });

    /**
     * Use standard library as lambda expression.
     */
    ArrayList<Integer> arr = new ArrayList<Integer>();

    for (int i = 0; i < 20; i ++) {
      arr.add(i);
    }

    arr.forEach(i -> {
      if (i % 2 == 0) {
        System.out.print(i + " ");
      }
    });
    /**
     * Use lambda expression on function parameter.
     */
    doLoginWithFunction((String username) -> System.out.println("Try login to: " + username));
  }

  /**
   * Add `@FunctionalInterface` header to interface defintine.
   */
  @FunctionalInterface interface User {
    // If we want to use as lambda expression that there must have only one method.
    void login(String username);
  }

  interface ClickListener {
    void onClick(int view);
  }

  static class ButtonView {
    void setOnClickListener(int view, ClickListener clickListener) {
      clickListener.onClick(view);
    }
  }

  static void doLoginWithFunction(User user) {
    user.login("test");
  }
}
