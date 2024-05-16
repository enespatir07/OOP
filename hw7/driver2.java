import java.util.Scanner;

/**
 * The driver2 class is used to create a Tetris game that takes user input for
 * the number of rows and columns in the game board,
 * as well as the type of Tetromino to drop. The game will continue to run until
 * the user enters 'Q' to quit.
 * 'R' can be entered as input to drop a random Tetromino.
 * 
 * @author Abdullah Enes Patir
 */
public class driver2 {
    /**
     * The main method is used to run the Tetris game.
     * 
     * @param args An array of command-line arguments.
     */
    public static void main(String[] args) {
        Tetris tetris;
        Scanner scanner = new Scanner(System.in);
        char type = 'x';
        int row, column;
        // Input validation and getting input
        while (true) {
            try {
                System.out.println("Number of rows and columns (10 or greater): ");
                // Checking if input is integer
                if (scanner.hasNextInt()) {
                    row = scanner.nextInt();
                    column = scanner.nextInt();
                    tetris = new Tetris(row, column);
                    tetris.createBoard();
                    break;
                } else {
                    System.err.println("Please enter a valid number.");
                    scanner.next();
                    continue;
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
                continue;
            }
        }
        // Input validation and getting input
        while (true) {
            do {
                System.out.println("Tetromino type: ");
                String temp = scanner.next();
                // If given input is longer than 1 then that is invalid
                if (temp.length() > 1)
                    System.err.println("Please enter a valid type");
                else {
                    type = temp.charAt(0);
                    // Valid case
                    if (type == 'O' || type == 'J' || type == 'T' || type == 'L' || type == 'S' || type == 'Z'
                            || type == 'I' || type == 'Q' || type == 'R')
                        break;
                    // Invalid case
                    else
                        System.err.println("Please enter a valid type");
                }
            } while (true);
            // Program termination
            if (type == 'Q') {
                System.out.println("Program terminated");
                System.exit(0);
            }
            // Random tetromino
            if (type == 'R')
                type = Tetromino.randomShape();

            Tetromino tetromino = new Tetromino(type);
            tetris.animate(tetromino, scanner);
        }

    }
}
