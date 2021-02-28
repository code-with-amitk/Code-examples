#include<tuple>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<iostream>
#include<unordered_map>
#include<boost/any.hpp>
#include<boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

class Spend{
  using String = std::string;
  String m_strCity;

  typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
  tokenizer::iterator it;
  boost::char_separator<char> sep{","};

  //std::unordered_map<String,std::pair<boost::any,boost::any>> umTable03;
  std::unordered_map<String,std::pair<double,double>> umTable03;
  std::vector<int> vecTable02;

  //city,HouseNo,Num_Res_Age0,Num_Res_Age1,Num_Res_Age2,Num_Res_Age3
  std::vector<std::vector<boost::any>> m_vecTable01;
public:

  bool ParseTable01();

  //Parse Table02 and store in umTable02
  bool ParseTable02();

  //Parse Table03 and store m_vecTable01
  bool ParseTable03();

  std::vector<String> ReadUserInput();
  double FindSpending(std::vector<String>&);

  double CalculateSpending(int& row);

  double MultiplyByWeight(double& Spending);
};
