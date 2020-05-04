# STL

## stl containers
* [sequence containers](#sequence_containers)
* [associative containers](#associative_containers)
* [unordered associative containers](#unordered_associative_containers)
* [container adaptor](#container_adaptor)

<br/>

## `heap, sort, partition` util naming
* [std::stable_*](#stable_*)
* [std::is_*](#is_*)
* [std::is_*_until](#is_*_until)

<br/>

## heap (std::priority_queue)
* [heap overview](#heap_overview)
* [std::priority_queue](#priority_queue)

<br/>

## sort
* [std::sort](#sort)
* [std::stable_sort](#stable_sort)
* [std::inplace_merge](#inplace_merge), [std::merge](#merge)
* [std::partial_sort](#partial_sort)
* [std::nth_element](#nth_element)
* [std::is_sorted](#is_sorted)

<br/>

## partition
* [std::partition](#partition)
* [std::stable_partition](#stable_partition)
* [std::partition_point](#partition_point)

<br/>

## permutation
* [std::next_permutation](#next_permutation), [std::prev_permutation](#prev_permutation)
* [std::rotate](#rotate)
* [std::random_shuffle](#random_shuffle), [std::shuffle](#shuffle)

<br/>

## algorithm etc
* [std::min](#min), [std::max](#max) // todo
* [std::swap](#swap) // todo
* [std::copy](#copy) // todo
* [std::transform](#transform) // todo
* [std::fill](#fill)
* [std::count](#count)
* [std::remove](#remove)
* [std::replace](#replace)
* [std::find](#find)
* 각각의 ```_if``` 함수가 존재하는 것들은 따로 함수를 만들어 함수 포인터를 매개 변수로 넣어주면 된다.


<br/><br/>
<hr/>

## stl containers

# stl containers
## <a id="sequence_containers*">sequence containers</a>
## <a id="associative_containers*">associative containers</a>
## <a id="unordered_associative_containers*">unordered associative containers</a>
## <a id="container_adaptor*">container adaptor</a>



<br/>

# `heap, sort, partition` util naming
## <a id="stable_*">std::stable_*</a>
## <a id="is_*">std::is_*</a>
## <a id="is_*_until">std::is_*_until</a>



<br/>

# heap (std::priority_queue)
## <a id="heap_overview">heap overview</a>
## <a id="priority_queue">std::priority_queue</a>


<br/>

# sort
## <a id="sort">std::sort</a>
## <a id="stable_sort">std::stable_sort</a>
## <a id="inplace_merge">std::inplace_merge</a>, <a id="merge">std::merge</a>
## <a id="partial_sort">std::partial_sort</a>
## <a id="nth_element">std::nth_element</a>
## <a id="is_sorted">std::is_sorted</a>


<br/>

# partition
## <a id="partition">std::partition</a>
## <a id="stable_partition">std::stable_partition</a>
## <a id="partition_point">std::partition_point</a>


<br/>

# permutation
## <a id="next_permutation">std::next_permutation</a>, <a id="prev_permutation">std::prev_permutation</a>
## <a id="rotate">std::rotate</a>
## <a id="random_shuffle">std::random_shuffle</a>, <a id="shuffle">std::shuffle</a>

<br/>

# algorithm etc

## <a id="min">std::min</a>, <a id="max">std::max</a>
### 설명
### 예제


<br/>

## <a id="swap">std::swap</a>
### 설명
### 예제


<br/>

## <a id="copy">std::copy</a>
### 설명
### 예제


<br/>

## <a id="transform">std::transform</a>
### 설명
### 예제


<br/>

## <a id="fill">std::fill</a>

### 설명

* 지정된 위치만큼 값을 채움

### 예제

~~~cpp
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
~~~



<br/>

## <a id="count">std::count, std::count_if</a>

### 설명

* 특정 범위에서 특정 숫자를 카운트

### 예제

~~~cpp
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
~~~




<br/>

## <a id="remove">std::remove, std::remove_if</a>

### 설명

* 특정 범위에서 특정 숫자를 지움

### 예제

~~~cpp
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
~~~





<br/>

## <a id="replace">std::replace, std::replace_if</a>

### 설명

* 특정 범위에서 특정 숫자를 바꿈

### 예제

~~~cpp
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
~~~




<br/>

## <a id="find">std::find, std::find_if</a>

### 설명

* 범위에서 지정된 값을 가진 요소가 첫 번째로 나타나는 위치를 반환

### 예제

~~~cpp
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
~~~
