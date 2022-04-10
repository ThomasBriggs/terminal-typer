#include "curl/curl.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

struct memory {
    size_t size;
    char* data;
};

size_t writeCB(void* data, size_t byte_size, size_t data_size, void* container)
{
    size_t realsize = byte_size * data_size;
    memory* mem = (memory*)container;

    char* ptr = (char*)std::realloc(mem->data, mem->size + realsize + 1);
    if (ptr == NULL)
        return 0;

    mem->data = ptr;
    std::memcpy(&(mem->data[mem->size]), data, realsize);
    mem->size += realsize;
    mem->data[mem->size] = 0;

    return realsize;
}

int main(int argc, char const* argv[])
{
    memory data;
    data.size = 0;
    data.data = (char*)std::malloc(0);
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://opentdb.com/api.php?amount=1");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCB);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&data);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if (res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);

    std::cout << data.data << '\n';
    // free(data.data);
    return 0;
}
