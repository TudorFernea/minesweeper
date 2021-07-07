#pragma once

#include <string>

class SourceFile {
private:
    std::string name;
    std::string status;
    std::string creator;
    std::string reviewer;

public:
    SourceFile(std::string s1, std::string s2, std::string s3, std::string s4);

    std::string getName();

    std::string getStatus();

    std::string getCreator();

    std::string getReviewer();

    void setName(std::string value);

    void setStatus(std::string value);

    void setCreator(std::string value);

    void setReviewer(std::string value);

    friend void swap(SourceFile& s1, SourceFile& s2);

    bool operator==(const SourceFile& sf);

    ~SourceFile() = default;
};

