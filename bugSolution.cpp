#include <vector>
#include <iostream>

std::vector<int> sieveOfEratosthenes(int n) {
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }
    std::vector<int> primes;
    for (int p = 2; p <= n; p++)
        if (isPrime[p])
            primes.push_back(p);
    return primes;
}

int main() {
    int n = 100;
    std::vector<int> primes = sieveOfEratosthenes(n);
    std::cout << "Prime numbers up to " << n << ": \n";
    for (int p : primes) {
        std::cout << p << " ";
    }
    std::cout << "\n";
    return 0;
}