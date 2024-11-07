public class MergeArray {
    public static void main(String[] args) {

        //initialising sizes of the array
            int n1 = 5;
            int n2 = 5;
            int n = n1+n2;

        //initialising two single dimension arrays
            int[] arr1 = new int[n1];
            int[] arr2 = new int[n2];

        //initialising merged array
            int[] mergedarr = new int[n];

        //populating the first array
            for(int i=0;i<arr1.length;i++){
                arr1[i]=i*i;
            }

        //populating the second array
            for(int i=0;i<arr2.length;i++){
                arr2[i]=i*2;
            }

        //printing elements in the first array
            System.out.println("First array: ");

            for(int i=0;i<arr1.length;i++){
                System.out.println(arr1[i]);
            }

        //printing elements in the second array
            System.out.println("Second array: ");

            for(int i=0;i<arr2.length;i++){
                System.out.println(arr2[i]);
            }

        //initialising counters for the arrays
            int i = 0;
            int i1 = 0;
            int i2 = 0;

        //populating the merged array with elements of the first array
            for(int j=0;j<arr1.length;j++){
                    mergedarr[i] = arr1[i1];
                    i = i+1;
                    i1 = i1+1;
            }

        //populating the merged array with elements of the second array
            for(int j=0;j<arr2.length;j++){
                    mergedarr[i] = arr2[i2];
                    i = i+1;
                    i2 = i2+1;
                
            }

        //printing elements in the merged array
            System.out.println("The merged array is: ");

            for(int j=0;j<mergedarr.length;j++){
                System.out.print(mergedarr[j] +", ");
            }
    }
}
