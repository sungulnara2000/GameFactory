#include "abstract_factory.h"
#include "units.h"

template<typename T>
struct Allocator {
    T* allocate() {
        return new T();
    }
};

template<typename T, template<typename> typename Allocator>
struct UnitFactory {
    T* create_unit(Allocator<T>& allocator) {
        return allocator.allocate();
    }
};

int main() {
    IAbstractFactory<GameUnits>* game_factory = new FactoryWithAllocator<GameUnits, Allocator, UnitFactory>();

    Cavalry* cavalry = game_factory->create_unit<Cavalry>();
    Infantry* infantry = game_factory->create_unit<Infantry>();
    Archer* archer = game_factory->create_unit<Archer>();

    std::cout << cavalry->name << std::endl;
    std::cout << infantry->name << std::endl;
    std::cout << archer->name << std::endl;

    return 0;
}