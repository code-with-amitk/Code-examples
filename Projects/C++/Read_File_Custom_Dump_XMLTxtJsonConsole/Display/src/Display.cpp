#include "Display.h"

_HResult Display::CreateStream(Parser &oParser,
                               std::stringstream& ss,
                               VectorPair& vecPTopXWords,
                               VectorInt& vecISmileyIndex) const
{
    _HResult ret = E_FAIL;
    _TRY
        //std::cout << std::setw(2) << std::setfill('0');
        ss << std::endl << m_strTopWords << std::endl
           << "Word : Count" << std::endl;
        vecPTopXWords = oParser.GetTopXUsedWords(10);
        for (auto i:vecPTopXWords)
            ss << i.first << " : " << i.second << "\n";

        ss << std::endl << m_strSmileyIndex << std::endl;

        vecISmileyIndex = oParser.GetSmileysIndex();
        for (auto i:vecISmileyIndex)
            ss << i << " ";
        ss << std::endl;
        ret = E_SUCCESS;

    _CATCH_ALL
    _END
    return ret;
}

_HResult Display::Dump(Parser &oParser) const
{
    _HResult ret = E_FAIL;

    std::stringstream ss, ss1;
    VectorInt vecISmileyIndex;
    VectorPair vecPTopXWords;
    std::streambuf* sStream = nullptr;

    _TRY
        if (CreateStream(oParser, ss,
                         vecPTopXWords,
                         vecISmileyIndex) == E_FAIL)
            return ret;

        if ((sStream = ss.rdbuf()) == nullptr)
            throw NULLException ("ss1 << rdbuf");
        ss1 << sStream;

        for (auto i : m_vstrWhere) {
            if (!i.compare("console")) {
                std::cout << ss.str();
                ret = E_SUCCESS;
            }
            if (!i.compare("file")) {
                std::ofstream oFile("output.txt");
                if ((sStream = ss1.rdbuf()) == nullptr)
                    throw NULLException ("oFile << rdbuf");
                oFile << sStream;

                oFile.close();
                ret = E_SUCCESS;
            }
            if (!i.compare("xml")) {
               ret = DumpToXML(vecPTopXWords, vecISmileyIndex);
            }
            if (!i.compare("json")) {
               ret = DumpToJson(vecPTopXWords, vecISmileyIndex);
            }
        }

    _CATCH_NULL_POINTER
    _CATCH_ALL
    _END
    return ret;
}

_HResult Display::DumpToJson(VectorPair& vecPTopXWords,
                            VectorInt& vecIndex) const
{
    _HResult ret = E_FAIL;
    pt::ptree root;

    _TRY
        //Will use vecPTopXWords as such
        pt::ptree top_words;
        for (auto &i:vecPTopXWords)
            top_words.put(i.first, i.second);
        root.add_child("top_words", top_words);

        pt::ptree index_of_smileys;
        for (auto &i:vecIndex) {
            pt::ptree temp;
            temp.put_value(i);
            index_of_smileys.push_back(std::make_pair("", temp));
        }
        root.add_child("index_of_smileys", index_of_smileys);

        pt::write_json(m_strJsonFile, root);

        ret = E_SUCCESS;

    _CATCH_BOOST_XML_PARSER_ERROR
    _CATCH_BADALLOC
    _CATCH_ALL
    _END
    return ret;
}

_HResult Display::DumpToXML(VectorPair& vecPTopXWords,
                            VectorInt& vecIndex) const
{
    _HResult ret = E_FAIL;
    VectorString vecStrTopWords;

    _TRY
        //Create VectorString from VectorPair
        for (const auto &i:vecPTopXWords) {
            String strTemp = i.first;
            strTemp.append(", ");
            std::stringstream ss;
            ss << i.second;
            strTemp.append(ss.str());
            vecStrTopWords.push_back (strTemp);
            strTemp.clear();
        }

        //Create empty property tree object
        pt::ptree tree;

        //Add all the modules. Unlike put, which overwrites existing nodes
        //add() adds a new node at the lowest level, so the "modules" node will have
        // multiple "module" children.
        BOOST_FOREACH(const std::string &s, vecStrTopWords)
            tree.add("output.top_words.word", s);

        BOOST_FOREACH(const int &i, vecIndex)
            tree.add("output.indexes_of_smileys.index", i);

        // Write property tree to XML file
        String strFile = "output.xml";
        pt::write_xml(strFile, tree);

        ret = E_SUCCESS;

    _CATCH_BADALLOC
    _CATCH_BOOST_XML_PARSER_ERROR
    _CATCH_STD_EXCEPTION
    _CATCH_ALL
    _END
    return ret;
}
_HResult Display::OutputOptions (int ac, char** av)
{
    _HResult ret = E_FAIL;
    po::options_description desc("Allowed options");

    _TRY
        desc.add_options()
        ("help", "produce help message")
        ("display,d", po::value<VectorString>(&m_vstrWhere)->multitoken(),
                     "console | file | xml | json");

         if (ac == 1) {
            std::cout << desc << std::endl;
         }
         else {
            po::variables_map vm;
            po::store(po::parse_command_line(ac, av, desc), vm);
            po::notify(vm);

            if (vm.count("help")) {
                std::cout << desc << "\n";
                ret = E_FAIL;
            }
            else {
                for (const auto &i:m_vstrWhere)
                    std::cout << i << " ";
                std::cout << "\n";
                ret = E_SUCCESS;
            }
        }

    _CATCH_BOOST_TOO_MANY_POSITIONAL_OPTIONS
    _CATCH_BOOST_UNKNOWN_OPTION
    _CATCH_ALL
    _END
    return ret;
}
