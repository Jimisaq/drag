public class Stack {
    String[] pages;
    int top;
    int capacity;

    public Stack(int capacity){
        this.capacity=capacity;
        this.pages=new String[capacity];
        this.top=0;
    }

    public void push(String page){
        if(!this.isFull()){
            this.pages[this.top]=page;
            this.top++;
        }else{
            System.out.println("Stack is full");
        }
    }
    public String pop(){
        if(!this.isEmpty()){
            //System.out.println("Popping ..");
            String item = this.pages[this.top-1];
            this.pages[this.top-1]=null;
            this.top--;
            return item;
        }
        return("Stack is empty");
    }
    public boolean isFull(){
        return this.top == this.capacity;
    }
    public boolean isEmpty(){
        return top == 0;
    }
    public void printStack(){
        for(int i=0; i<this.top; i++){
            System.out.println(this.pages[i]);
        }
    }
    public void empty(){
        this.top=0;
        this.pages= new String[this.capacity];
    }

}
