#ifndef ABSTRACT_FACTORY_HIERARCHIES_H
#define ABSTRACT_FACTORY_HIERARCHIES_H

#include "TypeList.h"

//-----------------------------------SCATTER-----------------------------------

template<class TList, template<class> class Unit>
struct GenScatterHierarchy;

template<class ... Types, template<class> class Unit>
struct GenScatterHierarchy<TypeList<Types...>, Unit> : public Unit<Types> ... {};

//-----------------------------------LINEAR-------------------------------------

template <class TList, template <class, class> class Unit, class Root = NullType>
class GenLinearHierarchy;

template<class T1, class ... T2, template<class, class> class Unit, class Root>
class GenLinearHierarchy<TypeList<T1, T2...>, Unit, Root> :
        public Unit<T1, GenLinearHierarchy<TypeList<T2..., NullType>, Unit, Root>> {
};

template<class T, template<class, class> class Unit, class Root>
class GenLinearHierarchy<TypeList<T, NullType>, Unit, Root> :
        public Unit<T, Root> {};

#endif //ABSTRACT_FACTORY_HIERARCHIES_H
