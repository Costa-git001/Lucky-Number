using System;
using System.Collections.Generic;
using System.Linq;

class NumberGuessingGame
{
    static void Main()
    {
        Random random = new Random();
        List<(string Difficulty, int Attempts)> highScores = new();
        bool playAgain = true;

        Console.WriteLine("Welcome to the Number Guessing Game!");

        while (playAgain)
        {
            Console.Clear();
            Console.WriteLine("=========================================");

            // --- Difficulty Selection ---
            int maxNumber, maxAttempts;
            string difficultyLabel;

            Console.WriteLine("Select Difficulty:");
            Console.WriteLine("  1. Easy   - Guess 1 to 100  (10 attempts)");
            Console.WriteLine("  2. Medium - Guess 1 to 100  ( 7 attempts)");
            Console.WriteLine("  3. Hard   - Guess 1 to 200  ( 5 attempts)");
            Console.Write("Enter choice (1/2/3): ");

            switch (Console.ReadLine())
            {
                case "2":
                    maxNumber = 100;
                    maxAttempts = 7;
                    difficultyLabel = "Medium";
                    break;
                case "3":
                    maxNumber = 200;
                    maxAttempts = 5;
                    difficultyLabel = "Hard";
                    break;
                default:
                    maxNumber = 100;
                    maxAttempts = 10;
                    difficultyLabel = "Easy";
                    break;
            }

            Console.WriteLine($"\n[{difficultyLabel}] Guess a number between 1 and {maxNumber}. You have {maxAttempts} attempts.");
            Console.WriteLine("=========================================\n");

            int secretNumber = random.Next(1, maxNumber + 1);
            int attempts = 0;
            int guess = 0;
            bool won = false;

            // --- Game Loop ---
            while (guess != secretNumber && attempts < maxAttempts)
            {
                int remaining = maxAttempts - attempts;
                Console.Write($"Enter your guess ({remaining} attempt{(remaining == 1 ? "" : "s")} left): ");

                if (!int.TryParse(Console.ReadLine(), out guess))
                {
                    Console.WriteLine("⚠ Please enter a valid number.\n");
                    continue;
                }

                if (guess < 1 || guess > maxNumber)
                {
                    Console.WriteLine($"⚠ Number must be between 1 and {maxNumber}.\n");
                    continue;
                }

                attempts++;

                if (guess < secretNumber)
                    Console.WriteLine("📉 Too low! Try again.\n");
                else if (guess > secretNumber)
                    Console.WriteLine("📈 Too high! Try again.\n");
                else
                {
                    won = true;
                    Console.WriteLine($"🎉 Correct! You guessed it in {attempts} attempt{(attempts == 1 ? "" : "s")}.");
                }
            }

            if (!won)
                Console.WriteLine($"💀 Out of attempts! The number was {secretNumber}.");

            // --- High Score Tracking ---
            if (won)
            {
                highScores.Add((difficultyLabel, attempts));

                // Sort and keep top 5 scores
                highScores = highScores
                    .OrderBy(s => s.Attempts)
                    .Take(5)
                    .ToList();

                Console.WriteLine("\n🏆 High Scores:");
                Console.WriteLine($"  {"Difficulty",-10} {"Attempts",8}");
                Console.WriteLine($"  {new string('-', 20)}");

                foreach (var score in highScores)
                    Console.WriteLine($"  {score.Difficulty,-10} {score.Attempts,8}");
            }

            // --- Replay Prompt ---
            Console.WriteLine("\n=========================================");
            Console.Write("Play again? (Y/N): ");
            string input = Console.ReadLine()?.Trim().ToUpper();
            playAgain = input == "Y";

            Console.WriteLine();
        }

        Console.WriteLine("Thanks for playing! Final High Scores:");
        if (highScores.Count == 0)
        {
            Console.WriteLine("  No wins recorded.");
        }
        else
        {
            Console.WriteLine($"  {"Difficulty",-10} {"Attempts",8}");
            Console.WriteLine($"  {new string('-', 20)}");

            foreach (var score in highScores)
                Console.WriteLine($"  {score.Difficulty,-10} {score.Attempts,8}");
        }

        Console.WriteLine("\nPress any key to exit.");
        Console.ReadKey();
    }
}
