#pragma once

#include <vector>

template<typename TElem>
class Repository {
private:
    std::vector<TElem> elements;

public:
    Repository();

    Repository(const Repository &newRepository);

    void add(TElem element);

    void remove(TElem element);

    void update(TElem oldElement, TElem newElement);

    int getSize();

    std::vector<TElem> getElements();

    ~Repository();
};

template<typename TElem>
Repository<TElem>::Repository() {
    this->elements = std::vector<TElem>();
}

template<typename TElem>
Repository<TElem>::Repository(const Repository &newRepository) {
    this->elements.clear();
    this->elements = newRepository.elements;
}

template<typename TElem>
void Repository<TElem>::add(TElem element) {
    this->elements.push_back(element);
}

template<typename TElem>
void Repository<TElem>::remove(TElem element) {
    this->elements.erase(std::remove(this->elements.begin(), this->elements.end(), element), this->elements.end());
}

template<typename TElem>
int Repository<TElem>::getSize() {
    return this->elements.size();
}

template<typename TElem>
std::vector<TElem> Repository<TElem>::getElements() {
    return this->elements;
}

template<typename TElem>
void Repository<TElem>::update(TElem oldElement, TElem newElement) {
    this->remove(oldElement);
    this->add(newElement);
}

template<typename TElem>
Repository<TElem>::~Repository() = default;
