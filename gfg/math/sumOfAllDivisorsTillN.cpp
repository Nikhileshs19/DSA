long long sumOfDivisors(int N)
    {
        long long sum = 0;
        for (int i = 1; i <= N; ++i)
        {
            sum += i * (N / i);
        }
        return sum;
    }