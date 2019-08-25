import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class IO {

  public static void main(String[] args) {
    File file = new File("./test.txt");

    try {
      FileOutputStream fileOutputStream = new FileOutputStream(file);

      fileOutputStream.write("Hello World".getBytes());
      fileOutputStream.close();
    } catch (IOException e) {
      e.printStackTrace();
    }

    try {
      FileInputStream fileInputStream = new FileInputStream(file);

      byte[] bytes = new byte[1024];

      String a = new String(bytes, 0, fileInputStream.read(bytes));

      System.out.println(a);
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
