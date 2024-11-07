public class MinMax {
    
    //attributes
        int value;
        int row;
        int column;

    //constructor
        MinMax(int v, int r, int c){
            this.value = v;
            this.row = r;
            this.column = c;
        }

    //function to find minimum element
        public static MinMax findMin(int[][] a){
            MinMax min = new MinMax(Integer.MAX_VALUE,0,0);

            for(int i=0; i<a.length;i++){
                for(int j=0; j<a[0].length;j++){
                    if(a[i][j] < min.value){
                        min.value = a[i][j];
                        min.row = i;
                        min.column = j;
                    }
                }
            }

            return min;
        }

    //function to find maximum element
        public static MinMax findMax(int[][] a){
            MinMax max = new MinMax(Integer.MIN_VALUE,0,0);

            for(int i=0; i<a.length;i++){
                for(int j=0; j<a[0].length;j++){
                    if(a[i][j] > max.value){
                        max.value = a[i][j];
                        max.row = i;
                        max.column = j;
                    }
                }
            }

            return max;
        }
    //function to print the array
        public static void printArray(int a[][]){
            for(int i=0;i<a.length; i++){
                for (int j=0;j<a[0].length;j++){
                    System.out.print(a[i][j] +" ");
                }
                System.out.println("");
            }
        }

    //main method
        public static void main(String[] args){
            int[][] a = {{3,2,1},{4,9,6},{7,8,5}};

            System.out.println("2D Array: ");
            printArray(a);

            MinMax min = findMin(a);
            MinMax max = findMax(a);

            System.out.println("Minimum element: " +min.value+ " at (" +min.row+ "," +min.column+ ").");
            System.out.println("Maximum element: " +max.value+ " at (" +max.row+ "," +max.column+ ").");
        }
}
