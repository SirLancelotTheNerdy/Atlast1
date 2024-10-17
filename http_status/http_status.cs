

ConsoleApplication.Run();

public class ConsoleApplication
{
    public static void Run()
 {
    int errorcode;

    Console.Write("Enter a Response Code: ");
        
            
     if (int.TryParse(Console.ReadLine(), out errorcode))
     {
        if (errorcode >= 100 && errorcode <= 199)
     {
        Console.WriteLine(errorcode +" is a Informational Response.");
     }
    
        else if (errorcode >= 200 && errorcode <= 299)
     {
        Console.WriteLine(errorcode +" is a Successful Responses.");
     }
        else if (errorcode >= 300 && errorcode <= 399)
     {
        Console.WriteLine(errorcode +" is a Redirection Messages.");
     }
        else if (errorcode >= 400 && errorcode <= 499)
     {
        Console.WriteLine(errorcode +" is a Client Error Responses.");
     }
        else if (errorcode >= 500 && errorcode <= 599)
     {
        Console.WriteLine(errorcode +" is a Server Error Responses.");
     }
        else
        {
            Console.WriteLine(errorcode +" is not a valid Responses.");
        }
     
     //else 
     //{
       // Console.WriteLine(errorcode +" is not a valid Responses.");
    // }   
             }
     

}
}


