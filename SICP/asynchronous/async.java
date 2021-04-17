import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

class App {
  public static void main(String[] args) {
    System.out.println("START!!");

    CompletableFuture<Integer> future = CompletableFuture.supplyAsync(() -> {
      try {
        Thread.sleep(3000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
      System.out.println("DONE.");
      return 1;
    });
    future.join();

    if (future.isDone()) {
      try {
        System.out.printf("END %d\n", future.get());
      } catch (InterruptedException | ExecutionException e) {
        e.printStackTrace();
      }
    }
  }
}