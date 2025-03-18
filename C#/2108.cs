using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Baekjoon
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(Console.OpenStandardInput()))
            {
                int N = int.Parse(sr.ReadLine());
                List<int> arr = new List<int>(N);

                for (int i = 0; i < N; i++)
                {
                    arr.Add(int.Parse(sr.ReadLine()));
                }

                arr.Sort();

                double avg = Math.Round((double)arr.Sum() / N);
                Console.WriteLine((int)avg);

                Console.WriteLine(arr[N / 2]);

                Dictionary<int, int> dic = new Dictionary<int, int>();
                foreach (int i in arr)
                {
                    if (dic.ContainsKey(i))
                        dic[i]++;
                    else
                        dic[i] = 1;
                }

                var freqList = dic.OrderByDescending(x => x.Value)
                                  .ThenBy(x => x.Key)
                                  .ToList();

                if (N > 1 && freqList.Count > 1 && freqList[0].Value == freqList[1].Value)
                    Console.WriteLine(freqList[1].Key);
                else
                    Console.WriteLine(freqList[0].Key);

                Console.WriteLine(arr.Max() - arr.Min());
            }
        }
    }
}
