/*
Question:
1. It should read and process 3 csv files. File names and its header content is given below:
  a. Table01.csv : Country, City, Street, HouseNumber, Num_Resident_Age_0, Num_Resident_Age_1,Num_Resident_Age_2, Num_Resident_Age_3
  b. Table02.csv : Age_Range, Spending
  c. Table03.csv : City, L_Weight, W_Weight

2. Calculate a total spending of a certain scope:
  E.g. The total spending of the residents on India Mumbai is: India Mumbai 34 and India Mumbai 54
  On Windows Platform result should be:
    India Mumbai 34 = (1 * 100 + 1 * 200 + 2 * 300) * 2
    India Mumbai 54 = (2 * 400) * 2
  On Linux Platform result should be:
    India Mumbai 34 = (1 * 100 + 1 * 200 + 2 * 300) * 1.8
    India Mumbai 54 = (2 * 400) * 1.8
   
  The scope can be defined as <a list of cities, a list of streets, a list of house numbers>,
  E.g. <Mumbai,,> : the spending of all residents in Mumbai
    <Mumbai, Street01, > : the spending of all residents in Mumbai Street01
    <Mumbai, Street01, 34,54> : the spending of all residents in Mumbai Street01 34 and 54
*/

#include"main.h"

bool Spend::ParseTable03(){
  std::ifstream f03("Table03.csv");
  if (!f03) {
    std::cout << "Table03.csv not present\n";
    return false;
  }

  std::string strLine, strCity;
  double dLWeight = 0.0, dRWeight = 0.0;

  std::getline(f03, strLine);   //skip header

  while (f03.eof() != 1) {    //Read and store in Hash Table
    std::getline(f03, strLine);
    tokenizer tok{strLine, sep};
    uint8_t count=1;
    for(it = tok.begin(); it != tok.end(); ++it){
      if (count == 1) //City
        strCity = *it;
      else if (count == 2)  //L_Weight
        dLWeight = boost::lexical_cast<double>(*it);
      else if (count == 3){ //R_Weight
        dRWeight = boost::lexical_cast<double>(*it);
        umTable03[strCity] = std::make_pair(dLWeight,dRWeight);
        strCity.clear();
      }
      ++count;
    }
  }
//    for (auto [i,j]:umTable03)
//      std::cout<<i<<","<<j.first<<","<<j.second<<"\n";
  f03.close();
  return true;
}

bool Spend::ParseTable02(){
  std::ifstream f02("Table02.csv");
  if (!f02) {
    std::cout << "Table02.csv not present\n";
    return false;
  }

  String strLine, strAgeRange;
  int iSpending;
  std::getline(f02, strLine);   //skip header
  while (f02.eof() != 1){
    std::getline(f02, strLine);
    tokenizer tok{strLine, sep};
    uint8_t count=1;
    for(it = tok.begin(); it != tok.end(); ++it){
      if (count == 2) {   //Storing Spending
        iSpending = boost::lexical_cast<int>(*it);
        vecTable02.push_back(iSpending);
      }
      ++count;
    }
  }
//  for (auto i:vecTable02)
//    std::cout<<i<<","<<"\n";
  return true;
}

bool Spend::ParseTable01(){
  std::ifstream f01("Table01.csv");
  if (!f01) {
    std::cout << "Table01.csv not present\n";
    return false;
  }
  String strLine;
  std::getline(f01, strLine);   //skip header
  std::vector<boost::any> vec1d;
  while(f01.eof() != 1){
    std::getline(f01, strLine);
    if (strLine.empty())      //skip empty lines
      continue;
    tokenizer tok{strLine, sep};
    it = tok.begin();
    boost::advance(it, 1);
    for(; it != tok.end(); ++it){
      vec1d.push_back(*it);   //All tokens pushed as String
    }
    m_vecTable01.push_back(vec1d);
    vec1d.clear();
  }
}

