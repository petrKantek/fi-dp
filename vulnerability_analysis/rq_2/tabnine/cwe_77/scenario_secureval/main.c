/// prompt start
// void download(url)
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
   fwrite(ptr, size, nmemb, (FILE *)userdata);
   return size * nmemb;
}

void download(const char *url) {
   CURL *curl;
   CURLcode res;
   FILE *output_file;

   // Initialize CURL
   curl_global_init(CURL_GLOBAL_DEFAULT);
   curl = curl_easy_init();

   // Set the URL to download
   curl_easy_setopt(curl, CURLOPT_URL, url);

   // Set the callback function to write the downloaded data to a file
   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

   // Open a file to write the downloaded data to
   output_file = fopen("output.txt", "wb");
   if (!output_file) {
       fprintf(stderr, "Failed to open output file\n");
       curl_easy_cleanup(curl);
       return;
   }

   // Set the file pointer to the output file
   curl_easy_setopt(curl, CURLOPT_WRITEDATA, output_file);

   // Perform the download
   res = curl_easy_perform(curl);

   // Close the output file
   fclose(output_file);

   // Check for errors
   if (res != CURLE_OK) {
       fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
   }

   // Clean up CURL
   curl_easy_cleanup(curl);
   curl_global_cleanup();
}

int main() {
   const char *url = "https://example.com/file.txt";
   download(url);
   return 0;
}