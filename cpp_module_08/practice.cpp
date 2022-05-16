#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

/*

	시퀀스 컨테이너(원소 자체를 보관하는 컨테이너)
		- 일반적인 상황에서는 벡터를 사용한다.(만능)
		- 맨약 맨 끝이 아닌 중간에 원소들을 추가하거나 제거하는 일을 많이 하고, 원소들을 순차적으로만 접근한다면 리스트를 사용한다.
		- 만약 맨 처음과 끝 모두에 원소들을 추가하는 작업을 많이 사용하면 덱을 사용한다.

	벡터
		벡터는 임의의 위치에 있는 원소의 접근을 빠르게 수행한다.(O(1))
		맨 뒤에 새로운 원소를 추가하거나 제거하는 것 역시 빠르게 수행한다.
		그러나 임의의 위치에 원소를 추가하는 것은 O(n)으로 느리다.
		새로운 원소를 추가하거나 뺄 경우 그 뒤에 오는 원소들을 한 칸씩 이동시켜 주어야 하므로 n번의 복사가 필요하다.

		size() : 벡터의 크기를 리턴하는 함수
		size_type : size()의 리턴하는 값의 타입
		insert() : 벡터에 요소 추가
		erase(삭제할 위치) : 벡터의 요소 삭제
			erase(삭제할 처음 위치, 삭제할 마지막 위치) : 지정한 범위만큼 요소 삭제
		vector의 index는 unsigned int이다.

		벡터는 현재 가지고 있는 원소의 개수보다 더 많은 공간을 할당해 놓고 있다.
		그러므로 새로운 원소를 추가하게 된다면 새롭게 메모리를 할당할 필요가 없이,
		이미 할당된 공간에 그 원소를 쓰기만 하면 된다.

		그러나 할당된 공간을 다 채웠을 때는 새로운 큰 공간을 다시 할당하고 기존의 원소를 복사하는 수 밖에 없다.
		하지만 n개의 원소를 모두 복사하는 경우(O(n))는 매우 드물기 때문에 전체적으로 평균을 내보았을 때 O(1)로 수행된다.

		벡터 컨테이너에 원소를 추가하거나 제거하게 되면 기존에 사용하였던 모든 반복자들을 사용할 수 없게 된다.

	리스트
		양방향 링크드 리스트 구조를 가진 자료형
		vector와는 달리 임의의 위치에 있는 원소에 접근을 바로 할 수 없다.
		list 컨테이너 자체는 시작 원소와 마지막 원소만을 기억하기 때문에 임의의 원소에 접근하기 위해서는 하나씩 링크를 따라가야 한다.
		하지만 임의의 원소를 추가하거나 제거하는 작업이 빠르게 수행된다. (원하는 위치 앞과 뒤에 있는 링크 값만 바꿔주면 되기 때문)

		벡터와는 달리 원소를 추가하거나 지워도 반복자가 무효화되지 않는다. 각 원소들의 주소값은 바뀌지 않기 때문이다.

		리스트는 한 번에 한 칸만 이동이 가능하기 때문에 리스트의 반복자는 단항 증감 연산자만 사용 가능하다(itr++, itr-- ..)
		리스트의 반복자 타입은 BidirectionalIterator이며 벡터의 반복자 타입은 BidirectionalIterator를 상속받는 RandomAccessIterator이다.

	deque(double ended queue)
		벡터와 비슷하게 O(1)로 임의의 위치에 접근할 수 있으며 맨 뒤에 원소를 추가/제거하는 작업도 빠르게 수행할 수 있다.
		뿐만 아니라 맨 앞에 원소를 추가/제거하는 작업까지도 O(1)으로 수행 가능하다.
		하지만 덱의 경우 벡터와는 달리 원소들이 실제로 메모리 상에서 연속적으로 존재하지 않는다.
		이 때문에 원소들이 어디에 저장되어 있는지에 대한 정보를 보관하기 위해 추가적인 메모리가 더 필요하다.
		즉, 실행속도를 위해 메모리를 많이 희생하는 컨테이너이다.



 */

/*

	반복자(iterator)
	컨테이너의 원소에 접근할 수 있는 포인터같은 객체

	begin() : 첫번 째 원소를 가리키는 반복자를 리턴한다.
	end() : 마지막 원소의 한칸 뒤를 가리키는 반복자를 리턴한다.
		(이를 통해 빈 벡터를 표현할 수 있다 (begin() == end()))


 */

/*
	연관 컨테이너(associative container)

	데이터의 존재 유무만 궁금한 경우 : set
	데이터에 대응되는 데이터를 저장하고 싶은 경우 : map

	키 - 값 구조를 가진 컨테이너
	특정한 키를 넣으면 이에 대응되는 값을 돌려준다.
	set multiset map multimap

	- 특정 키가 연관 컨테이너에 존재하는지 여부 : set, multiset
	- 특정 키에 대응되는 값이 무엇인지 : map, multimap
	map과 multimap을 set처럼 쓸 수 있지만, 메모리가 크기 때문에 키의 존재유무만 알고싶지만 set을 쓰는것이 좋다.

	set
		시퀀스 컨테이너처럼 '어디에' 추가할지에 대한 정보가 없다. insert를 사용하면 순차적으로 추가되며
		시퀀스 컨테이너가 상자 하나에 원소를 한개씩 담고 각 상자에 번호를 매긴 것이라면,
		set은 그냥 큰 상자 안에 모든 원소들을 쑤셔 넣은 것이라 보면 된다.
		(원소가 어디 있는가가 중요하지 않고 해당 원소가 '있는지 없는지'에 대한 정보가 중요하다.)
		셋에 원소를 추가하거나 지우는 작업은(O(logN)) 시퀀스 컨테이너의 원소를 지우는 작업(O(N))보다 빠르다.

		반복자 타입은 BidirectionalIterator으로 리스트처럼 순차적으로 하나씩 접근하는것만 가능하다.
		넣었을 때와 출력했을 떄의 순서가 다른데, 내부에 원소를 추가할 때 정렬된 상태를 유지하며 추가한다.(내부적으로 트리 구조로 작성되어 있다.)
		set에 find 함수가 제공되며 원소가 존재하는지 확인할 수 있다. 트리구조로 되어있기에 O(logN)의 검색 속도가 보장된다.
		값이 동일한 원소를 insert하여도 이미 같은 원소가 있다면 무시되므로 중복된 원소가 존재하지 않는다.

		직접 만든 클래스 객체를 set에 넣고 싶을 때 Todo 클래스를 사용한다.
		Todo 클래스는 2개의 멤버 변수를 가지는데 하나는 일의 중요도이고 하나는 해야 할 일의 설명이다.

	map
		set과 거의 비슷한 자료구조이다. 다만 set의 경우 key를 보관했지만, map의 경우 key에 대응되는 값(value)까지 같이 보관한다.
		map의 insert 함수는 pair객체를 인자로 받는다.
		맵의 경우 템플릿 인자로 2개를 가지는데 첫 번째는 키의 타입이고 두 번쨔는 값의 타입이다.

		아래 map에 insert하는 부분은 세가지 다 동일한 추가방법이다.
		std::map<std::string, double> pitcher_list;
		pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
		pitcher_list.insert(std::make_pair("차우찬", 3.04));
		pitcher_list["니퍼트"] = 3.56;

	multiset, multimap
		set과 map이랑 동일하지만 중복된 원소를 허용한다는 특징이 있다.

	C++11에 추가된 unordered_set과 unordered_map은 원소를 insert할 때 자동으로 정렬해주지 않는다.(랜덤으로)

 */


/*
	컨테이너 어댑터(Container Adaptor)
		다른 컨테이너 클래스를 상속 받아서 다른 컨테이너 클래스의 객체에 특정한 인터페이스를 제공해준다.
		stack(LIFO)
		queue(FIFO)

 */
