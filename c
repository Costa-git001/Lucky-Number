using System;

class NumberGuessingGame
{
    static void Main()
    {
        Random random = new Random();

        Console.WriteLine("Welcome to the Number Guessing Game!");
        Console.WriteLine("=========================================");

        // --- Difficulty Selection ---
        int maxNumber, maxAttempts;
        string difficultyLabel;

        Console.WriteLine("Select Difficulty:");
        Console.WriteLine("  1. Easy   - Guess 1 to 100  (10 attempts)");
        Console.WriteLine("  2. Medium - Guess 1 to 100  ( 7 attempts)");
        Console.WriteLine("  3. Hard   - Guess 1 to 200  ( 5 attempts)");
        Console.Write("Enter choice (1/2/3): ");

        string diffChoice = Console.ReadLine();
        switch (diffChoice)
        {
            case "2":
                maxNumber = 100; maxAttempts = 7; difficultyLabel = "Medium";
                break;
            case "3":
                maxNumber = 200; maxAttempts = 5; difficultyLabel = "Hard";
                break;
            default:
                maxNumber = 100; maxAttempts = 10; difficultyLabel = "Easy";
                break;
        }

        Console.WriteLine($"\n[{difficultyLabel}] Guess a number between 1 and {maxNumber}. You have {maxAttempts} attempts.");
        Console.WriteLine("=========================================\n");

        int secretNumber = random.Next(1, maxNumber + 1);
        int attempts = 0;
        int guess = 0;

        // --- Game Loop ---
        while (guess != secretNumber && attempts < maxAttempts)
        {
            int remaining = maxAttempts - attempts;
            Console.Write($"Enter your guess ({remaining} attempt{(remaining == 1 ? "" : "s")} left): ");

            if (!int.TryParse(Console.ReadLine(), out guess))
            {
                Console.WriteLine("⚠  Please enter a valid number.\n");
                continue;
            }

            if (guess < 1 || guess > maxNumber)
            {
                Console.WriteLine($"⚠  Number must be between 1 and {maxNumber}.\n");
                continue;
            }

            attempts++;

            if (guess < secretNumber)
                Console.WriteLine("📉 Too low! Try again.\n");
            else if (guess > secretNumber)
                Console.WriteLine("📈 Too high! Try again.\n");
            else
                Console.WriteLine($"🎉 Correct! You guessed it in {attempts} attempt{(attempts == 1 ? "" : "s")}.");
        }

        if (guess != secretNumber)
            Console.WriteLine($"💀 Out of attempts! The number was {secretNumber}.");

        Console.WriteLine("\nGame Over. Press any key to exit.");
        Console.ReadKey();
    }
}
