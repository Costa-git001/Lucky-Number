using System;

class NumberGuessingGame
{
    static void Main()
    {
        Random random = new Random();
        int secretNumber = random.Next(1, 101); // Number between 1 and 100
        int attempts = 0;
        int guess = 0;

        Console.WriteLine("Welcome to the Number Guessing Game!");
        Console.WriteLine("Guess a number between 1 and 100.");

        // Game loop
        while (guess != secretNumber)
        {
            Console.Write("Enter your guess: ");
            
            // Input validation
            if (!int.TryParse(Console.ReadLine(), out guess))
            {
                Console.WriteLine("Please enter a valid number.");
                continue;
            }

            attempts++;

            if (guess < secretNumber)
            {
                Console.WriteLine("Too low! Try again.");
            }
            else if (guess > secretNumber)
            {
                Console.WriteLine("Too high! Try again.");
            }
            else
            {
                Console.WriteLine($"🎉 Correct! You guessed the number in {attempts} attempts.");
            }
        }

        Console.WriteLine("Game Over. Press any key to exit.");
        Console.ReadKey();
    }
}