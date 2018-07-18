
## 자료구조, algorithm 헤더 정리

### 자료구조

* [vecto](#vector), [stack](#stack), [queue](#queue), [deque(덱)](#deque)

### algorithm 함수

* [min](#min), [max](#max), [swap](#swap), [sort](#sort), [fill](#fill), [count](#count), [remove](#remove), [replace](#replace), [find](#find)

* 각각의 ```_if``` 함수가 존재하는 것들은 따로 함수를 만들어 함수 포인터를 매개 변수로 넣어주면 된다.

<hr>


## <a id="vector">vector</a>

### vector 기본 함수

#### 추가

* ```push_back(element)``` : end에 요소를 추가
* ```insert(v.begin()+3, element)``` : 3번째 인덱스에 요소를 추가, 그 뒤의 요소는 뒤로 밀림

#### 삭제

* ```pop_back()``` : end에 있는 요소를 삭제
* ```q = erase(v.begin()+3)``` : 3번째 인덱스의 요소 삭제, q는 다음번 요소를 가리킴
* ```clear()``` : 벡터의 모든 요소 삭제

#### 조회

* ```at(index)``` : index에 있는 __요소를__ 반환
* ```begin(), end()``` : 각각 첫 번째와 마지막 __포인터__ 반환

#### 기타

* ```empty()``` : 벡터가 비어있으면 true 아니면 false를 반환
* ```size()``` : 벡터 사이즈를 반환



<br/>
## <a id="stack">stack</a>

### stack 기본 함수

#### 추가 및 삭제

* ```push(element)``` : top에 요소를 추가
* ```pop()``` : top에 있는 요소를 삭제

#### 조회

* ```top()``` : top(스택의 처음이 아닌 가장 끝)에 있는 요소를 반환

#### 기타

* ```empty()``` : 스택이 비어있으면 true 아니면 false를 반환
* ```size()``` : 스택 사이즈를 반환


<br/>
## <a id="queue">queue</a>

### queue 기본 함수

#### 추가 및 삭제

* ```push(element)``` : front에 요소를 추가
* ```pop()``` : back에 있는 요소를 삭제

#### 조회

* ```front()``` : 큐 제일 앞에 있는 요소를 반환
* ```back()``` : 큐 제일 뒤에 있는 요소를 반환

#### 기타

* ```empty()``` : 큐가 비어있으면 true 아니면 false를 반환
* ```size()``` : 큐 사이즈를 반환



<br/>
## <a id="deque">deque(덱)</a>

### deque 기본 함수

#### 추가

* ```push_front(element)``` : front에 요소를 추가
* ```push_back(element)``` : back에 요소를 추가
* ```pop_front()``` : front에 있는 요소를 삭제
* ```pop_back()``` : back에 있는 요소를 삭제
* ```insert(dq.begin()+3, element)``` : 3번째 인덱스에 요소를 추가, 그 뒤의 요소는 뒤로 밀림

#### 삭제

* ```q = erase(dq.begin()+3)``` 3번째 있는 요소 삭제, q는 다음번 요소를 가리킴
* ```clear()``` : 덱의 모든 요소 삭제

#### 조회

* ```front()``` : front에 있는 __요소를__ 반환
* ```back()``` : back에 있는 __요소를__ 반환
* ```at(index)``` : index에 있는 __요소를__ 반환
* ```begin(), end()``` : 각각 첫 번째와 마지막 __포인터__ 반환

#### 기타

* ```empty()``` : 덱이 비어있으면 true 아니면 false를 반환
* ```size()``` : 덱 사이즈를 반환



<hr>
## <a id="min">min</a>

### 설명

* 작은 값 반환


## <a id="max">max</a>

### 설명

* 큰 값 반환


## <a id="swap">swap</a>

### 설명

* 값을 바꿈



<br/>
## <a id="sort">sort</a>

### 설명

* 내림차순, 오름차순 정렬

### 예제

<pre>

#include iostream
#include algorithm
#include vector

using namespace std;

int main(void)
{
	vector"int" v;

	v.push_back(5);	v.push_back(3);
	v.push_back(2);	v.push_back(34);
	v.push_back(3);	v.push_back(355);
	v.push_back(0);	v.push_back(-5);
	v.push_back(-11);	v.push_back(36);

	sort(v.begin(), v.end());	             // 오름차순
	sort(v.begin(), v.end(), greater"int"()); // 내림차순

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
}
</pre>



<br/>
## <a id="fill">fill</a>

### 설명

* 지정된 위치만큼 값을 채움

### 예제

<pre>
#include iostream
#include algorithm
#include vector

using namespace std;

int main(void)
{
	vector"int" v;

	v.push_back(5);	v.push_back(3);
	v.push_back(2);	v.push_back(34);
	v.push_back(3);	v.push_back(355);
	v.push_back(0);	v.push_back(-5);
	v.push_back(-11);	v.push_back(36);

	fill(v.begin(), v.begin() + 5, 3); // 앞에서 5개까지 3으로 채움
	fill(v.begin(), v.end(), 3); // 전부 3으로 채움
}

</pre>



<br/>
## <a id="count">count, count_if</a>

### 설명

* 특정 범위에서 특정 숫자를 카운트

### 예제

<pre>
#include iostream
#include algorithm
#include vector

using namespace std;

bool greater6(int i) {
	return (i > 6) ? true : false;
}

int main(void)
{
	vector"int" v;


	v.push_back(5);	v.push_back(3);
	v.push_back(2);	v.push_back(34);
	v.push_back(3);	v.push_back(355);
	v.push_back(0);	v.push_back(-5);
	v.push_back(-11);	v.push_back(36);


	/* count  */
	count(v.begin(), v.end(), 3);
	// 특정 숫자 3을 카운트

	/* count_if  */
	cout << count_if(v.begin(), v.end(), greater6) << endl;
	// 6 이상의 수를 카운트
}
</pre>




<br/>
## <a id="remove">remove, remove_if</a>

### 설명

* 특정 범위에서 특정 숫자를 지움

### 예제

<pre>

#include iostream
#include algorithm
#include vector

using namespace std;


bool greater6(int i) {
	return (i > 6) ? true : false;
}

int main(void)
{
	vector"int" v;

	v.push_back(5);    v.push_back(3);
	v.push_back(2);    v.push_back(34);
	v.push_back(3);    v.push_back(355);
	v.push_back(0);    v.push_back(-5);
	v.push_back(-11);    v.push_back(36);

	/* 사용 주의!
	remove 사용시 특정 3을 모두 지우고 전체의 size를
	유지하기 위해 끝에서 부터 삭제된 만큼의 숫자를 똑같이 채운다.
	그러므로 원하는 대로 벡터의 전체 사이즈도 줄고 그 벡터 내에서
	특정 값만을 지우고 싶다면 다음과 같이 해야한다.
	1. remove() -> end_ptr을 반환
	2. end_ptr()에서 벡터의 end까지 다 지워버림 (쓸데 없이 채운 값을 지움)
	*/

	/* remove */
	auto end_ptr = remove(v.begin(), v.end(), 3);
	v.erase(end_ptr, v.end());

	/* remove_if */
	auto end_ptr = remove_if(v.begin(), v.end(), greater6);
	v.erase(end_ptr, v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
}

</pre>





<br/>
## <a id="replace">replace, replace_if</a>

### 설명

* 특정 범위에서 특정 숫자를 바꿈

### 예제

<pre>

#include iostream
#include algorithm
#include vector

using namespace std;

bool greater6(int i) {
	return (i > 6) ? true : false;
}

int main(void)
{
	vector"int" v;

	v.push_back(5);	v.push_back(3);
	v.push_back(2);	v.push_back(34);
	v.push_back(3);	v.push_back(355);
	v.push_back(0);	v.push_back(-5);
	v.push_back(-11);	v.push_back(36);

	/* replace */
	replace(v.begin(), v.end(), 3, 1000);

	/* replace_if */
	replace_if(v.begin(), v.end(), greater6, 100);

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
}

</pre>




<br/>
## <a id="find">find, find_if</a>

### 설명

* 범위에서 지정된 값을 가진 요소가 첫 번째로 나타나는 위치를 반환

### 예제

<pre>

#include iostream
#include algorithm
#include vector

using namespace std;

bool greater6(int i) {
	return (i > 6) ? true : false;
}

int main(void)
{
	vector"int" v;

	v.push_back(5);	v.push_back(3);
	v.push_back(2);	v.push_back(34);
	v.push_back(3);	v.push_back(355);
	v.push_back(0);	v.push_back(-5);
	v.push_back(-11);	v.push_back(36);

	/* find */
	auto ptr = find(v.begin(), v.end(), 34);
	int position = ptr - v.begin();
	cout << "값: " << *ptr << endl;
	cout << "위치: " << position << endl;

	/* find_if */
	auto ptr1 = find_if(v.begin(), v.end(), greater6);
	int position1 = ptr1 - v.begin();
	cout << "값: " << *ptr1 << endl;
	cout << "위치: " << position1 << endl;

}
</pre>
