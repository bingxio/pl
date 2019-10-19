package app;

class App {
  public static void main (String[] args) throws Exception {
    System.out.println(
      getMiddle(1, 2, 3, 4, 5)
    );
  }

  public static <T> T getMiddle (T... arr) {
    return arr[arr.length / 2];
  }
}

interface Generator <T> {
  public T next ();
}

class FruitGenerator implements Generator <String> {
  @Override
  public String next () {
    return "next !!";
  }
}

class AppleGenerator <T> implements Generator <T> {
  private T value;

  void AppleGenerator (T value) {
    this.value = value;
  }

  @Override
  public T next () {
    return this.value;
  }
}

class Pair <T, R> {}
