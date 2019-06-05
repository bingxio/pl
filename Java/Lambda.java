import java.util.Arrays;

interface ClickListener {

    void onClick (int view);

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

        new Thread(() -> System.out.println("Hello World")).start();

        var textView = new TextView();

        textView.setOnClickListener(100, new ClickListener() {

            @Override
            public void onClick(int view) {
                System.out.format("%d call click listener before Java 8 \n", view);
            }
        });

        textView.setOnClickListener(200, (view ->
                System.out.format("%d call click listener after Java 8 \n", view)));

        var list = Arrays.asList(12, "hello", 4.5, false, 666);

        list.forEach(System.out::println);
    }
}
