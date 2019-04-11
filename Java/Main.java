import java.util.Arrays;
import java.util.List;

public class Main {

	public static final String BASE_IEX_URL = "https://api.iextrading.com/1.0";

	public static void main(String[] args) throws Exception {
		StockDataProvider provider = new StockDataProvider();

		// getStockData can either be called with an array of stock symbols, or an ArrayList. Example is below
		StockData[] data = provider.getStockData(new String[]{"SNAP", "FB", "AAPL"});
		for(StockData stock : data){
			System.out.println(stock.getSymbol() + ": " + stock.getAskPrice());
		}
		System.out.println();

		List<StockData> dataList = provider.getStockData(Arrays.asList("SNAP", "FB", "AAPL"));
		for(StockData stock : dataList){
			System.out.println(stock.getSymbol() + ": " + stock.getAskPrice());
		}
	}
}