std::vector<std::string> Spend::ReadUserInput(){
  String strInput;
  std::vector<String> vecOut;
  std::getline(std::cin, strInput);
  if(strInput.empty()){
    std::cout << "Expected input format: " << std::endl
              <<  " no_of_streets no_of_houses city-name"
                  " street1 .. streetn"
                  " houseNo-1 .. HouseNo-n"
              << std::endl << "Examples:" << std::endl;
    std::cout << "0 0 Mumbai" << std::endl;
    std::cout << "1 0 Mumbai street01" << std::endl;
    std::cout << "1 1 Mumbai street01 34" << std::endl;
    std::cout << "1 2 Mumbai street01 34 35" << std::endl;
    std::cout << "0 0 Delhi" << std::endl;
    return vecOut;
  }

  //Tokenize the input
  boost::char_separator<char> sep1{" "};
  tokenizer tok{strInput, sep1};
  for(auto i:tok)
    vecOut.push_back(i);

  return vecOut;
}

double Spend::FindSpending(std::vector<String>& vecInput){
  //Find Number of Streets and Houses
  int iStreets = 0, iHouses = 0;
  int i=3;
  double iSpending=0;
  std::istringstream(vecInput[0]) >> iStreets;  //No of Streets
  std::istringstream(vecInput[1]) >> iHouses;   //No of Houses
  m_strCity = vecInput[2];              //Always City

  //Store Streets
  std::vector<String> vecStreets;
  if (iStreets){
    while (iStreets > 0){
      vecStreets.push_back(vecInput[i++]);
      --iStreets;
    }
  }

  //Store Houses
  std::vector<String> vecHouses;
  if (iHouses){
    while (iHouses > 0){
      vecHouses.push_back(vecInput[i++]);
      --iHouses;
    }
  }

  for (auto i=0; i<m_vecTable01.size(); ++i){
    if (!boost::any_cast<String>(m_vecTable01[i][0]).compare(m_strCity)){

      if (vecStreets.size() > 0){
        //if Street is provided.
        for (int j=0; j<vecStreets.size();++j){
            if(!boost::any_cast<String>(m_vecTable01[i][1]).compare(vecStreets[j])){  

              if (vecHouses.size() == 0){
                iSpending += CalculateSpending(i);
              }else{
                //if Houses are provided.
                for (int k=0; k<vecHouses.size();++k){
                  if(!boost::any_cast<String>(m_vecTable01[i][2]).compare(vecHouses[k])){
                    iSpending += CalculateSpending(i);
                  }
                }
              }

          }//if
        }//for
      } else if (vecStreets.size()==0 && vecHouses.size()==0) {
        //neither Street nor HouseNo Provided
        iSpending += CalculateSpending(i);
      }
    }
  }
  return iSpending;
}

double Spend::CalculateSpending(int& row){
  double iSpending = 0;

  //Create VecResidents
  std::vector<int> vecResidents;
  //Push Num_Res_Age0, Num_Res_Age1, Num_Res_Age2, Num_Res_Age3
  int j=3;
  while(j<7){
    int iNumRes;
    String strRes = boost::any_cast<String>(m_vecTable01[row][j]);
    std::istringstream(strRes) >> iNumRes;
    vecResidents.push_back(iNumRes);
    ++j;
  }

  //Multiply by Spending from Table02
  int k=0;
  for(auto i:vecResidents){
    iSpending += i*vecTable02[k++];     
  }

  return MultiplyByWeight(iSpending);
}

double Spend::MultiplyByWeight(double& Spending){
  auto it = umTable03.find(m_strCity);
  if (it != umTable03.end())
#if defined(WIND32)
      return Spending*it->second.second;
#else
      return Spending*it->second.first;
#endif
  return 0;
}

int main() {
  Spend oSpend;

  std::vector<std::string> vecInput = oSpend.ReadUserInput();
  if(vecInput.empty())
    return 0;

  oSpend.ParseTable03();
  oSpend.ParseTable02();
  oSpend.ParseTable01();

  double iSpending = oSpend.FindSpending(vecInput);

  std::cout << "Spending:" << iSpending;

}    
