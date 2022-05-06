#include "common.h"

#define OUTPUT_ERROR \
    std::cout << e.what() << std::endl;

#define _TRY \
    try {

#define _CATCH_ALL \
    } catch (...) { \
        std::cout << "Exception Occurred" << std::endl;

#define _CATCH_BADALLOC \
   } catch (std::bad_alloc& e) { \
        OUTPUT_ERROR

#define _CATCH_IOS_BASE_FAILURE \
    } catch(const std::ios_base::failure& e) { \
        OUTPUT_ERROR

#define _CATCH_NULL_POINTER \
    } catch (const NULLException& e ) { \
        OUTPUT_ERROR

#define _CATCH_STD_EXCEPTION \
    } catch (std::exception &e) { \
        OUTPUT_ERROR

//Boost Exceptions
#define _CATCH_BOOST_FILESYSTEM_ERROR \
   } catch(const boost::filesystem::filesystem_error& e) { \
        OUTPUT_ERROR

#define _CATCH_BOOST_XML_PARSER_ERROR \
   } catch(const boost::property_tree::xml_parser::xml_parser_error& e){ \
        OUTPUT_ERROR

#define _CATCH_BOOST_TOO_MANY_POSITIONAL_OPTIONS \
    } catch (po::too_many_positional_options_error &e) { \
        OUTPUT_ERROR

#define _CATCH_BOOST_UNKNOWN_OPTION \
    } catch (po::unknown_option &e) { \
        OUTPUT_ERROR
