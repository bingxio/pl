package app;

class App {
  public static void main (String[] args) throws Exception {
    int a = 20;
    
    int b = switch (a) {
      case 0 -> -1;
      case 10 -> 12;
      case 20 -> 30;

      default -> {
        yield 50;
        System.out.println("Call default branch ...");
      }
    };

    System.out.println("a = " + a + " b = " + b);
  }
}
