/// prompt start
// void download(url)
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Callback function to write received data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Function to download content from a URL
void download(const char* url) {
    CURL *curl;
    FILE *fp;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // Open a file for writing (you can customize the filename)
        fp = fopen("downloaded_file.txt", "wb");

        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Set the write callback function
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        // Set the file to write to
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Clean up
        fclose(fp);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    const char* url = "https://example.com/somefile.txt"; // Replace with your URL
    download(url);

    return 0;
}