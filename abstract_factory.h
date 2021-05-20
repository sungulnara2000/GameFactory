#ifndef ABSTRACT_FACTORY_ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_ABSTRACT_FACTORY_H

#include "hierarchies.h"

template<
        template<typename, template<typename> typename> class UnitFactory,
        template<typename> class Allocator,
        typename T,
        typename Base
>
struct UnitFactoryWithAllocator : UnitFactory<T, Allocator>, Base {
public:
    virtual T *create_unit(T) {
        return UnitFactory<T, Allocator>::create_unit(allocator);
    }
private:
    Allocator<T> allocator;
};


template<
        template<typename, template<typename> typename> class UnitFactory,
        template<typename> typename Allocator
>
struct UnitFactoryFromBaseCreator {
    template<typename T, typename Base>
    using UnitFactoryFromBase = UnitFactoryWithAllocator<UnitFactory, Allocator, T, Base>;
};

//---------------------------------------------------------------------------------


template<typename T>
struct IAbstractUnitFactory {
    virtual T *create_unit(T) = 0;
};


template<typename TypeList>
struct IAbstractFactory : GenScatterHierarchy<TypeList, IAbstractUnitFactory> {
    template<typename T>
    T *create_unit() {
        T* created = new T;
        return created;
    }
};

//---------------------------------------------------------------------------------

template<
        typename TypeList,
        template<typename> typename Allocator,
        template<typename, template<typename> typename> typename UnitFactory
>
using FactoryWithAllocator = GenLinearHierarchy<
        TypeList,
        UnitFactoryFromBaseCreator<UnitFactory, Allocator>::template UnitFactoryFromBase,
        IAbstractFactory<TypeList>
>;

#endif //ABSTRACT_FACTORY_ABSTRACT_FACTORY_H
