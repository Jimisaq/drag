import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        LinkedStack forward = new LinkedStack(10);
        LinkedStack backward = new LinkedStack(10);
        Browser browser = new Browser(forward,backward);
        Scanner scanner = new Scanner(System.in);

        while(true){
            System.out.println("\nEnter page to visit(B for back, F for forward,exit to exit):");
            String action=scanner.nextLine();
            if(action.equalsIgnoreCase("exit")){
              break;
            }else if(action.equalsIgnoreCase("B")){
                browser.back();
            }else if(action.equalsIgnoreCase("F")){
                browser.forward();
            }else{
                browser.visit(action);
            }
        }
    }
}