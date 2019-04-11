#include <iostream>
#include <string>

using namespace std;

class StockData {
private:
  string symbol;
  double marketPercent;
  int bidSize;
  double bidPrice;
  int askSize;
  double askPrice;
  int volume;
  double lastSalePrice;
  int lastSaleSize;
  long lastSaleTime;
  long lastUpdated;
  string sector;
  string securityType;

public:
  StockData(string symbol, double marketPercent, int bidSize, double bidPrice, int askSize, double askPrice,
            int volume, double lastSalePrice, int lastSaleSize, long lastSaleTime, long lastUpdated, string sector, string securityType) :
                symbol(symbol),
                marketPercent(marketPercent),
                bidSize(bidSize),
                bidPrice(bidPrice),
                askSize(askSize),
                askPrice(askPrice),
                volume(volume),
                lastSalePrice(lastSalePrice),
                lastSaleSize(lastSaleSize),
                lastSaleTime(lastSaleTime),
                lastUpdated(lastUpdated),
                sector(sector),
                securityType(securityType) {}

  //Read-only getters
  string getSymbol() const { return symbol; }
  double getMarketPercent() const { return marketPercent; }
  int getBidSize() const { return bidSize; }
  double getBidPrice() const { return bidPrice; }
  int getAskSize() const { return askSize; }
  double getAskPrice() const{ return askPrice; }
  int getVolume() const { return volume; }
  double getLastSalePrice() const { return lastSalePrice; }
  int getLastSaleSize() const { return lastSaleSize; }
  long getLastSaleTime() const { return lastSaleTime; }
  long getLastUpdated() const { return lastUpdated; }
  string getSector() const { return sector; }
  string getSecurityType() const { return securityType; }
};