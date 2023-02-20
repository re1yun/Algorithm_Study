문제 설명

정수를 담고 있는 배열 arr의 평균값을 return하는 함수, solution을 완성해보세요.

제한사항
arr은 길이 1 이상, 100 이하인 배열입니다.
arr의 원소는 -10,000 이상 10,000 이하인 정수입니다.

입출력 예
arr	return
[1,2,3,4]	2.5
[5,5]	5

간단하게 arr 배열을 돌면서 값을 더해주고, size() 함수를 이용해서 평균을 구해주었다.
다른 사람의 풀이를 보니, <numeric> 라이브러리의 accumulate 함수를 사용하여 간편하게 구했다.

'''c

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "The sum of the numbers is " << sum << std::endl;

    return 0;
}

'''
사용 예제이다.
