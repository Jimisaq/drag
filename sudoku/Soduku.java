public class Soduku {

    //function to solve a soduku puzzle
        public static boolean solvePuzzle(int[][] puzzle){
            for(int i =0; i<9;i++){
                for(int j=0; j<9;j++){
                    if(checkEmpty(puzzle[i][j])){
                        //fill(puzzle,i,j);
                        for(int s=0;s<=9;s++){
                            if(isValidEntry(puzzle,i,j,s)){
                                puzzle[i][j]=s;

                                if(solvePuzzle(puzzle)){
                                    return true;
                                }else{
                                    puzzle[i][j]=0;
                                }
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }

    public static boolean checkEmpty(int value){
        return value == 0;
    }

    public static void fill(int[][] puzzle,int i, int j){
        int[] solutionSet = {1,2,3,4,5,6,7,8,9};
        for(int sol:solutionSet){
            if(isValidEntry(puzzle,i,j,sol)){
                puzzle[i][j]=sol;
                break;
            }
        }
    }

    public static boolean isValidEntry(int[][] puzzle,int i, int j,int n){
        if(checkRow(puzzle,i,n) & checkCol(puzzle,j,n) & checkSubGrid(puzzle,i,j,n)){
            return true;
        }
        return false;
    }

    public static boolean checkRow(int[][] puzzle,int i,int candidate){
        for(int j=0;j<9;j++){
            if(candidate==puzzle[i][j]){
                return false;
            }
        }
        return true;
    }

    public static boolean checkCol(int[][] puzzle, int j, int candidate) {
        for (int i = 0; i < 9; i++) {
            if (candidate == puzzle[i][j]) {
                return false;
            }
        }
        return true;
    }

    public static boolean checkSubGrid(int[][] puzzle,int i, int j, int candidate){
        int m=i-(i%3);
        int n=j-(j%3);
        for(int x=m;x<m+3;x++){
            for(int y=n;y<n+3;y++){
                if(candidate==puzzle[x][y]){
                    return false;
                }
            }
        }
        return true;
    }

    public static void printPuzzle(int[][] puzzle){
        for(int i =0; i<9;i++){
            for(int j=0; j<9;j++){
                System.out.print(puzzle[i][j]+" ");
                if((j+1)%3==0){
                    System.out.print(" ");
                }
            }
            System.out.println("");
            if((i+1)%3==0){
                System.out.println();
            }
        }
    }

        public static void main(String[] args) {
         int[][] puzzle = {
                {5, 3, 0, 0, 7, 0, 0, 0, 0},
                {6, 0, 0, 1, 9, 5, 0, 0, 0},
                {0, 9, 8, 0, 0, 0, 0, 6, 0},
                {8, 0, 0, 0, 6, 0, 0, 0, 3},
                {4, 0, 0, 8, 0, 3, 0, 0, 1},
                {7, 0, 0, 0, 2, 0, 0, 0, 6},
                {0, 6, 0, 0, 0, 0, 2, 8, 0},
                {0, 0, 0, 4, 1, 9, 0, 0, 5},
                {0, 0, 0, 0, 8, 0, 0, 7, 9}
         };
    
        Soduku.printPuzzle(puzzle);
    
            //solution
            System.out.println("Solution");
            Soduku.solvePuzzle(puzzle);
            Soduku.printPuzzle(puzzle);
    
        }
}