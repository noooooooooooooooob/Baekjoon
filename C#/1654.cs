using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Baekjoon
{
    class Program
    {
        static void Main(string[] args) // 이분탐색
        {
            String[] input = Console.ReadLine().Split(" ");
            int K = int.Parse(input[0]);
            int N = int.Parse(input[1]);
            List<long> arr = new List<long>();
            for (int i = 0; i < K; i++)
            {
                arr.Add(long.Parse(Console.ReadLine()));
            }
            if (N == 1)
            {
                Console.WriteLine(arr.Max());
                return;
            }

            long end = arr.Max();
            long start = 1;
            long result = 0;

            while (start <= end)
            {
                long mid = (end + start) / 2;
                long cnt = 0;

                for (int i = 0; i < K; i++)
                    cnt += arr[i] / mid;

              // 무한 반복 방지용 +1 , -1
                if (cnt >= N)
                {
                    result = mid;
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            Console.WriteLine(result);
        }
    }
}
