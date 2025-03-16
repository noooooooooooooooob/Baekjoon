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
        	int J = int.Parse(Console.ReadLine());
            int A = int.Parse(Console.ReadLine());
            int[] Jsize = new int[J];
            for(int i=0;i<J;i++)
            {
                string input = Console.ReadLine();
                if(input=="S")
                {
                    Jsize[i]=1;
                }
                else if(input=="M")
                {
                    Jsize[i]=2;
                }
                else if(input=="L")
                {
                    Jsize[i]=3;
                }
            }
            int result=0;
            int size=0;
            for(int i=0;i<A;i++)
            {
                string[] input = Console.ReadLine().Split();
                if(input[0]=="S")
                {
                    size=1;
                }
                else if(input[0]=="M")
                {
                    size=2;
                }
                else if(input[0]=="L")
                {
                    size=3;
                }
                if(Jsize[int.Parse(input[1])-1]>=size)
                {
                    Jsize[int.Parse(input[1])-1]=0;
                    result++;
                }
            }
            Console.WriteLine(result);
        }
    }
}
