using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Baekjoon
{
    class Program
    {
        static void Main(string[] args)
        {	
        	Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 1; i <= 8; i++)
            {
                dic.Add(i, Convert.ToInt32(Console.ReadLine()));
            }
            // 값 기준 내림차순 정렬
            // Take(5)로 상위 5개만 가져옴 ToList() -> 리스트로 변환
            var sorted = dic.OrderByDescending(item => item.Value)
                .Take(5)
                .ToDictionary(x => x.Key, x => x.Value);
            
            // 합 계산
            int sum = sorted.Sum(x => x.Value);
            Console.WriteLine(sum);

            // 문제에서 정렬 기준을 오름차순으로 출력 요구할 수도 있음
            var sortedKeys = sorted.Keys.OrderBy(x => x).ToList();
            foreach (var key in sortedKeys)
            {
                Console.Write(key + " ");
            }
        }
    }
}
