/**
 * The driver1 class is used to test the functionality of the Tetromino and
 * Tetris classes.
 * 
 * @author Abdullah Enes Patir
 */
public class driver1 {
    /**
     * The main method is used to run the test cases for the Tetromino and Tetris
     * classes.
     *
     * @param args An array of command-line arguments.
     */
    public static void main(String[] args) {
        System.out.println("Creating tetromino object of shape J");
        Tetromino tetromino = new Tetromino('J');
        System.out.println("Object created");
        System.out.println();
        System.out.println("--------------------------------------");
        System.out.println();
        System.out.println("Testing printOnScreen function");
        tetromino.printOnScreen();
        System.out.println("--------------------------------------");
        System.out.println();
        System.out.println("Testing rotate function in anticlockwise direction");
        tetromino.rotate('a');
        tetromino.printOnScreen();
        System.out.println("Testing rotate function in clockwise direction");
        tetromino.rotate('c');
        tetromino.printOnScreen();
        System.out.println("--------------------------------------");
        System.out.println();
        System.out.println("Testing randomShape function");
        System.out.println("Output: " + Tetromino.randomShape());
        System.out.println("Testing randomShape function");
        System.out.println("Output: " + Tetromino.randomShape());
        System.out.println();
        System.out.println("--------------------------------------");
        System.out.println();

        System.out.println("Creting tetris object");
        Tetris tetris = new Tetris(10, 10);
        System.out.println("Object created");
        System.out.println();
        System.out.println("--------------------------------------");
        System.out.println();
        System.out.println("Testing createBoard function");
        tetris.createBoard();
        System.out.println();
        System.out.println("--------------------------------------");
        System.out.println();
        System.out.println("Testing draw function");
        tetris.draw();
        System.out.println();
        System.out.println("--------------------------------------");
        System.out.println("Testing heigtofTetris function");
        System.out.println("Output: " + tetris.heigthofTetris());
        System.out.println();
        System.out.println("--------------------------------------");

        System.out.println();
        System.out.println("Testing add function");
        tetris.add(tetromino);
        tetris.draw();
        tetris.createBoard();
        System.out.println();
        System.out.println("--------------------------------------");

        System.out.println();
        System.out.println("Testing animate function");
        tetris.animate(tetromino, null);
        System.out.println();
        System.out.println("--------------------------------------");
    }
}
