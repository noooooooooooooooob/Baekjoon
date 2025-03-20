using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Sort 함수 추가
public static class StringExtensions
{
    public static string Sort(this String input)
    {
        char[] chars = input.ToCharArray();
        Array.Sort(chars);

        return new string(chars);
    }
}

namespace Baekjoon
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<string> list = new List<string>();

            for (int i = 0; i < N; i++)
            {
                string input = Console.ReadLine();
                input = input.Sort();
                list.Add(input);
            }
            list = list.Distinct().ToList();
            Console.WriteLine(list.Count);
        }
    }
}
