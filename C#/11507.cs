using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Immutable;
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
            int[] reaminCards = {13,13,13,13};
            bool[][] isin = new bool[4][];
            for(int i=0;i<4;i++)
                isin[i] = new bool[14];
            string input = Console.ReadLine();
            // 입력을 3개 씩 나눔
            var result = Enumerable.Range(0, (input.Length + 2) / 3)
                               .Select(i => input.Substring(i * 3, Math.Min(3, input.Length - i * 3)))
                               .ToArray();
            bool isSame = false;
            
            foreach(string str in result)
            {
                int num = str[2] - '0';
                num += (str[1] - '0') * 10;
                switch(str[0])
                {
                    case 'P':
                        if(isin[0][num])
                            isSame = true;
                        else
                            isin[0][num] = true;
                        reaminCards[0]--;
                        break;
                    case 'K':
                        if(isin[1][num])
                            isSame = true;
                        else
                            isin[1][num] = true;
                        reaminCards[1]--;
                        break;
                    case 'H':
                        if(isin[2][num])
                            isSame = true;
                        else
                            isin[2][num] = true;
                        reaminCards[2]--;
                        break;
                    case 'T':
                        if(isin[3][num])
                            isSame = true;
                        else
                            isin[3][num] = true;
                        reaminCards[3]--;
                        break;
                }
            }
            if(isSame)
            {
                Console.WriteLine("GRESKA");
            }
            else
            {
                foreach(int number in reaminCards)
                    Console.Write(number + " ");
            }
        }
    }
}
