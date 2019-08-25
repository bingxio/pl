public class Final {

  public static void main(String[] args) {
    final var a = 20;

    System.out.println(a);

    final int[] b = {4, 5, 6};
    final int[] c = {1, 2, 3};

    System.arraycopy(c, 0, b, 0, 3);

    for (int i = 0; i < 3; i ++) {
      System.out.format("%d %d \n", b[i], c[i]);
    }
  }
}
