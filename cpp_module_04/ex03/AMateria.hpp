#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

/*
	속성(Materia) Ice, Cure를 만듦. 이 유형들은 lowercase의 이름을 가짐. (Ice는 “ice”, 등등..)

	clone() 메서드가 있고, 이것은 당연히 실제 속성(Materia) 유형의 새로운 인스턴스를 반환함.

	use(ICharacter&) 메서드를 사용하면, 다음과 같이 출력함.
	Ice: “* shoots an ice bolt at NAME *”
	Cure: “* heals NAME’s wounds *”
	(물론, NAME 은 인자로 주어진 Character에서 얻어와 대치해야함.)

	(⚠️ 속성(Materia)을 다른 속성에 대입(assigning)하면서, 유형을 복사하는 것은 의미가 없습니다…)
 */
class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(const AMateria &copy);
		AMateria &operator=(const AMateria &copy);
		virtual ~AMateria();

		AMateria(std::string const & type);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
