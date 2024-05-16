import java.util.Random;

/**
 * The Tetromino class represents a Tetromino shape in the game of Tetris.
 * It has various constructors to create different shape of Tetromino and
 * a method to rotate it in either clockwise or anticlockwise direction.
 * It also has method to print the Tetromino on the screen and get the current
 * shape of Tetromino.
 * And a method to generate random shape of Tetromino.
 * 
 * @author Abdullah Enes Patir
 * 
 */
public class Tetromino {
    private char[][] shapeOfClass;
    static Random rand = new Random();

    /**
     * No-arg constructor that creates an 'O' shape Tetromino
     */
    public Tetromino() { // no parameter constructor
        shapeOfClass = new char[][] { { 'O', 'O' }, { 'O', 'O' } };
    }

    /**
     * Constructor that assigns the Tetromino with the given shape.
     * 
     * @param shape the shape of the Tetromino.
     */
    public Tetromino(char shape) { // Constructor to assign Tetrominos
        if (shape == 'I') {
            shapeOfClass = new char[][] { { 'I', 'I', 'I', 'I' } };
        } else if (shape == 'O') {
            shapeOfClass = new char[][] { { 'O', 'O' }, { 'O', 'O' } };
        } else if (shape == 'T') {
            shapeOfClass = new char[][] { { 'T', 'T', 'T' }, { ' ', 'T', ' ' } };
        } else if (shape == 'J') {
            shapeOfClass = new char[][] { { ' ', 'J', ' ' }, { ' ', 'J', ' ' }, { 'J', 'J', ' ' } };
        } else if (shape == 'L') {
            shapeOfClass = new char[][] { { ' ', 'L', ' ' }, { ' ', 'L', ' ' }, { ' ', 'L', 'L' } };
        } else if (shape == 'S') {
            shapeOfClass = new char[][] { { ' ', 'S', 'S' }, { 'S', 'S', ' ' } };
        } else if (shape == 'Z') {
            shapeOfClass = new char[][] { { 'Z', 'Z', ' ' }, { ' ', 'Z', 'Z' } };
        }
    }

    /**
     * Method that prints the Tetromino shape on the screen
     */
    public void printOnScreen() { // Printing Tetrominos on the screen
        for (int i = 0; i < shapeOfClass.length; i++) {
            for (int j = 0; j < shapeOfClass[i].length; j++) {
                System.out.print(shapeOfClass[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    /**
     * Method that rotates the Tetromino shape either in clockwise or anticlockwise
     * direction
     * 
     * @param direction the direction of rotation
     */
    public void rotate(final char direction) {
        // Rotates tetrominos either in clockwise or anticlockwise direction
        final int column = shapeOfClass[0].length;
        final int row = shapeOfClass.length;
        char[][] temp = new char[column][row];

        if (direction == 'a') {
            // towards anticlockwise
            for (int i = column - 1, k = 0; i >= 0; i--, k++) {
                for (int j = 0; j < row; j++) {
                    temp[k][j] = shapeOfClass[j][i];
                }
            }
        }
        if (direction == 'c') {
            // towards clockwise
            for (int i = 0; i < column; i++) {
                for (int j = row - 1, k = 0; j >= 0; j--, k++) {
                    temp[i][k] = shapeOfClass[j][i];
                }
            }
        }

        shapeOfClass = temp;
    }

    /**
     * Method that returns the current shape of the Tetromino.
     * 
     * @return the current shape of the Tetromino.
     */
    public char[][] getTetromino() {
        return shapeOfClass;
    }

    /**
     * Method that generates random shape of Tetromino
     * 
     * @return the random shape of Tetromino
     */
    public static char randomShape() {
        char[] randomArray = { 'I', 'S', 'Z', 'L', 'T', 'O', 'J' };
        return randomArray[rand.nextInt(7)];
    }

}
