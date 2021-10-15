#pragma once
#include "common.h"

class Parser {
public:
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    boost::char_separator<char> sep{" /\t"};
    std::unordered_set<String> usSmileys = {
        ":(", ":-]", ":]"
    };

    Parser(std::string& strPath):strFilePath(strPath){}
    VectorPair GetTopXUsedWords(int x);
    _HResult ParseFile();
    inline __attribute__((always_inline)) VectorInt GetSmileysIndex()
    noexcept{
        return vecSmileysIndex;
    }
private:
    boost::filesystem::ifstream oStream;
    String strFilePath;
    std::unordered_map<String, int> umWordCount;
    VectorInt vecSmileysIndex;

    _HResult OpenFile();
    _HResult ReadFile() noexcept(false);
    inline __attribute__((always_inline)) bool IsSmiley(const String& strWord)
    noexcept(true) {
        return (usSmileys.find(strWord) != usSmileys.end()) ? true : false;
    }
    static inline __attribute__((always_inline)) bool comparator(Pair p1, Pair p2){
        return p1.second < p2.second;
    }
};
