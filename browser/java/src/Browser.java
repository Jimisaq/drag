public class Browser {
    LinkedStack forward;
    LinkedStack backward;
    String currentPage=null;

    public Browser(LinkedStack forward, LinkedStack backward){
        this.forward=forward;
        this.backward=backward;
    }

    public void visit(String page){
        if(currentPage != null){
            backward.push(currentPage);
        }
        currentPage=page;
        forward.empty();
        displayCurrentPage();
    }
    public void back(){
        if(backward.isEmpty()){
            System.out.println("No previously visited pages available");
            return;
        }
        forward.push(currentPage);
        currentPage=backward.pop();
        displayCurrentPage();
    }
    public void forward(){
        if(forward.isEmpty()){
            System.out.println("Forward stack empty..");
            return;
        }
        backward.push(currentPage);
        currentPage=forward.pop();
        displayCurrentPage();
    }
    public void displayBackStack(){
        System.out.println("\nBack stack..");
        backward.printStack();
    }
    public void displayForwardStack(){
        System.out.println("\nForward stack..");
        forward.printStack();
    }
    public void displayCurrentPage(){
        System.out.println("Displaying... "+currentPage);
        displayBackStack();
        displayForwardStack();
        System.out.println("--------------------------------");
    }
}
