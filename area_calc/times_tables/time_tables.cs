using System;

    static void Main()
    {
        // Input for rows
        Console.Write("Enter starting value for rows: ");
        int startRow = int.Parse(Console.ReadLine());

        Console.Write("Enter ending value for rows: ");
        int endRow = int.Parse(Console.ReadLine());

        // Input for columns
        Console.Write("Enter starting value for columns: ");
        int startCol = int.Parse(Console.ReadLine());

        Console.Write("Enter ending value for columns: ");
        int endCol = int.Parse(Console.ReadLine());

        // Print column headers
        Console.Write("\n    ");
        for (int col = startCol; col <= endCol; col++)
        {
            Console.Write($"{col,4}");
        }
        Console.WriteLine();

        // Print separator
        Console.WriteLine("    " + new string('=', (endCol - startCol + 1) * 4));

        // Print rows with their corresponding multiplication values
        for (int row = startRow; row <= endRow; row++)
        {
            Console.Write($"{row,4}"); // Row label
            for (int col = startCol; col <= endCol; col++)
            {
                Console.Write($"{row * col,4}"); // Multiplication result
            }
            Console.WriteLine(); // Move to the next line after each row
        }
    }

