
struct curl_slist* list = NULL;
std::string retrieveStockData(std::string ticker) /*Ticker would be a stock ticket (i.e. AMZN, AAPL, LMT)*/
{  
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    curl = curl_easy_init();
    if (curl) {    
        curl_easy_setopt(curl, CURLOPT_URL, ticker.c_str());
        curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
        list = curl_slist_append(list, "x-api-key: API_KEY_HERE"); //keep the space between apikey and the colon!!
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_perform(curl);
    }
    return readBuffer;
}
