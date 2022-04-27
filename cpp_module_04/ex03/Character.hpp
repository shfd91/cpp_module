#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
/*
	ICharacter 인터페이스를 상속받은 클래스

	캐릭터는 처음에 최대 4개의 비어있는 속성(Materia) 인벤토리를 가짐. 그리고 속성(Materia)을 슬롯 0에서 슬롯 3까지 순서대로 장착함.
	만약 인벤토리가 가득 찬 상태에서 장착하려고 하거나, 없는 속성(Materia)을 사용/장착해제 하려고 했을 땐 아무 것도 하지 않아야 함.
	장착해제 메서드는 절대 속성(Materia)을 delete 해서는 안됨.
	use(int, ICharacter&) 메서드는 idx 슬롯의 속성(Materia)을 사용해야만 함. 그리고 target을 AMateria::use 메서드의 인자로 넘겨야 함.
	(⚠️ 물론, 캐릭터의 인벤토리는 어떠한 AMateria도 지원할 수 있게 해야함.)

	당신의 Character는 이름을 인자로 받는 생성자를 가지고 있어야 함.
	당연히 Character의 복사 또는 대입(assignation) 역시도 “deep” 해야함.
	Character의 예전 속성(Materia)는 삭제되어야만 함. 캐릭터의 소멸에서도 같아야 함.

	최대 4개의 AMateria를 보유하고 있으며, 0~3순으로 사용
	equip을 할때 4개 모두 보유하고 있으면 못해야함.
	use/unequip 할때 무기가 아예 없으면 못해야함.
	unequip은 delete를 하면 안된다.
	use를 할때, AMateria::use로 target을 보내야한다.
 */

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_aMateria[4];
	public:
		Character();
		Character(const Character &copy);
		Character &operator=(const Character &copy);
		~Character();

		Character(const std::string &name);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif

