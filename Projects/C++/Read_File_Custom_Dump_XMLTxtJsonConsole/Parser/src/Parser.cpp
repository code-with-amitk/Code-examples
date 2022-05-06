#include "Parser.h"

VectorPair Parser::GetTopXUsedWords(int x)
{
    VectorPair vecPWords;

    _TRY
        std::unordered_map<String, int>::iterator it;
        for (int i=0; i < x; ++i){
            it = std::max_element(umWordCount.begin(),
                                  umWordCount.end(), comparator);
            vecPWords.emplace_back(it->first, it->second);
            umWordCount.erase(it);
        }
    _CATCH_BADALLOC
    _CATCH_ALL
    _END
    return vecPWords;
}

_HResult Parser::ParseFile ()
{
    _HResult ret = E_FAIL;
    ret = OpenFile();
    if (ret == E_SUCCESS)
        ReadFile();
    return ret;
}

_HResult Parser::OpenFile ()
{
    _HResult ret = E_FAIL;

    _TRY
        //Create path object containing path of file
        boost::filesystem::path file = strFilePath;

        //Open file using path object
        oStream.open(file, std::ifstream::binary);

        if (!oStream.is_open() && !oStream.good()) {
            std::cout << "Cannot open file" << strFilePath << std::endl;
        } else {
            std::cout << "Reading from " << strFilePath << std::endl;
            ret = E_SUCCESS;
        }

    _CATCH_BOOST_FILESYSTEM_ERROR
    _CATCH_ALL
    _END
    return ret;
}

_HResult Parser::ReadFile() {
    _HResult ret = E_FAIL;
    String strLine, strWord;
    uint32_t u32Index = 0;

    _TRY
        while (oStream.eof() != 1){
            std::getline (oStream, strLine);

            tokenizer tok{strLine, sep};
            for (const auto &t:tok) {
                if (!IsSmiley(t)) {
                    umWordCount[t]++;
                } else {
                    vecSmileysIndex.push_back(u32Index);
                }
                u32Index++;
            }
        }
        ret = E_SUCCESS;

    _CATCH_IOS_BASE_FAILURE
    _CATCH_BADALLOC
    _CATCH_ALL
    _END
    return ret;
}
