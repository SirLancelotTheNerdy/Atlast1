// File: ShapeAreaCalculator.cs
using System;

class ShapeAreaCalculator
{
    static void Main()
    {
        // Prompt user for shape type
        Console.Write("What type of shape (R)ectangle, (T)riangle, or (C)ircle? ");
        char shapeType = Char.ToUpper(Console.ReadKey().KeyChar);
        Console.WriteLine(); // Move to next line after input
        
        // Handle shape selection
        switch (shapeType)
        {
            case 'R': // Rectangle
                Console.Write("Enter the length: ");
                double length = Convert.ToDouble(Console.ReadLine());

                Console.Write("Enter the width: ");
                double width = Convert.ToDouble(Console.ReadLine());

                double rectangleArea = length * width;
                Console.WriteLine($"The area of this rectangle is {rectangleArea:F2}.");
                break;

            case 'T': // Triangle
                Console.Write("Enter the base: ");
                double baseLength = Convert.ToDouble(Console.ReadLine());

                Console.Write("Enter the height: ");
                double height = Convert.ToDouble(Console.ReadLine());

                double triangleArea = 0.5 * baseLength * height;
                Console.WriteLine($"The area of this triangle is {triangleArea:F2}.");
                break;

            case 'C': // Circle
                Console.Write("Enter the radius: ");
                double radius = Convert.ToDouble(Console.ReadLine());

                double circleArea = Math.PI * Math.Pow(radius, 2);
                Console.WriteLine($"The area of this circle is {circleArea:F2}.");
                break;

            default:
                Console.WriteLine("Invalid shape type entered.");
                break;
        }
    }
}
