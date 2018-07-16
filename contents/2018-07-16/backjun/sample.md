
## Title : [ 정수 정렬하기 ] <br/> Tag : qsort, 이차원배열동적할당

### 알고리즘 이론 :
다이나믹 프로그래밍

<hr>

### 문제 :
다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.

<pre>
int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n‐1) + fibonacci(n‐2);
    }
}
</pre>

fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.

fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
fibonacci(0)은 0을 출력하고, 0을 리턴한다.
fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.


#### 입력 :
<pre>
3
0
1
3
</pre>

#### 출력 :
<pre>
1 0
0 1
1 2
</pre>

#### 답 :

<pre>
#include stdio.h
#include malloc.h

void fibonacci(int n, int *aa, int *bb) {
	int a, b, c;

	if (n == 0) {
		*aa = 1;
		*bb = 0;
		return;
	}
	else if (n == 1) {
		*aa = 0;
		*bb = 1;
		return;
	}

	a = 1;
	b = 1;

	for (int i = 2; i<=n; i++) {
		c = a + b;
		*aa = a;
		*bb = b;
		a = b;
		b = c;
	}

}

int main() {

	int T, n;
	int *aa, *bb;

	scanf("%d", &T);
	aa = (int *)malloc(sizeof(int)*T);
	bb = (int *)malloc(sizeof(int)*T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		fibonacci(n, &aa[i], &bb[i]);
	}

	for (int i = 0; i < T; i++)
		printf("%d %d\n", aa[i], bb[i]);
}
</pre>

#### 점수 : 통과

<hr>


### 좋은 예제
쉽다.

<hr>

### 링크
* <https://www.acmicpc.net/problem/1003>
