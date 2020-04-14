public class Main {
    public static void main(String[] args) {
        int x = 30;
        int y = switch (x) {
            case 29 -> -1;
            case 30 -> {
                System.out.println("Call.");
                yield 32;
            }
            default -> throw new IllegalStateException("Unexpected value: " + x);
        };
        System.out.println("x = " + x);
        System.out.println("y = " + y);
    }
}
