#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"


int main()
{
    {
        //---------SUBJECT-MAIN---------//
    cout << "\t--EXECUTING SUBJECT MAIN--" << endl << endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    cout << endl;
    }
    {
    //Testing unequip and use of unequiped materia.
    cout << "\t--EXECUTING OTHER TESTS--" << endl << endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* ice;
    AMateria* cure;
    ice = src->createMateria("ice");
    me->equip(ice);
    cure = src->createMateria("cure");
    me->equip(cure);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    cout << "\033[3m\t-unequiping slot 1\033[0m" << endl;
    me->unequip(1);
    cout << "\033[3m\t-trying to use slot 1\033[0m" << endl;
    me->use(1, *bob);
    cout << "\033[3m\t-unequiping slot 1 again\033[0m" << endl;
    me->unequip(1);
    delete cure;
    delete bob;
    delete me;
    delete src;
    }
    {
    //This test create a Character object and add the same "Ice" object 4 times (same pointer)
    //--testing double free and leaks, max adds..
    cout << "\t--EXECUTING SAME ITEM TESTS--" << endl << endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    ICharacter* me = new Character("me");
    AMateria* ice;
    ice = src->createMateria("ice");
    cout << "\033[3m\t-equiping same object 6 times\033[0m" << endl;
    me->equip(ice);
    me->equip(ice);
    me->equip(ice);
    me->equip(ice);
    me->equip(ice);
    me->equip(ice);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;   
    }
    {
    //This test create MateriaSource and add one "Ice" object, creates a clone (new one)
    // and add it 3 times to the MateriaSource object, testing double free and leaks, max adds..
    cout << "\t--EXECUTING MATERIA SOURCE TESTS--" << endl << endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    AMateria* ice;
    ice = src->createMateria("ice");
    cout << "\033[3m\t-adding same object 5 more times\033[0m" << endl;
    src->learnMateria(ice);
    src->learnMateria(ice);
    src->learnMateria(ice);
    src->learnMateria(ice);
    src->learnMateria(ice);
    
    delete src;   
    }
}