/*
	알고리즘
		컨테이너에 반복자들을 가지고 이런 저런 작업을 쉽게 수행할 수 있도록 도와주는 라이브러리
		알고리즘 함수들의 대부분 형태는 다음과 두개의 형태와 같다.

		알고리즘을 수행할 반복자의 시작점과 끝점 바로 뒤를 받는다.
		template <typename Iter>
		void do_something(Iter begin, Iter end);

		알고리즘을 수행할 반복자의 시작점과 끝점 바로 뒤를 받고, '특정한 조건'을 추가 인자로 받는다.
		이러한 특정한 조건을 '서술자(Predicate)'라고 부르며 보통 bool을 리턴하는 함수 객체(Functor)을 전달하게 된다.
		template <tepename Iter, typename Pred>
		void do_something(Iter begin, Iter end, Pred pred);

		정렬 알고리즘
			sort : 일반적인 정렬 함수
				sort(vec.begin(), vec.end());
				정렬할 원소의 시작 위치와 마지막 위치 바로 뒤를 반복자로 받는다.
				sort에 들어가는 반복자의 경우 반드시 임의접근 반복자(RandomAccessIterator) 타입을 만족해야 하므로 vector와 deque만 사용이 가능하다.
				default로 오름차순 정렬을 해주며 내림차순으로 정렬하고 싶다면 세번 째 인자에 greater<type>()을 넣어주면 된다.
			stable_sort : 정렬을 하되 원소들간의 순서를 보존한다.
				예를 들어 벡터에 [a, b] 순으로 있었는데 정렬할 때 a, b가 크기가 같다면 a, b 또는 b, a로 할 수 있다.
				sort의 경우 랜덤으로 순서가 정해지지만 stable_sort의 경우는 순서를 보존한다.(컨테이너 상에서 있던 순서로)
				하지만 그 때문에 sort보다는 좀 더 느리다.
			partial_sort
				배열의 일부분만 정렬한다.
				std::partial_sort(start, middle, end);
				전체 원소들 중에서 start부터 middle까지만 제일 작은 순으로 정렬한다.
		원소 삭제 알고리즘
			remove
				vec.erase(remove(vec.begin(), vec.end(), 3), vec.end());
					remove()를 이용해서 값이 3인 원소들을 뒤로 보내버리고,
					erase를 이용해 그 원소들을 삭제한다.
					remove는 반복자 타입이 ForwardIterator라 모든 컨테이너에서 사용이 가능하다.
			remove_if
				값 뿐만 아니라 특정한 조건을 만족하는 원소들을 제거
				세번 째 인자로 조건을 설명할 함수 객체를 전달받는다.
				is_odd 구조체에 operator()를 만들어서 함수 객체를 전달하면 된다.
		원소 탐색 알고리즘
			find
				find는 아래처럼 생겼다.
				template <class InputIt, class T>
				InputIt find(InputIt first, InputIt last, const T& value);
				first부터 last까지 순회하면서 value와 같은 원소가 있는지 확인하며, 있으면 이를 가리키는 반복자를 리턴한다.
				컨테이너에 중복되는 값이 있더라도 가장 먼저 찾은 것을 리턴한다.
				모든 중복되는 값을 찾고싶다면 반복문을 이용하면 된다.
				컨테이너에서 기본적으로 find 함수를 지원한다면 그 find 함수를 사용하는 것이 훨씬 빠르다.
				왜냐하면 알고리즘의 find 함수는 그 컨테이너가 어떠한 구조를 가지고 있는지에 대한 정보가 없기 때문이다.
				따라서 find 함수를 사용할 경우 벡터와 같이 기본적으로 find를 지원하지 않는 컨테이너에 사용해야 한다.
			any_of, all_of
				any_of : 인자로 받은 범위안의 모든 원소들 중에서 조건을 하나라도 충족하는 것이 있다면 true를 리턴한다.(OR연산과 비슷)
				all_of : 모든 원소들이 전부 조건을 충족해야 true를 리턴한다.(AND 연산과 비슷)

		원소 수정 알고리즘
			transform
				모든 원소에 1씩 더한다 같은 작업을 한다.
				std::transform(시작 반복자, 끝 반복자, 결과를 저장할 컨테이너의 시작 반복자, Pred)
				std::transform(vec.begin(), vec.end(), vec.begin(), [](int i) {return i + 1});
				= vec의 시작(begin)부터 끝(end)까지 각 원소에 [] (int i) {return i + 1} 함수를 적용시킨 결과를 vec.begin()부터 저장한다.

		람다 함수
			C++11에서 도입되었다.
			[capture list] (받는 인자) -> 리턴 타입 { 함수 본체 };
			[](int i) -> bool { return i % 2 == 1; }

 */

// 전체 벡터 출력하는 템플릿 함수(전체 벡터를 iterator으로 출력하기)
template <typename T>
void print_vector(std::vector<T> &vec)
{
	// 템플릿 버전의 경우 typename을 추가해줘야 한다.
	// iterator가 std::vector<T>의 '의존타입'이기 때문이다.
	// 컴퓨터 입장에서는 type인지 value인지 알 수 없어서 typename을 명시해 타입임을 알려주는 것
	// (기본적으로 값으로 생각한다.)
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 4; i++)
		vec.push_back(i * 10);

	// 전체 벡터를 벡터.size() 함수로 출력하기
	// for (std::vector<int>::size_type i = 0; i < vec.size(); i++)
	// {
	// 	std::cout << "vec의 " << i + 1 << "번째 원소 :: " << vec[i] << std::endl;
	// }

	print_vector(vec);

	vec.insert(vec.begin() + 2, 15); // vec[2] 앞에 값 15를 추가한다.
	// vec.erase(vec.begin() + 3); // vec[3] 제거

	// 아래 두 반복문은 동일안 일을 하지만, 첫 번째 반복문은 erase()하고 처음부터 다시 찾으므로 비효율적이다.
	// std::vector<int>::iterator itr = vec.begin();
	// for (; itr != vec.end(); ++itr)
	// {
	// 	if (*itr == 20)
	// 	{
	// 		vec.erase(itr);
	// 		itr = vec.begin();
	// 	}
	// }

	for (std::vector<int>::size_type i = 0; i != vec.size(); i++)
	{
		if (vec[i] == 20)
		{
			vec.erase(vec.begin() + i);
			i--;
		}
	}

	print_vector(vec);

	// 배열을 가리키는 포인터와 똑같이 동작한다.
	std::vector<int>::iterator itr = vec.begin() + 2;
	// * 연산자를 오버로딩해서 마치 포인터처럼 동작하게 만든 것이다.
	std::cout << "3 번째 원소 :: " << *itr << std::endl;

	std::list<int> lst;
	for (int i = 0; i < 4; i++)
	{
		// lst[i] = i * 10; // list에는 []연산자로 접근할 수 없다.
		lst.push_back(i * 10);
	}
	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << std::endl;


}