## class options_description 
```c++
//In header: /usr/include/boost/program_options/options_description.hpp

class options_description_easy_init {
public:
  options_description_easy_init(options_description* owner);
  options_description_easy_init& operator()(const char* name, const char* description);

private:
  options_description* owner;
};
    
class options_description {
public:
  //Constructor
  options_description(const std::string &, unsigned = m_default_line_length, unsigned = m_default_line_length/2);
  
  options_description_easy_init add_options();
};
```
