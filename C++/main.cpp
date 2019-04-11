int main() {
  string URL = "https://api.iextrading.com/1.0/tops?symbols=SNAP,FB";

  StockDataProvider stockDataProvider;
  string stockSymbols[] = {"SNAP", "FB"};
  string newURL = stockDataProvider.createUrl(stockSymbols, 2);
  string responseData = stockDataProvider.getJSON(URL);
  stockDataProvider.parseJson(responseData);
  cout << "Response: " << responseData << endl;

  return 0;
}