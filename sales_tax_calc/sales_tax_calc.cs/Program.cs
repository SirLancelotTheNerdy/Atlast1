

    static void Main()
    {
        // Get input from user
        Console.Write("Enter the purchase price: ");
        double purchasePrice = Convert.ToDouble(Console.ReadLine());

        Console.Write("Enter the tax rate: ");
        double taxRate = Convert.ToDouble(Console.ReadLine());

        // Calculate tax and total owed
        double taxAmount = purchasePrice * (taxRate / 100);
        double totalOwed = purchasePrice + taxAmount;

        // Output the results with proper formatting
        Console.WriteLine($"\nFor your {purchasePrice:C2} purchase, a {taxRate:F1}% tax is {taxAmount:C2} for a total of {totalOwed:C2}.");
    }
}

