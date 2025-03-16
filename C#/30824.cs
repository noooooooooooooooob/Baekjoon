using System;
using System.Collections.Generic;

class Program
{
    static List<long> fib = new List<long>(); // 피보나치 수열 저장

    static void GenerateFibonacci()
    {
        fib.Add(1);
        fib.Add(1); 

        while (true)
        {
            long next = fib[fib.Count - 1] + fib[fib.Count - 2];
            if (next > 1e16) break; // 10^16을 초과하면 중단
            fib.Add(next);
        }
    }

    static bool CanSumWithFibonacci(int k, long x)
    {
        if (k == 1)
            return fib.Contains(x);

        if (k == 2)
        {
            for (int i = 0; i < fib.Count; i++)
            {
                for (int j = i; j < fib.Count; j++)  // 중복 허용
                {
                    if (fib[i] + fib[j] == x) return true;
                }
            }
            return false;
        }

        if (k == 3)
        {
            for (int i = 0; i < fib.Count; i++)
            {
                for (int j = i; j < fib.Count; j++)  
                {
                    for (int k_idx = j; k_idx < fib.Count; k_idx++)
                    {
                        if (fib[i] + fib[j] + fib[k_idx] == x) return true;
                    }
                }
            }
            return false;
        }

        return false;
    }

    static void Main()
    {
        GenerateFibonacci();

        int T = int.Parse(Console.ReadLine());
        while (T-- > 0)
        {
            string[] input = Console.ReadLine().Split();
            int k = int.Parse(input[0]);
            long x = long.Parse(input[1]);

            Console.WriteLine(CanSumWithFibonacci(k, x) ? "YES" : "NO");
        }
    }
}
