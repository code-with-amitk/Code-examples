#pragma once
#include "Parser.h"

class Display {
public:
    _HResult OutputOptions (int ac, char** av);
    _HResult Dump(Parser&) const;
    _HResult DumpToXML(VectorPair&, VectorInt&) const;
    _HResult DumpToJson(VectorPair&, VectorInt&) const;
    _HResult CreateStream(Parser&, std::stringstream&,
                          VectorPair&, VectorInt&) const;
private:
    //constexpr require cxx17
    const String m_strTopWords = "Top X used Words";
    const String m_strSmileyIndex = "Indexes of Smileys";
    const String m_strXMLFile = "./output.xml";
    const String m_strTxtFile = "./output.txt";
    const String m_strJsonFile = "./output.json";
    VectorString m_vstrWhere;
};
