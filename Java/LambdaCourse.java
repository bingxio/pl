import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class App {
    public void greet(Greeting greeting) {
        greeting.perform(); // Into a interface arg and called
    }

    // Call in interface
    void eval(MyAdd add) {
        System.out.println(add.add(6, 9)); // Print
    }

    public static void main(String[] args) throws Exception {
        App app = new App();
        HelloWorldGreeting hGreeting = new HelloWorldGreeting();
        app.greet(hGreeting); // 1

        HelloWorldGreeting greeting = new HelloWorldGreeting() {
            public void perform() {
                System.out.println("Hello inner 1!!");
            };
        };
        app.greet(greeting); // 2
        app.greet(new HelloWorldGreeting() {
            public void perform() {
                System.out.println("Hello inner 2!!"); // 3
            };
        });

        MyAdd add = (a, b) -> a + b; // lambda
        System.out.println("ADD 3 5 = " + add.add(3, 5)); // lambda

        app.eval((a, b) -> a * b); // And other

        new Thread(
                // Functional Interface
                // of Runnable
                () -> {
                    System.out.println("CALL IN THREAD 1");
                }
        //
        ).start();

        new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("CALL IN THREAD 2"); // Sample
            };
        }).start();

        class Todo {
            String title; // Fields

            Todo(String title) { // Constructor
                this.title = title;
            }
        }
        List<Todo> lTodos = Arrays.asList( // Functional
                new Todo("title 1"), new Todo("title 2"), new Todo("title 3"), new Todo("title 4"),
                new Todo("title 5"));

        lTodos.forEach(l -> System.out.println(l.title)); // Print

        Collections.sort(lTodos, new Comparator<Todo>() {
            @Override
            public int compare(Todo o1, Todo o2) {
                return 1;
            };
        });
        Collections.sort(lTodos, (a, b) -> -1); // And functional

        lTodos.forEach(l -> System.out.println("SORTED: " + l.title));// Print
        lTodos.stream().filter(l -> l.title.charAt(6) == '2' || l.title.charAt(6) == '4')
                .forEach(l -> System.out.println(l.title));
    }
}

// To lambda expression
interface Greeting {
    void perform();
}

// Sample class inherited of interface
// And implementationed.
class HelloWorldGreeting implements Greeting {
    @Override
    public void perform() {
        System.out.println("Hello sample!!"); // Method
    }
}

// To lambda expression
interface MyAdd {
    int add(int x, int y);
}
