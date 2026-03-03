#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int check_sha256 (char *input, char *expected_hash){
	unsigned char hash[32];
	SHA256((unsigned char*)input, strlen(input),hash);

	char hex_hash[32*2+1];
        for(int i = 0; i < 32; i++){
		sprintf(&hex_hash[i*2], "%02x", hash[i]);
	}
	hex_hash[32*2] = 0;

	if(strcmp(hex_hash,expected_hash) == 0){
		return 1;
	}else {
		return 0;
	}
}

int checking (char str[], char *expected_hash,int *match){
   if(check_sha256(str,expected_hash) == 1){
		printf("Found password: SHA256(%s) = %s\n" , str, expected_hash);
	   *match = 1;
	   return 1;
   }
     int len = strlen(str);
		for(int i = 0; i < len; i++){
           if( str[i] >= 'a' && str[i] <= 'z'){
			 str[i] = str[i] -32;
				if(check_sha256(str,expected_hash) == 1){
					 printf("Found password: SHA256(%s) = %s\n" , str, expected_hash);
					 *match = 1;
					 return 1;
			   }
						 str[i] = str[i] + 32;
				
			   }
		else if ( str[i] >= 'A' && str[i] <= 'Z'){
					str[i] = str[i] + 32;
		 if(check_sha256(str,expected_hash) == 1 ){
			 printf("Found password: SHA256(%s) = %s\n", str, expected_hash);
			   *match = 1;
				return 1;
			 }
			 str[i] = str[i] - 32;
		   }
		}
		return 0;
}
           
int main(int argc, char** argv){
       char buffer[1001];
	   int match = 0;
       while(fgets(buffer,1001,stdin)!=NULL){
        size_t len = strlen(buffer);
          if (len > 0 && buffer[len-1] == '\n') {
           buffer[len-1] = 0;
	 }
      checking(buffer,argv[1],&match);
	  if(match == 1){
		return 0;
	  }
}
 if (match == 0) {
	printf("Did not find a matching password\n");
 }
	 return 0;
 }
