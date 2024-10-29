static void Main()
{
    int age;
    string name;
    string dage = "Adult";
    //getting the age 
    Console.WriteLine ("What is your age:");
    int age = Convet.toInt(Console.ReadLine());
    //defining the age 
    if (age >= 65)
    {
        Console.WriteLine("You are a Senior ");
    }
    else if (age < 18)
    {
        Console.WriteLine("You are a Child")
        dage = "Kid"
    }    
    else
    {
        Console.WriteLine("You are and Adult")
    }
    

           // Populate the array with initial usernames
        string[] usernames = { "blah", "nope", "why", "idontthinkso", "crazzzzay", "bop" };

        // Prompt the user for a username
        Console.WriteLine("Enter a unique username:");

        // Convert input to lowercase
        string newUsername = Console.ReadLine().ToLower();

        // Check if the username already exists 
        if (Array.Exists(usernames, username => username.Equals(newUsername, StringComparison.OrdinalIgnoreCase)))
        {
            Console.WriteLine("Username already exists. Please try again.");
        }
        else
        {
            Console.WriteLine("Username is available.");
            
            usernames = usernames + newUsername ;

        }

}