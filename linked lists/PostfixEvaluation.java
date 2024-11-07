import java.util.Stack;

public class PostfixEvaluation {

    // Method to evaluate postfix expression using a stack
    public static int evaluatePostfix(String expression) {

        Stack<Integer> stack = new Stack<>();   // Stack to store operands

        // Loop through each character in the expression
        for (int i = 0; i < expression.length(); i++) {

            char c = expression.charAt(i);

            // If the character is a digit, push it onto the stack
            if (Character.isDigit(c)) {

                stack.push(c - '0');  // Convert character to integer and push
            } 
            // If the character is an operator, pop two elements from stack and apply the operation
            else {

                int v1 = stack.pop();

                int v2 = stack.pop();

                switch (c) {
                    case '+':
                        stack.push(v2 + v1);  // Perform addition
                        break;
                    case '-':
                        stack.push(v2 - v1);  // Perform subtraction
                        break;
                    case '*':
                        stack.push(v2 * v1);  // Perform multiplication
                        break;
                    case '/':
                        stack.push(v2 / v1);  // Perform division
                        break;
                    case '^':
                        stack.push((int) Math.pow(v2, v1));  // Perform exponentiation
                        break;
                }
            }
        }

        // Return the final result (the only value left in the stack)
        return stack.pop();
    }

    public static void main(String[] args) {
        
        String expression = "23+5*";        // Example postfix expression: (2 + 3) * 5

        System.out.println("Postfix Evaluation Result: " + evaluatePostfix(expression));  // Output: 25
    }
}
