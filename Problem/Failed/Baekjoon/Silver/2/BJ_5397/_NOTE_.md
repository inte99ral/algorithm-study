# <img alt="b2" src="https://d2gd6pc034wcta.cloudfront.net/tier/4.svg" width="16" /> [BJ 5397](https://www.acmicpc.net/problem/5397)：키로거

- 빈 벡터 컨테이너의 begin() 을 iter 로 저장했을 경우에 이 값은 end() 과 같으며, 값의 추가 이후에는 재할당(reallocation) 문제로 인하여 기존에 저장된 반복자(iterator)가 무효화됩니다. 하지만 빈 리스트 컨테이너의 begin() 을 iter 로 저장했을 경우 이 값은 end() 과 같으며, 값의 추가 이후에도 무효화되지 않고 여전히 end() 를 가르킵니다. 또한 ++ 연산자를 붙이면 순환구조로 인하여 한 바퀴 돌아 맨 앞의 begin() 을 가르키게 됩니다.
