#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
/*
	IMateriaSource 인터페이스를 상속받는 클래스

	learnMateria() : 인자의 Materia를 복사해야하며, 나중에 복제하기 위해 메모리에 저장해야 함. Character 와 거의 같은 방식으로,
		Source는 최대 4개의 속성(Materia)를 알 수 있으며, 반드시 고유할 필요는 없음.

	createMateria() : 새로운 속성(Materia)를 반환함. 이 속성(Materia)은 유형이 인자와 동일한
		속성(Materia)(Source에서 이전에 learnMateria 했던.)의 복사본이 됨. 타입을 알 수 없는 경우에는 0이 반환됨.
		간단히 말해서, Source는 속성(Materia)의 “템플릿”을 학습하고, 필요에 따라 재생성할 수 있어야 함.
		그러면 속성(Materia)의 “실제” 유형을 몰라도, 그냥 문자열(string) 만으로 식별할 수 있게 됨.

	LearnMateria는 매개변수로 전달된 Materia를 Character와 같은 방식으로 저장.
	createMateria는 매개변수로 전달된 type이 가지고 있는 Materia를 반환.
 */

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_aMateria[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		MateriaSource &operator=(const MateriaSource &copy);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria *createMateria(std::string const &type);

};

#endif