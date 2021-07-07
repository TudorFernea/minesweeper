

#include "Source.h"

#include <utility>

std::string SourceFile::getName() {
    return this->name;
}

std::string SourceFile::getStatus() {
    return this->status;
}

std::string SourceFile::getCreator() {
    return this->creator;
}

std::string SourceFile::getReviewer() {
    return this->reviewer;
}

SourceFile::SourceFile(std::string s1, std::string s2, std::string s3, std::string s4) : name(std::move(s1)), status(std::move(s2)),
                                                                                         creator(std::move(s3)), reviewer(std::move(s4)) {

}

void SourceFile::setName(std::string value) {
    this->name = std::move(value);
}

void SourceFile::setStatus(std::string value) {
    this->status = std::move(value);
}

void SourceFile::setCreator(std::string value) {
    this->creator = std::move(value);
}

void SourceFile::setReviewer(std::string value) {
    this->reviewer = std::move(value);
}

void swap(SourceFile &s1, SourceFile &s2) {
    using std::swap;
    swap(s1.name,s2.name);
    swap(s1.status,s2.status);
    swap(s1.creator,s2.creator);
    swap(s1.reviewer,s2.reviewer);
}

bool SourceFile::operator==(const SourceFile &sf) {
    return this->name == sf.name && this->status == sf.status && this->creator == sf.creator && this->reviewer == sf.reviewer;
}

