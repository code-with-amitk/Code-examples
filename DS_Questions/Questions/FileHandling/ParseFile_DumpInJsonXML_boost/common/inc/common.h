#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/tokenizer.hpp>
#include <boost/program_options.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include "null_pointer_exception.h"
#include "exception.h"

namespace po = boost::program_options;
namespace pt = boost::property_tree;

using _HResult = int;
using String        = std::string;
using VectorInt     = std::vector<int>;
using VectorString  = std::vector<std::string>;
using Pair          = std::pair<String, int>;
using VectorPair    = std::vector<Pair>;
using SetString     = std::set<String>;

//typedef boost::tokenizer<boost::char_separator<char>> tokenizer;//boost::char_separator<char> sep{" ", "\t"};

//boost::escaped_list_separator<wchar_t> separator(space, delim);
//boost::tokenizer<boost::escaped_list_separator<wchar_t>, std::wstring::const_iterator, std::wstring> tok(str, separator);

constexpr auto E_SUCCESS    = 1;
constexpr auto E_FAIL       = -1;
