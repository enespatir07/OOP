import java.util.Random;
import java.util.Scanner;

/**
 * The Tetris class represents the game of Tetris.
 * It has various methods to create the game board, add the Tetromino shapes,
 * rotate, move and animate the shapes.
 * It has fields to keep track of the number of falls, check if the shapes
 * overlap and keep track of the count of moves and rotations.
 * 
 * @author Abdullah Enes Patir
 */
public class Tetris {
    private int row;
    private int column;
    /**
     * Number of falls happened till tetromino lands
     */
    private int numofFalls;
    /**
     * An attribute to check if tetrises touches
     */
    private int check;
    private int moveCount;
    private int rotationCount;
    private char rotationDirection;
    private char moveDirection;
    private char[][] tetrisBoard;
    Random rand = new Random();

    /**
     * Constructor that initializes the number of rows and columns for the game
     * board and assigns the number of falls and check to 0.
     * 
     * @param row_    the number of rows for the game board
     * @param column_ the number of columns for the game board
     */
    public Tetris(final int row_, final int column_) {
        if (row_ < 10 || column_ < 10)
            throw new IllegalArgumentException("Please enter a valid number (10 or greater)");
        row = row_;
        column = column_;
        numofFalls = 1;
        check = 0;
    }

    /**
     * Method that creates the game board by initializing a 2D array of characters
     * and assigning '#' to the outer edges and ' ' to the inner spaces.
     */
    public void createBoard() {
        tetrisBoard = new char[row + 2][column + 2];
        for (int i = 0; i < row + 2; i++) {
            for (int j = 0; j < column + 2; j++) {
                if (i == 0 || i == row + 1)
                    tetrisBoard[i][j] = '#';
                else if (j == 0 || j == column + 1)
                    tetrisBoard[i][j] = '#';
                else
                    tetrisBoard[i][j] = ' ';
            }
        }
    }

    /**
     * Method that draws the game board on the screen by printing the 2D array of
     * characters
     */
    public void draw() {
        for (int i = 0; i < row + 2; i++) {
            for (int j = 0; j < column + 2; j++) {
                System.out.print(tetrisBoard[i][j]);
            }
            System.out.println();
        }
    }

    /**
     * Method that adds a Tetromino shape to the game board by updating the 2D array
     * of characters
     * 
     * @param other the Tetromino shape to be added
     * @return the updated Tetris object
     */

    public Tetris add(Tetromino other) {
        if (numofFalls == 2) {
            for (int i = 1; i <= other.getTetromino().length; i++) {
                for (int j = 0; j < other.getTetromino()[0].length; j++) {
                    tetrisBoard[i][1 + (column / 2) + j] = ' ';
                }
            }
        }
        for (int i = 0; i < other.getTetromino().length; i++) {
            for (int k = 0; k < other.getTetromino()[0].length; k++) {
                // checking for tetrominos overlap
                if (tetrisBoard[numofFalls + other.getTetromino().length - 1][1 + (column / 2) + moveCount + k] != ' ')
                    check = 1;
            }
            if (check == 1) {
                break;
            }
            for (int j = 0; j < other.getTetromino()[0].length; j++) {
                if (numofFalls == 1)
                    tetrisBoard[numofFalls + i][1 + (column / 2) + j] = other.getTetromino()[i][j];
                if (numofFalls > 1)
                    tetrisBoard[numofFalls + i][1 + (column / 2) + j + moveCount] = other.getTetromino()[i][j];
                if (numofFalls != 1) {
                    tetrisBoard[numofFalls - 1][1 + (column / 2) + j + moveCount] = ' ';
                }
            }
        }
        return this;
    }

    /**
     * Method that animates the Tetromino shape by moving and rotating it and
     * updating the game board
     * 
     * @param other   the Tetromino shape to be animated
     * @param scanner the input scanner
     */

    public void animate(Tetromino other, Scanner scanner) {
        allRandom(other);
        int i = 0;
        for (int k = 0; k < rotationCount; k++)
            other.rotate(rotationDirection);
        if (heigthofTetris() + other.getTetromino().length == row) {
            System.err.println("Table is full");
            scanner.close();
            System.exit(0);
        }

        if (moveDirection == 'l') {
            moveCount *= -1;
        }
        do {
            add(other);
            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.print("\033[H\033[2J");
            draw();
            numofFalls++;
            i++;
        } while (i < row - other.getTetromino().length + 1 && check == 0);
        numofFalls = 1;
        check = 0;

    }

    /**
     * Method that computes the heigth of tetrominos on tetris
     * 
     * @return the height of tetrominos on tetris
     */
    public int heigthofTetris() {
        int flag = 0, s = 0;
        for (int i = row; i >= 1; i--) {
            flag = 0;
            for (int j = 1; j <= column; j++) {
                if (tetrisBoard[i][j] != ' ') {
                    s++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                return s;
        }
        return s;
    }

    /**
     * Method that assigns move and rotation datas randomly
     * 
     * @param Tetromino object
     */
    public void allRandom(Tetromino other) {
        char[] randomArray = { 'a', 'c' };
        int[] randomInt = { 1, 2, 3, 4 };
        char[] randomArray2 = { 'r', 'l' };
        rotationDirection = randomArray[rand.nextInt(2)];
        rotationCount = randomInt[rand.nextInt(4)];
        moveDirection = randomArray2[rand.nextInt(2)];
        if (moveDirection == 'r')
            moveCount = rand.nextInt((column / 2) - 1);
        else
            moveCount = rand.nextInt((column / 2) + 1);
    }
}
