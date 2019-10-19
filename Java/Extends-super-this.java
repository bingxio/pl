package app;

class App {

  public static void main (String[] args) throws Exception {
    new Haha();
    new Haha(23);
  }
}

class Test {
  public void show () {
    System.out.println("Called show method on class.");
  }

  public void showHaveCons (int x) {
    System.out.println("x = " + x);
  }
}

class Haha extends Test {
  int x;

  Haha () {
    super.show();
  }

  Haha (int x) {
    super.showHaveCons(x);
    this.x = x;
  }
}
