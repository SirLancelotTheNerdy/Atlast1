using System;
using System.Linq;

class DiceGame
{
    static void Main()
    {
        Random random = new Random();
        int[] diceRolls = new int[5];
        int rerollCount = 0;

        // Initial roll
        RollDice(diceRolls, random);
        DisplayRolls(diceRolls, "Initial Roll:");

        while (rerollCount < 2)
        {
            Console.WriteLine($"You have {2 - rerollCount} reroll(s) remaining.");
            Console.Write("Enter the dice numbers to reroll (comma-separated, ex: 2,3,5) or leave blank to keep current dice: ");
            string input = Console.ReadLine();

            if (!string.IsNullOrEmpty(input))
            {
                int[] diceToReroll = input.Split(',').Select(num => int.Parse(num.Trim()) - 1).ToArray();
                RollSpecificDice(diceRolls, diceToReroll, random);
                rerollCount++;
            }
            else
            {
                break;
            }
            Console.Clear(); 
            DisplayRolls(diceRolls, "Updated Rolls:");
        }

        // Final score
        int finalScore = CalculateScore(diceRolls);
        Console.WriteLine($"Final Score: {finalScore}");
    }

    // Method to roll all dice
    static void RollDice(int[] diceRolls, Random random)
    {
        for (int i = 0; i < diceRolls.Length; i++)
        {
            diceRolls[i] = random.Next(1, 7);
        }
    }

    // Method to roll specific dice
    static void RollSpecificDice(int[] diceRolls, int[] diceToReroll, Random random)
    {
        foreach (int index in diceToReroll)
        {
            if (index >= 0 && index < diceRolls.Length)
            {
                diceRolls[index] = random.Next(1, 7);
            }
        }
    }

    // Method to display current rolls
    static void DisplayRolls(int[] diceRolls, string message)
    {
        Console.WriteLine(message);
        for (int i = 0; i < diceRolls.Length; i++)
        {
            Console.WriteLine($"Die {i + 1}: {diceRolls[i]}");
        }
    }

    // Method to calculate score
    static int CalculateScore(int[] diceRolls)
    {
        int sum = diceRolls.Sum();
        int bonusPoints = 0;
        var groupedRolls = diceRolls.GroupBy(x => x).Select(group => group.Count());

        // Calculate bonus points based on scoring rules
        switch (groupedRolls.Max())
        {
            case 2:
                bonusPoints = 10;  // Two of the same value
                break;
            case 3:
                bonusPoints = 15;  // Three of the same value
                break;
            case 4:
                bonusPoints = 25;  // Four of the same value
                break;
            case 5:
                bonusPoints = 30;  // Five of the same value
                break;
        }

        return sum + bonusPoints;
    }
}
