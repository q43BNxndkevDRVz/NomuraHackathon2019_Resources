#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <curl/curl.h>
#include <json/json.h>
#include <vector>
#include "StockData.cpp"
using namespace std;

class StockDataProvider {
private:
  CURL *curl;
  CURLcode res;
  Json::Value jsonData;
  Json::Reader jsonReader;
  const string BASE_URL="https://api.iextrading.com/1.0/tops?symbols=";

public:
  static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
  {
      ((std::string*)userp)->append((char*)contents, size * nmemb);
      return size * nmemb;
  }

  string getJSON(string url) {
      string readBuffer;
      curl = curl_easy_init();

      if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        return readBuffer;
      }

      return 0;
  }



  vector<StockData> getStockData(string stockSymbols[]) {
    const int size = sizeof(stockSymbols)/sizeof(stockSymbols[0]);
    string url = createUrl(stockSymbols, size);
    string jsonString = getJSON(url);

    /*
    * TODO: Implement the jsonParsing using jsoncpp to create the objects
    */

  }



/* Use the jsonData to parse through JSON reponse and create StockData objects */
  void parseJson(string jsonString) {
    if (jsonReader.parse(jsonString, jsonData))
    {
      cout << "Successfully parsed JSON data" << endl;
      cout << "\nJSON data received:" << endl;
      cout << jsonData.toStyledString() << endl;
      //Need to parse data here!
    }
    else
    {
      cout << "Could not parse HTTP data as JSON" << endl;
      cout << "HTTP data was:\n" << jsonString << endl;
    }
  }



  string createUrl(string stockSymbols[], int size) {
    string url = BASE_URL;

    for(int i = 0; i < size; i++) {
        url += stockSymbols[i];
        if(i < size-1) {
          url += ',';
        }
    }
    return url;
  }

};