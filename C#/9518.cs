using System;
using System.Linq;

namespace Baekjoon
{
    class Program
    {
        static int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
        static int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

        static void Main(string[] args)
        {
            // 입력 처리
            string[] RS = Console.ReadLine().Split();
            int R = int.Parse(RS[0]);
            int S = int.Parse(RS[1]);

            char[][] arr = new char[R][];
            for (int i = 0; i < R; i++)
                arr[i] = Console.ReadLine().ToCharArray();

            // 현재 악수 횟수 계산
            int originalHandshakes = CountHandshakes(arr, R, S);

            int maxHandshakes = originalHandshakes;

            // 빈 자리에 상근이를 배치했을 때 최대 악수 횟수 계산
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < S; j++)
                {
                    if (arr[i][j] == '.') // 빈 자리일 때만 시도
                    {
                        // 배열 복사 후, 상근이 앉기
                        char[][] arrCopy = arr.Select(row => row.ToArray()).ToArray();
                        arrCopy[i][j] = 'o';

                        // 새로운 악수 횟수 계산
                        int newHandshakes = CountHandshakes(arrCopy, R, S);
                        maxHandshakes = Math.Max(maxHandshakes, newHandshakes);
                    }
                }
            }

            Console.WriteLine(maxHandshakes);
        }

        // 현재 배열에서 악수 개수 계산
        static int CountHandshakes(char[][] arr, int R, int S)
        {
            int cnt = 0;

            for (int x = 0; x < R; x++)
            {
                for (int y = 0; y < S; y++)
                {
                    if (arr[x][y] == 'o')
                    {
                        for (int d = 0; d < 8; d++) 
                        {
                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if (nx >= 0 && nx < R && ny >= 0 && ny < S && arr[nx][ny] == 'o')
                            {
                                cnt++;
                            }
                        }
                    }
                }
            }

            return cnt / 2; // 중복 카운트 제거
        }
    }
}
