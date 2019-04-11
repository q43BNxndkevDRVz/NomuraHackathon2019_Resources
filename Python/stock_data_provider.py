import requests, json

def get_stock_data(stock_symbols):
    iex_uri = 'https://api.iextrading.com/1.0/tops?symbols=' + ",".join(stock_symbols)
    print("Retrieving from {}".format(iex_uri))
    response = requests.get(iex_uri)
    return response.json()


if __name__ == '__main__':
    symbols = ['AAPL', 'FB', 'SNAP']
    content = get_stock_data(symbols)

    # get_stock_data returns an array of dicts, where each dict contains data for a given stock. Format is displayed
    # by the following print statement
    print(json.dumps(content, indent=1) + "\n")

    # Data can be extracted in the following way:
    for stock_data in content:
        print(stock_data['symbol'] + ": " + str(stock_data['askPrice']))
