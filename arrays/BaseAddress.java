public class BaseAddress{
    public static void main(String[] args) {
        //initializing the arrays.
            int[] arr1 = {1,5,7,3,9};
            int[][] arr2 = {{1,5},{7,3},{9,8}};
            int[][][] arr3 = {{{1,5},{7,3}},{{9,8},{2,4}}};

        //retrieving base addresses of the arrays
            int baseaddress1=System.identityHashCode(arr1);
            int baseaddress2=System.identityHashCode(arr2);
            int baseaddress3=System.identityHashCode(arr3);

        //Traversing single dimension array while printing each element
            System.out.println("Traversing single dimension array");

            for(int i=0;i<5;i++){
                System.out.println("Element["+ i +"]: "+ arr1[i]);
            }

        //printing the base address of the single dimension array
            System.out.println("Base address of single dimension array is: "+Integer.toHexString(baseaddress1));
            System.out.println();

        //Traversing two dimension array while printing each element
            System.out.println("Traversing 2-dimension array");

            for(int i=0;i<3;i++){
                for(int j=0;j<2;j++){
                    System.out.println("Element["+ i +"][" + j + "]: " + arr2[i][j]);
                }
            }

        //printing the base address of the two dimension array
            System.out.println("Base address of 2-dimension array is: "+Integer.toHexString(baseaddress2));
            System.out.println();

        //Traversing three dimension array while printing each element
            System.out.println("Traversing 3-dimension array");

            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    for(int k=0;k<2;k++){
                        System.out.println("Element["+ i +"]["+ j +"][" + k + "]: " + arr3[i][j][k]);
                    }
                }
            }

        //printing the base address of the three dimension array
            System.out.println("Base address of 3-dimension array is:"+Integer.toHexString(baseaddress3));
            System.out.println();
    }
}